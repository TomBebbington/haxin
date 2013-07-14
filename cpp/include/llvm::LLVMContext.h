#ifndef INCLUDED_llvm::LLVMContext
#define INCLUDED_llvm::LLVMContext

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <gen/Extern.h>
HX_DECLARE_CLASS1(gen,Extern)
HX_DECLARE_CLASS0(llvm::LLVMContext)


class HXCPP_CLASS_ATTRIBUTES  llvm::LLVMContext_obj : public ::gen::Extern_obj{
	public:
		typedef ::gen::Extern_obj super;
		typedef llvm::LLVMContext_obj OBJ_;
		llvm::LLVMContext_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< llvm::LLVMContext_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~llvm::LLVMContext_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("llvm::LLVMContext"); }

};


#endif /* INCLUDED_llvm::LLVMContext */ 
