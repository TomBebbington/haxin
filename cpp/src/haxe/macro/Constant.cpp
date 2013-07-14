#include <hxcpp.h>

#ifndef INCLUDED_haxe_macro_Constant
#include <haxe/macro/Constant.h>
#endif
namespace haxe{
namespace macro{

::haxe::macro::Constant  Constant_obj::CFloat(::String f)
	{ return hx::CreateEnum< Constant_obj >(HX_CSTRING("CFloat"),1,hx::DynamicArray(0,1).Add(f)); }

::haxe::macro::Constant  Constant_obj::CIdent(::String s)
	{ return hx::CreateEnum< Constant_obj >(HX_CSTRING("CIdent"),3,hx::DynamicArray(0,1).Add(s)); }

::haxe::macro::Constant  Constant_obj::CInt(::String v)
	{ return hx::CreateEnum< Constant_obj >(HX_CSTRING("CInt"),0,hx::DynamicArray(0,1).Add(v)); }

::haxe::macro::Constant  Constant_obj::CRegexp(::String r,::String opt)
	{ return hx::CreateEnum< Constant_obj >(HX_CSTRING("CRegexp"),4,hx::DynamicArray(0,2).Add(r).Add(opt)); }

::haxe::macro::Constant  Constant_obj::CString(::String s)
	{ return hx::CreateEnum< Constant_obj >(HX_CSTRING("CString"),2,hx::DynamicArray(0,1).Add(s)); }

HX_DEFINE_CREATE_ENUM(Constant_obj)

int Constant_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("CFloat")) return 1;
	if (inName==HX_CSTRING("CIdent")) return 3;
	if (inName==HX_CSTRING("CInt")) return 0;
	if (inName==HX_CSTRING("CRegexp")) return 4;
	if (inName==HX_CSTRING("CString")) return 2;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Constant_obj,CFloat,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Constant_obj,CIdent,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Constant_obj,CInt,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(Constant_obj,CRegexp,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Constant_obj,CString,return)

int Constant_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("CFloat")) return 1;
	if (inName==HX_CSTRING("CIdent")) return 1;
	if (inName==HX_CSTRING("CInt")) return 1;
	if (inName==HX_CSTRING("CRegexp")) return 2;
	if (inName==HX_CSTRING("CString")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic Constant_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("CFloat")) return CFloat_dyn();
	if (inName==HX_CSTRING("CIdent")) return CIdent_dyn();
	if (inName==HX_CSTRING("CInt")) return CInt_dyn();
	if (inName==HX_CSTRING("CRegexp")) return CRegexp_dyn();
	if (inName==HX_CSTRING("CString")) return CString_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("CInt"),
	HX_CSTRING("CFloat"),
	HX_CSTRING("CString"),
	HX_CSTRING("CIdent"),
	HX_CSTRING("CRegexp"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Constant_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Constant_obj::__mClass;

Dynamic __Create_Constant_obj() { return new Constant_obj; }

void Constant_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.macro.Constant"), hx::TCanCast< Constant_obj >,sStaticFields,sMemberFields,
	&__Create_Constant_obj, &__Create,
	&super::__SGetClass(), &CreateConstant_obj, sMarkStatics, sVisitStatic);
}

void Constant_obj::__boot()
{
}


} // end namespace haxe
} // end namespace macro
