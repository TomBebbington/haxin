#ifndef INCLUDED_haxin_Args
#define INCLUDED_haxin_Args

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(EReg)
HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
HX_DECLARE_CLASS1(haxin,Args)
namespace haxin{


class HXCPP_CLASS_ATTRIBUTES  Args_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Args_obj OBJ_;
		Args_obj();
		Void __construct(Array< ::String > ovals);

	public:
		static hx::ObjectPtr< Args_obj > __new(Array< ::String > ovals);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Args_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Args"); }

		Array< ::String > args;
		Array< ::String > flags;
		::haxe::ds::StringMap vals;
		static ::EReg REGEX_ARGS;
		static ::EReg REGEX_FLAGS;
		static Array< ::Dynamic > matches( ::String s,::EReg r,int ms);
		static Dynamic matches_dyn();

};

} // end namespace haxin

#endif /* INCLUDED_haxin_Args */ 
