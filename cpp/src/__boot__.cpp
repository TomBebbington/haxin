#include <hxcpp.h>

#include <sys/io/FileOutput.h>
#include <sys/io/FileInput.h>
#include <sys/io/File.h>
#include <llvm::Module.h>
#include <llvm::LLVMContext.h>
#include <haxin/Distro.h>
#include <haxin/OS.h>
#include <haxin/Haxin.h>
#include <sys/_FileSystem/FileKind.h>
#include <sys/FileSystem.h>
#include <haxin/HaxeGen.h>
#include <haxin/Args.h>
#include <haxe/macro/Printer.h>
#include <haxe/macro/TypeDefKind.h>
#include <haxe/macro/FieldType.h>
#include <haxe/macro/Access.h>
#include <haxe/macro/TypeParam.h>
#include <haxe/macro/ComplexType.h>
#include <haxe/macro/ExprDef.h>
#include <haxe/macro/Unop.h>
#include <haxe/macro/Binop.h>
#include <haxe/macro/Constant.h>
#include <haxe/io/Output.h>
#include <haxe/io/Input.h>
#include <haxe/io/Error.h>
#include <haxe/io/Eof.h>
#include <haxe/io/Bytes.h>
#include <haxe/ds/StringMap.h>
#include <haxe/Log.h>
#include <gen/Extern.h>
#include <Sys.h>
#include <StringTools.h>
#include <StringBuf.h>
#include <Std.h>
#include <IMap.h>
#include <Lambda.h>
#include <EReg.h>
#include <cpp/Lib.h>

void __boot_all()
{
hx::RegisterResources( hx::GetResources() );
::sys::io::FileOutput_obj::__register();
::sys::io::FileInput_obj::__register();
::sys::io::File_obj::__register();
::llvm::Module_obj::__register();
::llvm::LLVMContext_obj::__register();
::haxin::Distro_obj::__register();
::haxin::OS_obj::__register();
::haxin::Haxin_obj::__register();
::sys::_FileSystem::FileKind_obj::__register();
::sys::FileSystem_obj::__register();
::haxin::HaxeGen_obj::__register();
::haxin::Args_obj::__register();
::haxe::macro::Printer_obj::__register();
::haxe::macro::TypeDefKind_obj::__register();
::haxe::macro::FieldType_obj::__register();
::haxe::macro::Access_obj::__register();
::haxe::macro::TypeParam_obj::__register();
::haxe::macro::ComplexType_obj::__register();
::haxe::macro::ExprDef_obj::__register();
::haxe::macro::Unop_obj::__register();
::haxe::macro::Binop_obj::__register();
::haxe::macro::Constant_obj::__register();
::haxe::io::Output_obj::__register();
::haxe::io::Input_obj::__register();
::haxe::io::Error_obj::__register();
::haxe::io::Eof_obj::__register();
::haxe::io::Bytes_obj::__register();
::haxe::ds::StringMap_obj::__register();
::haxe::Log_obj::__register();
::gen::Extern_obj::__register();
::Sys_obj::__register();
::StringTools_obj::__register();
::StringBuf_obj::__register();
::Std_obj::__register();
::IMap_obj::__register();
::Lambda_obj::__register();
::EReg_obj::__register();
::cpp::Lib_obj::__register();
::cpp::Lib_obj::__boot();
::EReg_obj::__boot();
::haxe::Log_obj::__boot();
::Lambda_obj::__boot();
::IMap_obj::__boot();
::Std_obj::__boot();
::StringBuf_obj::__boot();
::StringTools_obj::__boot();
::Sys_obj::__boot();
::gen::Extern_obj::__boot();
::haxe::ds::StringMap_obj::__boot();
::haxe::io::Bytes_obj::__boot();
::haxe::io::Eof_obj::__boot();
::haxe::io::Error_obj::__boot();
::haxe::io::Input_obj::__boot();
::haxe::io::Output_obj::__boot();
::haxe::macro::Constant_obj::__boot();
::haxe::macro::Binop_obj::__boot();
::haxe::macro::Unop_obj::__boot();
::haxe::macro::ExprDef_obj::__boot();
::haxe::macro::ComplexType_obj::__boot();
::haxe::macro::TypeParam_obj::__boot();
::haxe::macro::Access_obj::__boot();
::haxe::macro::FieldType_obj::__boot();
::haxe::macro::TypeDefKind_obj::__boot();
::haxe::macro::Printer_obj::__boot();
::haxin::Args_obj::__boot();
::haxin::HaxeGen_obj::__boot();
::sys::FileSystem_obj::__boot();
::sys::_FileSystem::FileKind_obj::__boot();
::haxin::Haxin_obj::__boot();
::haxin::OS_obj::__boot();
::haxin::Distro_obj::__boot();
::llvm::LLVMContext_obj::__boot();
::llvm::Module_obj::__boot();
::sys::io::File_obj::__boot();
::sys::io::FileInput_obj::__boot();
::sys::io::FileOutput_obj::__boot();
}

