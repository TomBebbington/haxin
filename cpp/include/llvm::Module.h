#ifndef INCLUDED_llvm::Module
#define INCLUDED_llvm::Module

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <gen/Extern.h>
HX_DECLARE_CLASS1(gen,Extern)
HX_DECLARE_CLASS0(llvm::LLVMContext)
HX_DECLARE_CLASS0(llvm::Module)


class HXCPP_CLASS_ATTRIBUTES  llvm::Module_obj : public ::gen::Extern_obj{
	public:
		typedef ::gen::Extern_obj super;
		typedef llvm::Module_obj OBJ_;
		llvm::Module_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< llvm::Module_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~llvm::Module_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("llvm::Module"); }

		static ::llvm::Module parseBitcodeFile( ::String s,::llvm::LLVMContext c);
		static Dynamic parseBitcodeFile_dyn();

};


#endif /* INCLUDED_llvm::Module */ 
