#include <hxcpp.h>

#ifndef INCLUDED_haxin_Distro
#include <haxin/Distro.h>
#endif
#ifndef INCLUDED_haxin_OS
#include <haxin/OS.h>
#endif
namespace haxin{

::haxin::OS OS_obj::BSD;

::haxin::OS  OS_obj::Linux(::haxin::Distro d)
	{ return hx::CreateEnum< OS_obj >(HX_CSTRING("Linux"),0,hx::DynamicArray(0,1).Add(d)); }

::haxin::OS OS_obj::Mac;

::haxin::OS OS_obj::Windows;

HX_DEFINE_CREATE_ENUM(OS_obj)

int OS_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("BSD")) return 3;
	if (inName==HX_CSTRING("Linux")) return 0;
	if (inName==HX_CSTRING("Mac")) return 2;
	if (inName==HX_CSTRING("Windows")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(OS_obj,Linux,return)

int OS_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("BSD")) return 0;
	if (inName==HX_CSTRING("Linux")) return 1;
	if (inName==HX_CSTRING("Mac")) return 0;
	if (inName==HX_CSTRING("Windows")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic OS_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("BSD")) return BSD;
	if (inName==HX_CSTRING("Linux")) return Linux_dyn();
	if (inName==HX_CSTRING("Mac")) return Mac;
	if (inName==HX_CSTRING("Windows")) return Windows;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Linux"),
	HX_CSTRING("Windows"),
	HX_CSTRING("Mac"),
	HX_CSTRING("BSD"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(OS_obj::BSD,"BSD");
	HX_MARK_MEMBER_NAME(OS_obj::Mac,"Mac");
	HX_MARK_MEMBER_NAME(OS_obj::Windows,"Windows");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(OS_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(OS_obj::BSD,"BSD");
	HX_VISIT_MEMBER_NAME(OS_obj::Mac,"Mac");
	HX_VISIT_MEMBER_NAME(OS_obj::Windows,"Windows");
};

static ::String sMemberFields[] = { ::String(null()) };
Class OS_obj::__mClass;

Dynamic __Create_OS_obj() { return new OS_obj; }

void OS_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxin.OS"), hx::TCanCast< OS_obj >,sStaticFields,sMemberFields,
	&__Create_OS_obj, &__Create,
	&super::__SGetClass(), &CreateOS_obj, sMarkStatics, sVisitStatic);
}

void OS_obj::__boot()
{
hx::Static(BSD) = hx::CreateEnum< OS_obj >(HX_CSTRING("BSD"),3);
hx::Static(Mac) = hx::CreateEnum< OS_obj >(HX_CSTRING("Mac"),2);
hx::Static(Windows) = hx::CreateEnum< OS_obj >(HX_CSTRING("Windows"),1);
}


} // end namespace haxin
