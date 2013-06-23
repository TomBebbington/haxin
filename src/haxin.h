using namespace llvm;
using namespace std;
#ifndef HAXIN_H
#define HAXIN_H
const string encodeString(string);
string genID(uint);
string getDir(string);
string toUpper(string);
string haxeFilter(string, bool=false);
string toHaxeName(string);
string replaceAll(string, const string, const string);
string getDefaultValue(const Type*);
int getConstantInt(const ConstantInt*);
class HaxePath {
	public:
		vector<string>* packs;
		string name;
		HaxePath(const string path);
		friend llvm::raw_ostream & operator << (llvm::raw_ostream & out, HaxePath &);
		string toHaxe();
		string toPath();
};
class HaxeWriter {
	string dir;
	raw_ostream* output;
	vector<const Instruction*>* i_cache;
	vector<const Type*>* t_cache;
	vector<const StructType*>* structs;
	const Function* mainFunc;
	Module* mod;
	string name;
	unsigned int tabs;
	unsigned int allocWidth;
	std::map <const Instruction*, string> names;
	public:
		HaxeWriter(raw_ostream*, Module*, string, string);
		void newline(const int tabp=0);
		void addStruct(const StructType*);
		void writeAll();
		void writeStruct(const StructType*);
		void writeStructs();
		void writeFunctions();
		void writeVars(vector<const AllocaInst*>* vars);
		void writeGlobals();
		void writeValue(const Value* v, bool=true);
		void writeConstant(const Constant*);
		void writeType(const Type*);
		void writeCast(const Value* v, const Type* t);
		void writeInsts(const BasicBlock*, bool=false);
		void writeInst(const Instruction*, bool=false);
		void writeMain();
		void generateInst();
};
#endif
