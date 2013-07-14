#include <hxcpp.h>

#ifndef INCLUDED_gen_Extern
#include <gen/Extern.h>
#endif
#ifndef INCLUDED_llvm::LLVMContext
#include <llvm::LLVMContext.h>
#endif

Void llvm::LLVMContext_obj::__construct()
{
HX_STACK_PUSH("llvm::LLVMContext::new","gen/External.hx",31);
{
}
;
	return null();
}

llvm::LLVMContext_obj::~llvm::LLVMContext_obj() { }

Dynamic llvm::LLVMContext_obj::__CreateEmpty() { return  new llvm::LLVMContext_obj; }
hx::ObjectPtr< llvm::LLVMContext_obj > llvm::LLVMContext_obj::__new()
{  hx::ObjectPtr< llvm::LLVMContext_obj > result = new llvm::LLVMContext_obj();
	result->__construct();
	return result;}

Dynamic llvm::LLVMContext_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< llvm::LLVMContext_obj > result = new llvm::LLVMContext_obj();
	result->__construct();
	return result;}


llvm::LLVMContext_obj::llvm::LLVMContext_obj()
{
}

void llvm::LLVMContext_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(llvm::LLVMContext);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void llvm::LLVMContext_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic llvm::LLVMContext_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic llvm::LLVMContext_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void llvm::LLVMContext_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(llvm::LLVMContext_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(llvm::LLVMContext_obj::__mClass,"__mClass");
};

Class llvm::LLVMContext_obj::__mClass;

void llvm::LLVMContext_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("llvm::LLVMContext"), hx::TCanCast< llvm::LLVMContext_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void llvm::LLVMContext_obj::__boot()
{
}

