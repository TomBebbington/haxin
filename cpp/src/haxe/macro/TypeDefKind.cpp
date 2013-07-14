#include <hxcpp.h>

#ifndef INCLUDED_haxe_macro_ComplexType
#include <haxe/macro/ComplexType.h>
#endif
#ifndef INCLUDED_haxe_macro_TypeDefKind
#include <haxe/macro/TypeDefKind.h>
#endif
namespace haxe{
namespace macro{

::haxe::macro::TypeDefKind  TypeDefKind_obj::TDAbstract(::haxe::macro::ComplexType tthis,Array< ::Dynamic > from,Array< ::Dynamic > to)
	{ return hx::CreateEnum< TypeDefKind_obj >(HX_CSTRING("TDAbstract"),4,hx::DynamicArray(0,3).Add(tthis).Add(from).Add(to)); }

::haxe::macro::TypeDefKind  TypeDefKind_obj::TDAlias(::haxe::macro::ComplexType t)
	{ return hx::CreateEnum< TypeDefKind_obj >(HX_CSTRING("TDAlias"),3,hx::DynamicArray(0,1).Add(t)); }

::haxe::macro::TypeDefKind  TypeDefKind_obj::TDClass(Dynamic superClass,Dynamic interfaces,Dynamic isInterface)
	{ return hx::CreateEnum< TypeDefKind_obj >(HX_CSTRING("TDClass"),2,hx::DynamicArray(0,3).Add(superClass).Add(interfaces).Add(isInterface)); }

::haxe::macro::TypeDefKind TypeDefKind_obj::TDEnum;

::haxe::macro::TypeDefKind TypeDefKind_obj::TDStructure;

HX_DEFINE_CREATE_ENUM(TypeDefKind_obj)

int TypeDefKind_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("TDAbstract")) return 4;
	if (inName==HX_CSTRING("TDAlias")) return 3;
	if (inName==HX_CSTRING("TDClass")) return 2;
	if (inName==HX_CSTRING("TDEnum")) return 0;
	if (inName==HX_CSTRING("TDStructure")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC3(TypeDefKind_obj,TDAbstract,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(TypeDefKind_obj,TDAlias,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(TypeDefKind_obj,TDClass,return)

int TypeDefKind_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("TDAbstract")) return 3;
	if (inName==HX_CSTRING("TDAlias")) return 1;
	if (inName==HX_CSTRING("TDClass")) return 3;
	if (inName==HX_CSTRING("TDEnum")) return 0;
	if (inName==HX_CSTRING("TDStructure")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic TypeDefKind_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("TDAbstract")) return TDAbstract_dyn();
	if (inName==HX_CSTRING("TDAlias")) return TDAlias_dyn();
	if (inName==HX_CSTRING("TDClass")) return TDClass_dyn();
	if (inName==HX_CSTRING("TDEnum")) return TDEnum;
	if (inName==HX_CSTRING("TDStructure")) return TDStructure;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("TDEnum"),
	HX_CSTRING("TDStructure"),
	HX_CSTRING("TDClass"),
	HX_CSTRING("TDAlias"),
	HX_CSTRING("TDAbstract"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TypeDefKind_obj::TDEnum,"TDEnum");
	HX_MARK_MEMBER_NAME(TypeDefKind_obj::TDStructure,"TDStructure");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TypeDefKind_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(TypeDefKind_obj::TDEnum,"TDEnum");
	HX_VISIT_MEMBER_NAME(TypeDefKind_obj::TDStructure,"TDStructure");
};

static ::String sMemberFields[] = { ::String(null()) };
Class TypeDefKind_obj::__mClass;

Dynamic __Create_TypeDefKind_obj() { return new TypeDefKind_obj; }

void TypeDefKind_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.macro.TypeDefKind"), hx::TCanCast< TypeDefKind_obj >,sStaticFields,sMemberFields,
	&__Create_TypeDefKind_obj, &__Create,
	&super::__SGetClass(), &CreateTypeDefKind_obj, sMarkStatics, sVisitStatic);
}

void TypeDefKind_obj::__boot()
{
hx::Static(TDEnum) = hx::CreateEnum< TypeDefKind_obj >(HX_CSTRING("TDEnum"),0);
hx::Static(TDStructure) = hx::CreateEnum< TypeDefKind_obj >(HX_CSTRING("TDStructure"),1);
}


} // end namespace haxe
} // end namespace macro
