#ifndef INCLUDED_haxin_Distro
#define INCLUDED_haxin_Distro

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxin,Distro)
namespace haxin{


class Distro_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Distro_obj OBJ_;

	public:
		Distro_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxin.Distro"); }
		::String __ToString() const { return HX_CSTRING("Distro.") + tag; }

		static ::haxin::Distro Arch;
		static inline ::haxin::Distro Arch_dyn() { return Arch; }
		static ::haxin::Distro Debian(bool is_ubuntu);
		static Dynamic Debian_dyn();
		static ::haxin::Distro Other(::String name);
		static Dynamic Other_dyn();
		static ::haxin::Distro RedHat;
		static inline ::haxin::Distro RedHat_dyn() { return RedHat; }
};

} // end namespace haxin

#endif /* INCLUDED_haxin_Distro */ 
