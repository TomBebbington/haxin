#ifndef INCLUDED_haxin_HaxeGen
#define INCLUDED_haxin_HaxeGen

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(gen,Extern)
HX_DECLARE_CLASS1(haxin,HaxeGen)
HX_DECLARE_CLASS0(llvm::LLVMContext)
namespace haxin{


class HXCPP_CLASS_ATTRIBUTES  HaxeGen_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef HaxeGen_obj OBJ_;
		HaxeGen_obj();
		Void __construct(::String path);

	public:
		static hx::ObjectPtr< HaxeGen_obj > __new(::String path);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~HaxeGen_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("HaxeGen"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		Dynamic pos;
		::String path;
		::String name;
		Dynamic fields;
		::llvm::LLVMContext ctx;
		static ::String haxeFilter( ::String n,hx::Null< bool >  camel);
		static Dynamic haxeFilter_dyn();

		static ::String toHaxeName( ::String n);
		static Dynamic toHaxeName_dyn();

};

} // end namespace haxin

#endif /* INCLUDED_haxin_HaxeGen */ 
