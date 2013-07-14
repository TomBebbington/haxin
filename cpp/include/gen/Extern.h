#ifndef INCLUDED_gen_Extern
#define INCLUDED_gen_Extern

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(gen,Extern)
namespace gen{


class HXCPP_CLASS_ATTRIBUTES  Extern_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Extern_obj OBJ_;
		Extern_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Extern_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Extern_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Extern"); }

};

} // end namespace gen

#endif /* INCLUDED_gen_Extern */ 
