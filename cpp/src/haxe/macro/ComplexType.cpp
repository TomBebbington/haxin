#include <hxcpp.h>

#ifndef INCLUDED_haxe_macro_ComplexType
#include <haxe/macro/ComplexType.h>
#endif
namespace haxe{
namespace macro{

::haxe::macro::ComplexType  ComplexType_obj::TAnonymous(Dynamic fields)
	{ return hx::CreateEnum< ComplexType_obj >(HX_CSTRING("TAnonymous"),2,hx::DynamicArray(0,1).Add(fields)); }

::haxe::macro::ComplexType  ComplexType_obj::TExtend(Dynamic p,Dynamic fields)
	{ return hx::CreateEnum< ComplexType_obj >(HX_CSTRING("TExtend"),4,hx::DynamicArray(0,2).Add(p).Add(fields)); }

::haxe::macro::ComplexType  ComplexType_obj::TFunction(Array< ::Dynamic > args,::haxe::macro::ComplexType ret)
	{ return hx::CreateEnum< ComplexType_obj >(HX_CSTRING("TFunction"),1,hx::DynamicArray(0,2).Add(args).Add(ret)); }

::haxe::macro::ComplexType  ComplexType_obj::TOptional(::haxe::macro::ComplexType t)
	{ return hx::CreateEnum< ComplexType_obj >(HX_CSTRING("TOptional"),5,hx::DynamicArray(0,1).Add(t)); }

::haxe::macro::ComplexType  ComplexType_obj::TParent(::haxe::macro::ComplexType t)
	{ return hx::CreateEnum< ComplexType_obj >(HX_CSTRING("TParent"),3,hx::DynamicArray(0,1).Add(t)); }

::haxe::macro::ComplexType  ComplexType_obj::TPath(Dynamic p)
	{ return hx::CreateEnum< ComplexType_obj >(HX_CSTRING("TPath"),0,hx::DynamicArray(0,1).Add(p)); }

HX_DEFINE_CREATE_ENUM(ComplexType_obj)

int ComplexType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("TAnonymous")) return 2;
	if (inName==HX_CSTRING("TExtend")) return 4;
	if (inName==HX_CSTRING("TFunction")) return 1;
	if (inName==HX_CSTRING("TOptional")) return 5;
	if (inName==HX_CSTRING("TParent")) return 3;
	if (inName==HX_CSTRING("TPath")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ComplexType_obj,TAnonymous,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ComplexType_obj,TExtend,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ComplexType_obj,TFunction,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ComplexType_obj,TOptional,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ComplexType_obj,TParent,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ComplexType_obj,TPath,return)

int ComplexType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("TAnonymous")) return 1;
	if (inName==HX_CSTRING("TExtend")) return 2;
	if (inName==HX_CSTRING("TFunction")) return 2;
	if (inName==HX_CSTRING("TOptional")) return 1;
	if (inName==HX_CSTRING("TParent")) return 1;
	if (inName==HX_CSTRING("TPath")) return 1;
	return super::__FindArgCount(inName);
}

Dynamic ComplexType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("TAnonymous")) return TAnonymous_dyn();
	if (inName==HX_CSTRING("TExtend")) return TExtend_dyn();
	if (inName==HX_CSTRING("TFunction")) return TFunction_dyn();
	if (inName==HX_CSTRING("TOptional")) return TOptional_dyn();
	if (inName==HX_CSTRING("TParent")) return TParent_dyn();
	if (inName==HX_CSTRING("TPath")) return TPath_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("TPath"),
	HX_CSTRING("TFunction"),
	HX_CSTRING("TAnonymous"),
	HX_CSTRING("TParent"),
	HX_CSTRING("TExtend"),
	HX_CSTRING("TOptional"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ComplexType_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class ComplexType_obj::__mClass;

Dynamic __Create_ComplexType_obj() { return new ComplexType_obj; }

void ComplexType_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.macro.ComplexType"), hx::TCanCast< ComplexType_obj >,sStaticFields,sMemberFields,
	&__Create_ComplexType_obj, &__Create,
	&super::__SGetClass(), &CreateComplexType_obj, sMarkStatics, sVisitStatic);
}

void ComplexType_obj::__boot()
{
}


} // end namespace haxe
} // end namespace macro
