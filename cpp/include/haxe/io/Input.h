#ifndef INCLUDED_haxe_io_Input
#define INCLUDED_haxe_io_Input

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Input)
namespace haxe{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  Input_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Input_obj OBJ_;
		Input_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Input_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Input_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Input"); }

		virtual int readInt32( );
		Dynamic readInt32_dyn();

		virtual bool set_bigEndian( bool b);
		Dynamic set_bigEndian_dyn();

		virtual Void close( );
		Dynamic close_dyn();

		virtual int readByte( );
		Dynamic readByte_dyn();

		bool bigEndian;
};

} // end namespace haxe
} // end namespace io

#endif /* INCLUDED_haxe_io_Input */ 
