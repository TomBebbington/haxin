#include <hxcpp.h>

#ifndef INCLUDED_haxin_Distro
#include <haxin/Distro.h>
#endif
namespace haxin{

::haxin::Distro Distro_obj::Arch;

::haxin::Distro  Distro_obj::Debian(bool is_ubuntu)
	{ return hx::CreateEnum< Distro_obj >(HX_CSTRING("Debian"),0,hx::DynamicArray(0,1).Add(is_ubuntu)); }

::haxin::Distro  Distro_obj::Other(::String name)
	{ return hx::CreateEnum< Distro_obj >(HX_CSTRING("Other"),3,hx::DynamicArray(0,1).Add(name)); }

::haxin::Distro Distro_obj::RedHat;

HX_DEFINE_CREATE_ENUM(Distro_obj)

int Distro_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("Arch")) return 2;
	if (inName==HX_CSTRING("Debian")) return 0;
	if (inName==HX_CSTRING("Other")) return 3;
	if (inName==HX_CSTRING("RedHat")) return 1;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Distro_obj,Debian,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Distro_obj,Other,return)

int Distro_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("Arch")) return 0;
	if (inName==HX_CSTRING("Debian")) return 1;
	if (inName==HX_CSTRING("Other")) return 1;
	if (inName==HX_CSTRING("RedHat")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Distro_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("Arch")) return Arch;
	if (inName==HX_CSTRING("Debian")) return Debian_dyn();
	if (inName==HX_CSTRING("Other")) return Other_dyn();
	if (inName==HX_CSTRING("RedHat")) return RedHat;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("Debian"),
	HX_CSTRING("RedHat"),
	HX_CSTRING("Arch"),
	HX_CSTRING("Other"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Distro_obj::Arch,"Arch");
	HX_MARK_MEMBER_NAME(Distro_obj::RedHat,"RedHat");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Distro_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Distro_obj::Arch,"Arch");
	HX_VISIT_MEMBER_NAME(Distro_obj::RedHat,"RedHat");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Distro_obj::__mClass;

Dynamic __Create_Distro_obj() { return new Distro_obj; }

void Distro_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxin.Distro"), hx::TCanCast< Distro_obj >,sStaticFields,sMemberFields,
	&__Create_Distro_obj, &__Create,
	&super::__SGetClass(), &CreateDistro_obj, sMarkStatics, sVisitStatic);
}

void Distro_obj::__boot()
{
hx::Static(Arch) = hx::CreateEnum< Distro_obj >(HX_CSTRING("Arch"),2);
hx::Static(RedHat) = hx::CreateEnum< Distro_obj >(HX_CSTRING("RedHat"),1);
}


} // end namespace haxin
