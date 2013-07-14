#include <hxcpp.h>

#ifndef INCLUDED_gen_Extern
#include <gen/Extern.h>
#endif
#ifndef INCLUDED_llvm::LLVMContext
#include <llvm::LLVMContext.h>
#endif
#ifndef INCLUDED_llvm::Module
#include <llvm::Module.h>
#endif

Void llvm::Module_obj::__construct()
{
	return null();
}

llvm::Module_obj::~llvm::Module_obj() { }

Dynamic llvm::Module_obj::__CreateEmpty() { return  new llvm::Module_obj; }
hx::ObjectPtr< llvm::Module_obj > llvm::Module_obj::__new()
{  hx::ObjectPtr< llvm::Module_obj > result = new llvm::Module_obj();
	result->__construct();
	return result;}

Dynamic llvm::Module_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< llvm::Module_obj > result = new llvm::Module_obj();
	result->__construct();
	return result;}

::llvm::Module llvm::Module_obj::parseBitcodeFile( ::String s,::llvm::LLVMContext c){
	HX_STACK_PUSH("llvm::Module::parseBitcodeFile","gen/External.hx",36);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(36)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(llvm::Module_obj,parseBitcodeFile,return )


llvm::Module_obj::llvm::Module_obj()
{
}

void llvm::Module_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(llvm::Module);
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void llvm::Module_obj::__Visit(HX_VISIT_PARAMS)
{
	super::__Visit(HX_VISIT_ARG);
}

Dynamic llvm::Module_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 16:
		if (HX_FIELD_EQ(inName,"parseBitcodeFile") ) { return parseBitcodeFile_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic llvm::Module_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void llvm::Module_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("parseBitcodeFile"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(llvm::Module_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(llvm::Module_obj::__mClass,"__mClass");
};

Class llvm::Module_obj::__mClass;

void llvm::Module_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("llvm::Module"), hx::TCanCast< llvm::Module_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void llvm::Module_obj::__boot()
{
}

