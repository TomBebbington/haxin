#include <hxcpp.h>

#ifndef INCLUDED_haxe_macro_ComplexType
#include <haxe/macro/ComplexType.h>
#endif
#ifndef INCLUDED_haxe_macro_FieldType
#include <haxe/macro/FieldType.h>
#endif
namespace haxe{
namespace macro{

::haxe::macro::FieldType  FieldType_obj::FFun(Dynamic f)
	{ return hx::CreateEnum< FieldType_obj >(HX_CSTRING("FFun"),1,hx::DynamicArray(0,1).Add(f)); }

::haxe::macro::FieldType  FieldType_obj::FProp(::String get,::String set,::haxe::macro::ComplexType t,Dynamic e)
	{ return hx::CreateEnum< FieldType_obj >(HX_CSTRING("FProp"),2,hx::DynamicArray(0,4).Add(get).Add(set).Add(t).Add(e)); }

::haxe::macro::FieldType  FieldType_obj::FVar(::haxe::macro::ComplexType t,Dynamic e)
	{ return hx::CreateEnum< FieldType_obj >(HX_CSTRING("FVar"),0,hx::DynamicArray(0,2).Add(t).Add(e)); }

HX_DEFINE_CREATE_ENUM(FieldType_obj)

int FieldType_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("FFun")) return 1;
	if (inName==HX_CSTRING("FProp")) return 2;
	if (inName==HX_CSTRING("FVar")) return 0;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(FieldType_obj,FFun,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC4(FieldType_obj,FProp,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(FieldType_obj,FVar,return)

int FieldType_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("FFun")) return 1;
	if (inName==HX_CSTRING("FProp")) return 4;
	if (inName==HX_CSTRING("FVar")) return 2;
	return super::__FindArgCount(inName);
}

Dynamic FieldType_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("FFun")) return FFun_dyn();
	if (inName==HX_CSTRING("FProp")) return FProp_dyn();
	if (inName==HX_CSTRING("FVar")) return FVar_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("FVar"),
	HX_CSTRING("FFun"),
	HX_CSTRING("FProp"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FieldType_obj::__mClass,"__mClass");
};

static ::String sMemberFields[] = { ::String(null()) };
Class FieldType_obj::__mClass;

Dynamic __Create_FieldType_obj() { return new FieldType_obj; }

void FieldType_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.macro.FieldType"), hx::TCanCast< FieldType_obj >,sStaticFields,sMemberFields,
	&__Create_FieldType_obj, &__Create,
	&super::__SGetClass(), &CreateFieldType_obj, sMarkStatics, sVisitStatic);
}

void FieldType_obj::__boot()
{
}


} // end namespace haxe
} // end namespace macro
