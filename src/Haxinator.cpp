#include "llvm/BasicBlock.h"
#include "llvm/Constants.h"
#include "llvm/DerivedTypes.h"
#include "llvm/Function.h"
#include "llvm/GlobalVariable.h"
#include "llvm/GlobalAlias.h"
#include "llvm/IRBuilder.h"
#include "llvm/InstrTypes.h"
#include "llvm/Instruction.h"
#include "llvm/Instructions.h"
#include "llvm/LLVMContext.h"
#include "llvm/Metadata.h"
#include "llvm/Module.h"
#include "llvm/Type.h"
#include "llvm/User.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/ilist_node.h"
#include "llvm/ADT/OwningPtr.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/Bitcode/BitCodes.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/DataTypes.h"
#include "llvm/Support/DebugLoc.h"
#include "llvm/Support/InstVisitor.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/system_error.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <algorithm>

using namespace llvm;
using namespace std;
bool endsWith (string const &fullString, string const &ending) {
	if (fullString.length() >= ending.length())
		return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
	else
		return false;
}
string toUpper(string s) {
	string ns = s;
	std::transform(ns.begin(), ns.end(), ns.begin(), ::toupper);
	return ns;
}

string haxeFilter(string n, bool camel = false) {
	const string notAllowed[] = {".", "/", "main"};
	const int num_notAllowed = 2;
	for(int i=0;i<num_notAllowed;i++) {
		const string c = notAllowed[i];
		int found = (int) n.find(c);
		int count = 0;
		while(found != -1 && count++ < 50) {
			if(camel) {
				n.replace(found, c.length()+1, toUpper(n.substr(found+1, 1)));
			} else
				n.replace(found, c.length(), "_");
			found = (int) n.find(c);
		}
	}
	return n;
}
string formatClassName(string n) {
	n = haxeFilter(n, true);
	n = toUpper(n.substr(0, 1)) + n.substr(1);
	return n;
}
class HaxeExpr {
	public:
		void writeTo(raw_ostream*);
};
class HaxeWhile : HaxeExpr {

};

