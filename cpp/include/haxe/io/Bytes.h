#ifndef INCLUDED_haxe_io_Bytes
#define INCLUDED_haxe_io_Bytes

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,io,Bytes)
namespace haxe{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  Bytes_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Bytes_obj OBJ_;
		Bytes_obj();
		Void __construct(int length,Array< unsigned char > b);

	public:
		static hx::ObjectPtr< Bytes_obj > __new(int length,Array< unsigned char > b);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Bytes_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Bytes"); }

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual ::String readString( int pos,int len);
		Dynamic readString_dyn();

		Array< unsigned char > b;
		int length;
		static ::haxe::io::Bytes ofString( ::String s);
		static Dynamic ofString_dyn();

		static ::haxe::io::Bytes ofData( Array< unsigned char > b);
		static Dynamic ofData_dyn();

};

} // end namespace haxe
} // end namespace io

#endif /* INCLUDED_haxe_io_Bytes */ 
