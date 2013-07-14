#include <hxcpp.h>

#ifndef INCLUDED_haxe_macro_Access
#include <haxe/macro/Access.h>
#endif
namespace haxe{
namespace macro{

::haxe::macro::Access Access_obj::ADynamic;

::haxe::macro::Access Access_obj::AInline;

::haxe::macro::Access Access_obj::AMacro;

::haxe::macro::Access Access_obj::AOverride;

::haxe::macro::Access Access_obj::APrivate;

::haxe::macro::Access Access_obj::APublic;

::haxe::macro::Access Access_obj::AStatic;

HX_DEFINE_CREATE_ENUM(Access_obj)

int Access_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("ADynamic")) return 4;
	if (inName==HX_CSTRING("AInline")) return 5;
	if (inName==HX_CSTRING("AMacro")) return 6;
	if (inName==HX_CSTRING("AOverride")) return 3;
	if (inName==HX_CSTRING("APrivate")) return 1;
	if (inName==HX_CSTRING("APublic")) return 0;
	if (inName==HX_CSTRING("AStatic")) return 2;
	return super::__FindIndex(inName);
}

int Access_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("ADynamic")) return 0;
	if (inName==HX_CSTRING("AInline")) return 0;
	if (inName==HX_CSTRING("AMacro")) return 0;
	if (inName==HX_CSTRING("AOverride")) return 0;
	if (inName==HX_CSTRING("APrivate")) return 0;
	if (inName==HX_CSTRING("APublic")) return 0;
	if (inName==HX_CSTRING("AStatic")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Access_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("ADynamic")) return ADynamic;
	if (inName==HX_CSTRING("AInline")) return AInline;
	if (inName==HX_CSTRING("AMacro")) return AMacro;
	if (inName==HX_CSTRING("AOverride")) return AOverride;
	if (inName==HX_CSTRING("APrivate")) return APrivate;
	if (inName==HX_CSTRING("APublic")) return APublic;
	if (inName==HX_CSTRING("AStatic")) return AStatic;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("APublic"),
	HX_CSTRING("APrivate"),
	HX_CSTRING("AStatic"),
	HX_CSTRING("AOverride"),
	HX_CSTRING("ADynamic"),
	HX_CSTRING("AInline"),
	HX_CSTRING("AMacro"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Access_obj::ADynamic,"ADynamic");
	HX_MARK_MEMBER_NAME(Access_obj::AInline,"AInline");
	HX_MARK_MEMBER_NAME(Access_obj::AMacro,"AMacro");
	HX_MARK_MEMBER_NAME(Access_obj::AOverride,"AOverride");
	HX_MARK_MEMBER_NAME(Access_obj::APrivate,"APrivate");
	HX_MARK_MEMBER_NAME(Access_obj::APublic,"APublic");
	HX_MARK_MEMBER_NAME(Access_obj::AStatic,"AStatic");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Access_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Access_obj::ADynamic,"ADynamic");
	HX_VISIT_MEMBER_NAME(Access_obj::AInline,"AInline");
	HX_VISIT_MEMBER_NAME(Access_obj::AMacro,"AMacro");
	HX_VISIT_MEMBER_NAME(Access_obj::AOverride,"AOverride");
	HX_VISIT_MEMBER_NAME(Access_obj::APrivate,"APrivate");
	HX_VISIT_MEMBER_NAME(Access_obj::APublic,"APublic");
	HX_VISIT_MEMBER_NAME(Access_obj::AStatic,"AStatic");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Access_obj::__mClass;

Dynamic __Create_Access_obj() { return new Access_obj; }

void Access_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.macro.Access"), hx::TCanCast< Access_obj >,sStaticFields,sMemberFields,
	&__Create_Access_obj, &__Create,
	&super::__SGetClass(), &CreateAccess_obj, sMarkStatics, sVisitStatic);
}

void Access_obj::__boot()
{
hx::Static(ADynamic) = hx::CreateEnum< Access_obj >(HX_CSTRING("ADynamic"),4);
hx::Static(AInline) = hx::CreateEnum< Access_obj >(HX_CSTRING("AInline"),5);
hx::Static(AMacro) = hx::CreateEnum< Access_obj >(HX_CSTRING("AMacro"),6);
hx::Static(AOverride) = hx::CreateEnum< Access_obj >(HX_CSTRING("AOverride"),3);
hx::Static(APrivate) = hx::CreateEnum< Access_obj >(HX_CSTRING("APrivate"),1);
hx::Static(APublic) = hx::CreateEnum< Access_obj >(HX_CSTRING("APublic"),0);
hx::Static(AStatic) = hx::CreateEnum< Access_obj >(HX_CSTRING("AStatic"),2);
}


} // end namespace haxe
} // end namespace macro
