#ifndef INCLUDED_haxin_OS
#define INCLUDED_haxin_OS

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxin,Distro)
HX_DECLARE_CLASS1(haxin,OS)
namespace haxin{


class OS_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef OS_obj OBJ_;

	public:
		OS_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxin.OS"); }
		::String __ToString() const { return HX_CSTRING("OS.") + tag; }

		static ::haxin::OS BSD;
		static inline ::haxin::OS BSD_dyn() { return BSD; }
		static ::haxin::OS Linux(::haxin::Distro d);
		static Dynamic Linux_dyn();
		static ::haxin::OS Mac;
		static inline ::haxin::OS Mac_dyn() { return Mac; }
		static ::haxin::OS Windows;
		static inline ::haxin::OS Windows_dyn() { return Windows; }
};

} // end namespace haxin

#endif /* INCLUDED_haxin_OS */ 
