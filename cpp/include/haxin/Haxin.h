#ifndef INCLUDED_haxin_Haxin
#define INCLUDED_haxin_Haxin

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(haxin,Args)
HX_DECLARE_CLASS1(haxin,Haxin)
HX_DECLARE_CLASS1(haxin,OS)
namespace haxin{


class HXCPP_CLASS_ATTRIBUTES  Haxin_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Haxin_obj OBJ_;
		Haxin_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Haxin_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Haxin_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Haxin"); }

		static ::haxin::Args args;
		static int opts;
		static ::haxin::OS os;
		static Void main( );
		static Dynamic main_dyn();

		static Void clangTo( ::String p,bool cpp);
		static Dynamic clangTo_dyn();

};

} // end namespace haxin

#endif /* INCLUDED_haxin_Haxin */ 
