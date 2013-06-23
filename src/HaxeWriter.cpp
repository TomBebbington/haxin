HaxeWriter::HaxeWriter(raw_ostream *o, Module* m, string n, string d) {
	dir = d;
	output = o;
	mod = m;
	name = n;
	tabs = 0;
	allocWidth = 0;
	i_cache = new vector<const Instruction*>();
	t_cache = new vector<const Type*>();
	structs = new vector<const StructType*>();
}
void HaxeWriter::newline(const int tabp) {
	tabs += tabp;
	*output << "\n\r";
	for(uint i = 0 ; i < tabs; i++)
		*output << "\t";
//	*output << output -> getBufferStart();
	output -> flush();
}
void HaxeWriter::writeCast(const Value *v, const Type *t) {
	if(v -> getType() -> isIntegerTy() && v -> getType() -> getIntegerBitWidth() <= 32 && t -> isIntegerTy(64)) {
		*output << "haxe.Int64.ofInt(";
		writeValue(v);
		*output << ")";
	} else if(v -> getType() == t)
		writeValue(v);
	else if(v -> getType() -> isPointerTy() && t == v -> getType() -> getPointerElementType())
		writeValue(v);
	else if(t -> isPointerTy() && t -> getPointerElementType() == v -> getType()) {
		writeValue(v);
		*output << ".get()";
	} else if(v -> getType() -> isPointerTy() && t -> isIntegerTy()) {
		writeValue(v);
		*output << ".addr()";
	} else {
		*output << "cast(";
		writeValue(v);
		*output << ", ";
		writeType(t);
		*output << ")";
	}
}
void HaxeWriter::writeValue(const Value *v, bool allow_name) {
	if(allow_name && v -> hasName())
		*output << haxeFilter(v -> getName());
	else if(const Argument* a = dyn_cast<Argument>(v)) {
		if(a -> hasName())
			*output << haxeFilter(a -> getName());
		else
			*output << "_" << genID(a -> getArgNo());
	} else if(const Constant* c = dyn_cast<Constant>(v)) 
		writeConstant(c);
	else if(const BasicBlock* b = dyn_cast<BasicBlock>(v)) {
		*output << "{";
		tabs++;
		writeInsts(b, true);
		newline(-1);
		*output << "}";
	} else if(const Instruction* i = dyn_cast<Instruction>(v)) {
		writeInst(i, true);
	} else if(const MDString* s = dyn_cast<MDString>(v)) {
		*output << encodeString(s -> getString());
	} else if(const MDNode* n = dyn_cast<MDNode>(v)) {
		int len = n -> getNumOperands();
		for(int i=0;i < len;i++) {
			const Value* ov = n -> getOperand(i);
			if(ov == 0)
				break;
			writeValue(ov);
			if(i < len-1)
				*output << ", ";
		}
	} else if(const Function* f = dyn_cast<Function>(v)) {
		if(f -> hasName())
			*output << haxeFilter(f -> getName());
		else {
			*output << "function(";
			for(Function::const_arg_iterator it = f -> arg_begin(); it != f -> arg_end(); it++) {
				if(it -> hasName())
					*output << haxeFilter(it -> getName());
				else
					*output << "_" << genID(it -> getArgNo());
				*output << ":";
				writeType(it -> getType());
			}
			*output << "):";
			writeType(f -> getReturnType());
			*output << "{";
			*output << "}";
		}
	} else {
		*output << "Unknown value \"" << *v << "\"";
	}
}
void HaxeWriter::writeInst(const Instruction* inst, bool is_value){
	for(vector<const Instruction*>::iterator it = i_cache -> begin();it != i_cache->end();it++) {
		if(inst == *it)
			return;
	}
	i_cache -> push_back(*&inst);
	bool should_end = true;
	if(const StructType* t = dyn_cast<StructType>(inst->getType()))
		addStruct(t);
	if(inst -> hasName()) {
		if(!is_value)
			*output << "var ";
		*output << haxeFilter(inst -> getName());
		if(!is_value) { 
			*output << ":";
			writeType(inst -> getType());
		}
		*output << " = ";
	}
	if(isa<UnreachableInst>(inst)) {

	} else if(const ReturnInst* r = dyn_cast<ReturnInst>(inst)) {
		*output << "return";
		const Value* val = r -> getReturnValue();
		if(val != 0) {
			*output << " ";
			writeValue(val);
		}
	} else if(const CastInst *c = dyn_cast<CastInst>(inst)) {
		writeCast(c -> getOperand(0), c -> getType());
	} else if(const LoadInst *l = dyn_cast<LoadInst>(inst)) {
		writeValue(l -> getOperand(0));
	} else if(const AllocaInst *i = dyn_cast<AllocaInst>(inst)) {
		if(is_value)
			*output << names[i];
		else if(inst -> hasName()) {
			*output << getDefaultValue(inst -> getType()) << ";";
			newline();
			*output << "var ";
			string id = genID(allocWidth++);
			names[i] = id;
			*output << id << ":";
			writeType(i -> getAllocatedType());
			*output << " = " << getDefaultValue(i -> getAllocatedType()) << ";";
			newline();
			*output << inst -> getName() << " = " << id;
		} else {
			*output << "var ";
			string id = genID(allocWidth++);
			names[i] = id;
			*output << id << ":";
			writeType(i -> getAllocatedType());
			*output << " = " << getDefaultValue(i -> getAllocatedType());
		}
	} else if(const AtomicRMWInst *a = dyn_cast<AtomicRMWInst>(inst)) {
		const Value* ptr = a -> getPointerOperand();
		const Value* val = a -> getValOperand();
		switch(a -> getOperation()) {
			case AtomicRMWInst::Xchg:
				writeValue(ptr);
				*output << " = ";
				writeValue(val);
				break;
			case AtomicRMWInst::Add:
				writeValue(ptr);
				*output << " += ";
				writeValue(val);
				break;
			case AtomicRMWInst::Sub:
				writeValue(ptr);
				*output << " -= ";
				writeValue(val);
				break;
			case AtomicRMWInst::And:
				writeValue(ptr);
				*output << " &= ";
				writeValue(val);
				break;
			case AtomicRMWInst::Nand:
				*output << "~";
				writeValue(ptr);
				*output << " &= ";
				writeValue(val);
				break;
			case AtomicRMWInst::Or:
				writeValue(ptr);
				*output << " |= ";
				writeValue(val);
				break;
			case AtomicRMWInst::Xor:
				writeValue(ptr);
				*output << " ^= ";
				writeValue(val);
				break;
			case AtomicRMWInst::Max:
				*output << "(";
				writeValue(val);
				*output << " > ";
				writeValue(ptr);
				*output << " ? ";
				writeValue(val);
				*output << " : ";
				writeValue(ptr);
				*output << ")";
				break;
			case AtomicRMWInst::Min:
				writeValue(ptr);
				*output << " = (";
				writeValue(val);
				*output << " < ";
				writeValue(ptr);
				*output << " ? ";
				writeValue(val);
				*output << " : ";
				writeValue(ptr);
				*output << ")";
				break;
			default: break;
		}
	} else if(const ExtractValueInst *e = dyn_cast<ExtractValueInst>(inst)) {
		writeValue(e -> getAggregateOperand());
		Type * lastType = e -> getAggregateOperand() -> getType();
		for(ExtractValueInst::idx_iterator iit = e -> idx_begin(); iit != e -> idx_end();iit++) {
			uint val = *iit;
			output -> flush();
			//lastType -> dump();
			//cerr << "\n";
			if(lastType -> isVectorTy() || lastType -> isArrayTy()) {
				*output << "[" << val << "]";
				lastType = cast<VectorType>(lastType) -> getElementType();
			} else if(lastType -> isStructTy()) {
				//*output << *lastType;
				*output << "." << genID(val);
			} else if(lastType -> isIntegerTy(64) && e -> getType() -> isIntegerTy(32))
				*output << ".toInt()";
			else if(const ArrayType *a = dyn_cast<const ArrayType>(lastType)) {
				Type* t = a -> getElementType();
				if(t -> isIntegerTy(8))
					*output << ".charAt(";
			}
		}
	} else if(const LandingPadInst *lp = dyn_cast<LandingPadInst>(inst)) {
		*output << "try ";
		writeValue(lp -> getOperand(0));
		uint clen = lp -> getNumClauses();
		for(uint i=0;i<clen;i++) {
			*output << "\nCLAUSE\n";
			writeValue(lp -> getClause(i));
		}
	} else if(const InvokeInst *i = dyn_cast<InvokeInst>(inst)) {
		writeValue(i -> getCalledValue());
		*output << "()";
	} else if(const CallInst *c = dyn_cast<CallInst>(inst)) {
		const Value* calledFunc = c -> getCalledFunction();
		const Value* calledVal = c -> getCalledValue();
		const Value* called = calledFunc == NULL ? calledVal : calledFunc;
		writeValue(called);
		int args = c -> getNumArgOperands();
		*output << "(";
		for(int ind = 0;ind < args;ind++) {
			writeValue(c -> getArgOperand(ind));
			if(ind < args-1)
				*output << ", ";
		}
		*output << ")";
	} else if(const StoreInst *s = dyn_cast<StoreInst>(inst)) {
		writeValue(s -> getOperand(1));
		*output << " = ";
		writeValue(s -> getOperand(0));
	} else if(const CmpInst *c = dyn_cast<CmpInst>(inst)) {
		switch(c -> getPredicate()) {
			case CmpInst::FCMP_FALSE: *output << "false"; break;
			case CmpInst::FCMP_TRUE: *output << "true"; break;
			case CmpInst::FCMP_OEQ:
			case CmpInst::FCMP_UEQ:
			case CmpInst::ICMP_EQ:
				writeValue(c -> getOperand(0));
				*output << " == ";
				writeValue(c -> getOperand(1));
				break;
			case CmpInst::FCMP_OGT:
			case CmpInst::FCMP_UGT:
			case CmpInst::ICMP_UGT:
			case CmpInst::ICMP_SGT:
				writeValue(c -> getOperand(0));
				*output << " > ";
				writeValue(c -> getOperand(1));
				break;
			case CmpInst::FCMP_OGE:
			case CmpInst::FCMP_UGE:
			case CmpInst::ICMP_UGE:
			case CmpInst::ICMP_SGE:
				writeValue(c -> getOperand(0));
				*output << " >= ";
				writeValue(c -> getOperand(1));
				break;
			case CmpInst::FCMP_OLT:
			case CmpInst::FCMP_ULT:
			case CmpInst::ICMP_ULT:
			case CmpInst::ICMP_SLT:
				writeValue(c -> getOperand(0));
				*output << " < ";
				writeValue(c -> getOperand(1));
				break;
			case CmpInst::FCMP_OLE:
			case CmpInst::FCMP_ULE:
			case CmpInst::ICMP_ULE:
			case CmpInst::ICMP_SLE:
				writeValue(c -> getOperand(0));
				*output << " <= ";
				writeValue(c -> getOperand(1));
				break;
			case CmpInst::FCMP_ONE:
			case CmpInst::FCMP_UNE:
			case CmpInst::ICMP_NE:
				writeValue(c -> getOperand(0));
				*output << " != ";
				writeValue(c -> getOperand(1));
				break;
			case CmpInst::FCMP_ORD:
				*output << "!Math.isNaN(";
				writeValue(c -> getOperand(0));
				*output << ") && !Math.isNaN(";
				writeValue(c -> getOperand(1));
				*output << ")";
				break;
			case CmpInst::FCMP_UNO:
				*output << "Math.isNaN(";
				writeValue(c -> getOperand(0));
				*output << ") || Math.isNaN(";
				writeValue(c -> getOperand(1));
				*output << ")";
				break;
			default:
				*output << "false";
		}
	} else if(const BinaryOperator* bin = dyn_cast<BinaryOperator>(inst)) {
		const Value* a = bin -> getOperand(0);
		const Value* b = bin -> getOperand(1);
		switch(bin -> getOpcode()) {
			case BinaryOperator::Add:
			case BinaryOperator::FAdd:
				writeValue(a);
				*output << " + ";
				writeValue(b);
				break;
			case BinaryOperator::Sub:
			case BinaryOperator::FSub:
				writeValue(a);
				*output << " - ";
				writeValue(b);
				break;
			case BinaryOperator::Mul:
			case BinaryOperator::FMul:
				writeValue(a);
				*output << " * ";
				writeValue(b);
				break;
			case BinaryOperator::UDiv:
			case BinaryOperator::SDiv:
			case BinaryOperator::FDiv:
				writeValue(a);
				*output << " / ";
				writeValue(b);
				break;
			case BinaryOperator::URem:
			case BinaryOperator::SRem:
			case BinaryOperator::FRem:
				writeValue(a);
				*output << " % ";
				writeValue(b);
				break;
			case BinaryOperator::Shl:
				writeValue(a);
				*output << " << ";
				writeValue(b);
				break;
			case BinaryOperator::LShr:
			case BinaryOperator::AShr:
				writeValue(a);
				*output << " >> ";
				writeValue(b);
				break;
			case BinaryOperator::And:
				writeValue(a);
				*output << " & ";
				writeValue(b);
				break;
			case BinaryOperator::Or:
				writeValue(a);
				*output << " | ";
				writeValue(b);
				break;
			case BinaryOperator::Xor:
				writeValue(a);
				*output << " ^ ";
				writeValue(b);
				break;
			default: break;
		}
	} else if(const BranchInst* br = dyn_cast<BranchInst>(inst)) {
		switch(br -> getNumOperands()) {
			case 1:
				break;
			case 2:
				*output << "if(";
				writeValue(br -> getOperand(0));
				*output << ")";
				writeValue(br -> getOperand(1));
				break;
			case 3:
				*output << "if(";
				writeValue(br -> getOperand(0));
				*output << ")";
				break;
			default: break;
		}
	} else if(const SwitchInst* s = dyn_cast<SwitchInst>(inst)) {
		*output << "switch(";
		writeValue(s -> getCondition());
		*output << ") {";
		for(SwitchInst::ConstCaseIt it = s -> case_begin(); it != s -> case_end();it++) {
			newline(1);
			*output << "case ";
			writeValue(it.getCaseValue());
			*output << ":";
			tabs++;
			writeInsts(it.getCaseSuccessor());
			newline(-1);
		}
		newline(1);
		*output << "default:";
		writeInsts(s -> getDefaultDest(), true);
		newline(-2);
		*output << "}";
		newline();
	} else if(const ResumeInst* r = dyn_cast<ResumeInst>(inst)) {
		*output << "throw ";
		writeValue(r -> getValue());
	} else if(const PHINode* n = dyn_cast<PHINode>(inst)) {
		uint len = n -> getNumIncomingValues();
		writeValue(n -> getIncomingValue(0));
		*output << ";";
		newline();
		*output << "while(true) {";
		newline(1);
		*output << haxeFilter(n -> getName()) << " = ";
		writeValue(n -> getIncomingValue(1));
		*output << ";";
		writeInsts(n -> getIncomingBlock(1));
		*output << ";";
		newline();
		newline(-1);
		*output << "}";
	} else if(const GetElementPtrInst* p = dyn_cast<GetElementPtrInst>(inst)) {
		*output << "new Pointer(";
		writeValue(p -> getPointerOperand());
		*output << ")";
	} else if(const InsertValueInst* i = dyn_cast<InsertValueInst>(i)) {
		writeValue(i -> getAggregateOperand());
		*output << ".push(";
		writeValue(i -> getInsertedValueOperand());
		*output << ")";
	} else
		*output << "?" << *inst << "?";
	if(!is_value && should_end)
		*output << ";";
	i_cache -> pop_back();
}
void HaxeWriter::writeInsts(const BasicBlock* b, bool is_value) {
	for(BasicBlock::const_iterator it = b -> begin(); it != b -> end(); it++) {
		newline();
		writeInst(it, it == b -> end());
	}
}
void HaxeWriter::writeFunctions() {
	newline();
	for(Module::const_iterator it = mod -> begin();it != mod -> end();it++) {
		bool isExtern = it -> empty() && !it -> getReturnType() -> isVoidTy();
		if(isExtern)
			continue;
		if(it -> getName() == "main")
			mainFunc = &*it;
		*output << "static function " << haxeFilter(it -> getName()) << "(";
		for(Function::const_arg_iterator ait = it -> arg_begin(); ait != it -> arg_end(); ait++) {
			if(ait != it -> arg_begin())
				*output << ", ";
			if(ait -> hasName())
				*output << haxeFilter(ait -> getName());
			else
				*output << "_" << genID(ait -> getArgNo());
			*output << ":";
			writeType(ait -> getType());
		}
		*output << "): ";
		writeType(it -> getReturnType());
		*output << " {";
		newline(1);
		for(Function::const_iterator bit = it -> begin(); bit != it -> end(); bit++) {
			writeInsts(bit);
			allocWidth = 0;
			names.clear();
		}
		newline(-1);
		*output << "}";
		newline();
	}
}
void HaxeWriter::writeType(const Type *t) {
	for(vector<const Type*>::iterator it = t_cache -> begin();it != t_cache->end();it++) {
		if(t == *it) {
			if(t -> isStructTy())
				*output << toHaxeName(t -> getStructName());
			else
				*output << "Dynamic";
			return;
		}
	}
	t_cache -> push_back(t);
	if(t -> isVoidTy())
		*output << "Void";
	else if(const IntegerType *i = dyn_cast<const IntegerType>(t)) {
		uint w = i -> getBitWidth();
		if(w <= 32)
			*output << "Int";
		else
			*output << "haxe.Int64";
	} else if(t -> isFloatingPointTy())
		*output << "Float";
	else if(const FunctionType *f = dyn_cast<const FunctionType>(t)) {
		int nparams = f -> getNumParams();
		if(nparams <= 0)
			*output << "Void -> ";
		else
			for(int i=0;i<nparams;i++) {
				writeType(f -> getParamType(i));
				*output << " -> ";
			}
		writeType(f -> getReturnType());
	} else if(const ArrayType *a = dyn_cast<const ArrayType>(t)) {
		Type* t = a -> getElementType();
		if(t -> isIntegerTy(8))
			*output << "String";
		else {
			*output << "haxe.ds.Vector<";
			writeType(t);
			*output << ">";
		}
	} else if(t -> isVectorTy())
		*output << "haxe.io.Bytes";
	else if(const StructType* s = dyn_cast<const StructType>(t)) {
		addStruct(s);
		uint numEles = s -> getNumElements();
		if(s -> hasName()) {
			*output << toHaxeName(s -> getName());
		} else {
			*output << "{";
			for(int i=0; i < numEles;i++) {
				*output << genID(i) << ": ";
				writeType(s -> getElementType(i));
				if(i < numEles - 1)
					*output << ", ";
			}
			*output << "}";
		}
	} else if(t -> isPointerTy()) {
		*output << "Pointer<";
		writeType(t -> getPointerElementType());
		*output << ">";
	} else
		*output << "Dynamic /* Unknown type " << t << "*/";
	t_cache -> pop_back();
}
void HaxeWriter::writeConstant(const Constant *it) {
	output -> flush();
	if(it -> canTrap())
		*output << "try ";
	if (const ConstantInt *CI = dyn_cast<const ConstantInt>(it))
		*output << CI -> getValue();
	else if (const ConstantFP *CF = dyn_cast<const ConstantFP>(it))
		*output << CF -> getValueAPF().convertToDouble();
	else if(isa<const ConstantAggregateZero>(it))
		*output << "0";
	else if(const BlockAddress *BA = dyn_cast<const BlockAddress>(it))
		*output << "\"" << BA -> getFunction() -> getName() << "\"";
	else if(isa<const UndefValue>(it))
		*output << "null";
	else if(const ConstantExpr *ex = dyn_cast<const ConstantExpr>(it)) {
		ConstantExpr *exp = (ConstantExpr*) ex;
		writeInst(exp -> getAsInstruction(), true);
	} else if(isa<const ConstantPointerNull>(it))
		*output << "0";
	else if(const BlockAddress *bl = dyn_cast<const BlockAddress>(it)) {
		*output << "{";
		newline(1);
		writeInsts(bl -> getBasicBlock(), true);
		newline(-1);
		*output << "}";
	} else if(const ConstantDataVector *cds = cast<ConstantDataVector>(it)) {
		Type* et = cds -> getElementType();
		if(cds -> getType() -> isPointerTy()) {
			*output << "Pointer<";
			writeType(cds -> getType() -> getPointerElementType());
			*output << ">";
		} else if(cds -> isString())
			*output << encodeString(cds -> getAsString().str());
		else if(cds -> isCString() || et -> isIntegerTy(8))
			*output << encodeString(cds -> getAsCString().str());
		else if(et -> isIntegerTy()) {
			*output << "[";
			for(uint i=0;i<cds -> getNumElements();i++) {
				if(i != 0)
					*output << ", ";
				*output << cds -> getElementAsInteger(i);
			}
			*output << "]";
		} else if(et -> isFloatTy()) {
			*output << "[";
			for(uint i=0;i<cds -> getNumElements();i++) {
				if(i != 0)
					*output << ", ";
				*output << cds -> getElementAsFloat(i);
			}
			*output << "]";
		} else if(et -> isDoubleTy()) {
			*output << "[";
			for(uint i=0;i<cds -> getNumElements();i++) {
				if(i != 0)
					*output << ", ";
				*output << cds -> getElementAsDouble(i);
			}
			*output << "]";
		}
	} else {
		*output << "Unknown";
	}
	if(it -> canTrap())
		*output << " catch(e:Dynamic) " << getDefaultValue(it -> getType());
}
void HaxeWriter::writeGlobals() {
	for(Module::const_global_iterator it = mod -> global_begin();it != mod -> global_end();it++) {
		newline();
		*output << "static ";
		if(it -> isConstant())
			*output << "inline ";
		*output << "var " << haxeFilter(it -> getName().str()) << ":";
		writeType(it -> getType());
		*output << " = ";
		writeConstant(&*it);
		*output << ";";
	}
}
void HaxeWriter::addStruct(const StructType* s) {
	if(!s -> hasName())
		return;
	for(vector<const StructType*>::iterator it = structs -> begin(); it != structs -> end(); it++)
		if(*it == s)
			return;
	structs -> push_back(s);
}
void HaxeWriter::writeStruct(const StructType* s) {
	HaxePath name(s -> getName());
	raw_ostream *old = output;
	string err = "ERROR";
	output = new raw_fd_ostream((dir + name.toPath()).c_str(), err, 0);
	if(s -> getNumElements() == 1) {
		*output << "typedef " << name << " = ";
		writeType(s -> getElementType(0));
		*output << ";";
	} else {
		*output << "class " << name.name << " {";
		newline(1);
		for(uint i=0; i < s -> getNumElements();i++) {
			*output << "public var " << genID(i) + ":";
			writeType(s -> getElementType(i));
			*output << ";";
			newline();
		}
		*output << "public function new() {";
		newline(1);
		for(uint i=0; i < s -> getNumElements();i++) {
			*output << "this." << genID(i) + " = " + getDefaultValue(s -> getElementType(i)) << ";";
			newline();
		}
		newline(-1);
		*output << "}";
		newline(-1);
		*output << "}";
	}
	newline();
	output = old;
}
void HaxeWriter::writeStructs() {
	for(vector<const StructType*>::iterator it = structs -> begin(); it != structs -> end(); it++)
		writeStruct(*it);
}
void HaxeWriter::writeMain() {
	*output << "public static function main() {";
	newline(1);
	*output << haxeFilter(mainFunc -> getName()) << "(";
	FunctionType* t = mainFunc -> getFunctionType();
	if(t -> getNumParams() == 2 && t -> getParamType(0) -> isIntegerTy() && t -> getParamType(1) -> isPointerTy()) {
		*output << "Sys.args().length, Sys.args()";
	}
	*output << ");";
	newline(-1);
	*output << "}";
	newline();
}
void HaxeWriter::writeAll() {
	*output << "class " << name << " {";
	newline(1);
	*output << "static var heap:Map<Int, Dynamic> = [0 => null];";
	writeGlobals();
	writeFunctions();
	if(mainFunc != NULL)
		writeMain();
	newline(-1);
	*output << "}";
	newline();
	writeStructs();
}