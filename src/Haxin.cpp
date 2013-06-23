#include "llvm/IR/Attributes.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/GlobalAlias.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Metadata.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/User.h"
#include "llvm/ADT/ArrayRef.h"
#include "llvm/ADT/ilist_node.h"
#include "llvm/ADT/OwningPtr.h"
#include "llvm/ADT/Twine.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/Bitcode/BitCodes.h"
#include "llvm/Support/Casting.h"
#include "llvm/Support/DataTypes.h"
#include "llvm/Support/DebugLoc.h"
#include "llvm/Support/InstIterator.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/system_error.h"
#include "llvm/Config/config.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "haxin.h"
#include "HaxeWriter.cpp"
#include "HaxePath.cpp"
#include "Utils.cpp"
using namespace llvm;
using namespace std;

int main(int argc, char** argv) {
	const string sourceFile = argv[argc-2];
	const string destFile = argv[argc-1];
	LLVMContext* ctx = new LLVMContext();
	OwningPtr<MemoryBuffer> ptr;
	if(MemoryBuffer::getFile(sourceFile, ptr)) {
		cerr << "File '" << sourceFile << "' does not exist\n";
		return 1;
	}
	Module* m = ParseBitcodeFile(ptr.get(), *ctx);
	string errorInfo = "ERROR";
	llvm::raw_ostream *out = new llvm::raw_fd_ostream(destFile.c_str(), errorInfo, 0);
	HaxeWriter *wtr = new HaxeWriter(out, m, toHaxeName(destFile.substr(0, destFile.length()-3)), getDir(destFile));
	wtr -> writeAll();
	return 0;
}