class HaxeWriter {
	raw_ostream* output;
	Module* mod;
	int tabs;
	public:
		HaxeWriter(raw_ostream*, Module*);
		void newline();
		void writeAll();
		void writeFunctions();
		void writeGlobals();
		void writeValue(const Value* v);
		void writeConstant(const Constant*);
		void writeType(const Type*);
		void writeInsts(const BasicBlock*);
		void writeInst(const Instruction*);
		void generateInst();
};
HaxeWriter::HaxeWriter(raw_ostream *o, Module* m) {
	output = o;
	mod = m;
	tabs = 0;
}
void HaxeWriter::newline() {
	*output << "\n\r";
	for(int i=0;i<tabs;i++)
		*output << "\t";
}
void HaxeWriter::writeValue(const Value *v) {
	if(v -> hasName() && v -> getName().str().length() > 0)
		haxeFilter(v -> getName().str());
	else if(const Constant* c = dyn_cast<Constant>(v))
		writeConstant(c);
	else if(const BasicBlock* b = dyn_cast<BasicBlock>(v)) {
		*output << "{";
		tabs++;
		writeInsts(b);
		newline();
		tabs--;
		*output << "}";
	} else if(const Instruction* i = dyn_cast<Instruction>(v)) {
		writeInst(i);
	} else {
		*output << v;
	}
}
void HaxeWriter::writeInst(const Instruction* inst){
	if(const ReturnInst* r = dyn_cast<ReturnInst>(inst)) {
		*output << "return";
		const Value* val = r -> getReturnValue();
		if(val != 0) {
			*output << " ";
			writeValue(val);
		}
		*output << ";";
	} else if(const CastInst *c = dyn_cast<CastInst>(inst)) {
		*output << "cast (";
		writeValue(c -> getOperand(0));
		*output << ", ";
		writeType(c -> getDestTy());
		*output << ")";
	} else if(const LoadInst *l = dyn_cast<LoadInst>(inst)) {
		writeValue(l -> getOperand(0));
	} else if(const AllocaInst *i = dyn_cast<AllocaInst>(inst)) {
		*output << "var a:";
		writeType(i -> getType());
		*output << ";";
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
	} else if(const GetElementPtrInst *e = dyn_cast<GetElementPtrInst>(inst)) {
		writeValue(e -> getPointerOperand());
		*output << "[";
		for(GetElementPtrInst::const_op_iterator iit = e -> idx_begin(); iit != e -> idx_end();iit++) {
			writeValue(*iit);
			*output << ", ";
		}
		*output << "]";
	} else if(const InvokeInst *i = dyn_cast<InvokeInst>(inst)) {
		writeValue(i -> getCalledValue());
		*output << "()";
	} else if(const CallInst *c = dyn_cast<CallInst>(inst)) {
		writeValue(c -> getCalledValue());
		int args = c -> getNumArgOperands();
		*output << "(";
		for(int ind = 0;ind < args;ind++) {
			writeValue(c -> getArgOperand(ind));
			if(ind < args-1)
				*output << ", ";
		}
		*output << ")";
	} else if(const StoreInst *s = dyn_cast<StoreInst>(inst)) {
		*output << "STORE";
	} else if(inst -> isBinaryOp()) {
		*output << "BINARY";
	} else
		*output << *inst;
}
void HaxeWriter::writeInsts(const BasicBlock* b) {
	for(BasicBlock::const_iterator it = b -> begin(); it != b -> end(); it++) {
		newline();
		writeInst(it);
	}
}
void HaxeWriter::writeFunctions() {
	for(Module::const_iterator it = mod -> begin();it != mod -> end();it++) {
		*output << "static function " << it -> getName() << "(";
		for(Function::const_arg_iterator ait = it -> arg_begin(); ait != it -> arg_end(); ait++) {
			if(ait -> getName().str().length() > 0)
				*output << ait -> getName().str();
			else
				*output << "a" << ait -> getArgNo();
			*output << ":";
			writeType(ait -> getType());
		}
		*output << "): ";
		writeType(it -> getReturnType());
		*output << " {";
		for(Function::const_iterator bit = it -> begin(); bit != it -> end(); bit++) {
			tabs++;
			writeInsts(bit);
			tabs--;
		}
		newline();
		*output << "}";
		newline();
	}
}
void HaxeWriter::writeType(const Type *t) {
	if(t -> isVoidTy())
		*output << "Void";
	else if(t -> isHalfTy() || t -> isIntegerTy())
		*output << "Int";
	else if(t -> isFloatingPointTy())
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
		*output << "haxe.ds.Vector<";
		writeType(a -> getElementType());
		*output << ">";
	} else if(t -> isVectorTy())
		*output << "haxe.io.Bytes";
	else if(t -> isStructTy()) {
		const StructType* s = cast<StructType>(t);
		if(s -> hasName())
			*output << s -> getName();
		else {
			int numEles = s -> getNumElements();
			*output << "{";
			for(int i=0; i < numEles;i++) {
				*output << "a: ";
				writeType(s -> getElementType(i));
				if(i < numEles - 1)
					*output << ", ";
			}
			*output << "}";
		}
	} else if(const PointerType *p = dyn_cast<const PointerType>(t))
		writeType(p -> getElementType());
	else if(const CompositeType *c = dyn_cast<const CompositeType>(t)) {
		*output << "Composite??";
	} else {
		*output << "Dynamic /* Unknown type " << t << "*/";
	}
}
void HaxeWriter::writeConstant(const Constant *it) {
	if (const ConstantInt *CI = dyn_cast<const ConstantInt>(it))
		*output << CI -> getSExtValue();
	else if (const ConstantFP *CF = dyn_cast<const ConstantFP>(it))
		*output << CF -> getValueAPF().convertToDouble();
	else if(const ConstantAggregateZero *CAZ = dyn_cast<const ConstantAggregateZero>(it))
		*output << "0";
	else if(const BlockAddress *BA = dyn_cast<const BlockAddress>(it))
		*output << "\"" << BA -> getFunction() -> getName() << "\"";
	else if(const UndefValue *UV = dyn_cast<const UndefValue>(it))
		*output << "null";
	else if(const ConstantStruct *CS = dyn_cast<const ConstantStruct>(it))
		*output << "Struct";
	else if(const ConstantExpr *CE = dyn_cast <const ConstantExpr>(it)) {
		//writeInst(CE -> getAsInstruction());
		*output << "expr:";
		*output << CE -> getOpcodeName();
	} else if(isa<const ConstantPointerNull>(it))
		*output << "null";
	else if(const BlockAddress *bl = dyn_cast<const BlockAddress>(it)) {
		*output << "{";
		tabs++;
		newline();
		writeInsts(bl -> getBasicBlock());
		tabs--;
		newline();
		*output << "}";
	} else if(const ConstantDataSequential *cds = cast<ConstantDataSequential>(it)) {
		if(cds -> isString())
			*output << "\"" << cds -> getAsString().str() << "\"";
		else if(cds -> isCString())
			*output << "\"" << cds -> getAsCString().str() << "\"";
		else {
			*output << "[";
			Constant* c;
			for(unsigned i=0;(c=cds->getElementAsConstant(i))!=0;i++)
				*output << " ";
			/*writeType(cds -> getElementType());*/
			*output << "]";
		}
	} else {
		*output << "Unknown";
	}
}
void HaxeWriter::writeGlobals() {
	for(Module::const_global_iterator it = mod -> global_begin();it != mod -> global_end();it++) {
		*output << "static ";
		if(it -> isConstant())
			*output << "inline ";
		*output << "var " << haxeFilter(it -> getName().str()) << ":";
		writeType(it -> getType());
		*output << " = ";
		writeConstant(&*it);
		*output << ";";
		newline();
	}
}
void HaxeWriter::writeAll() {
	*output << "/*" << mod -> getTargetTriple() << "*/";
	newline();
	string name = formatClassName(mod -> getModuleIdentifier());
	*output << "class " << name << " {";
	tabs++;
	newline();
	writeGlobals();
	writeFunctions();
	tabs--;
	newline();
	*output << "}";
	newline();
	output -> flush();
}
int main(int argc, char* argv[]) {
	const string sourceFile = argv[argc-2];
	const string destFile = argv[argc-1];
	LLVMContext* ctx = new LLVMContext();
	OwningPtr<MemoryBuffer> ptr;
	if(MemoryBuffer::getFile(sourceFile, ptr)) {
		cerr << "File '" << sourceFile << "' does not exist\n";
		return 1;
	}
	Module* m = ParseBitcodeFile(ptr.get(), *ctx);
	/*if(!mkdir(destDir.c_str(), 0)) {
		cerr << "Directory '" << destDir << "' could not be created\n";
	}*/
	cout << "Generating into Haxe at " << destFile << "...\n";
	string errorInfo = "ERROR";
	llvm::raw_ostream *out = new llvm::raw_fd_ostream(destFile.c_str(), errorInfo, 0);
	HaxeWriter *wtr = new HaxeWriter(out, m);
	wtr -> writeAll();
	return 0;
}
