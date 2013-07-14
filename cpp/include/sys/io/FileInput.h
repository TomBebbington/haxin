#ifndef INCLUDED_sys_io_FileInput
#define INCLUDED_sys_io_FileInput

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <haxe/io/Input.h>
HX_DECLARE_CLASS2(haxe,io,Input)
HX_DECLARE_CLASS2(sys,io,FileInput)
namespace sys{
namespace io{


class HXCPP_CLASS_ATTRIBUTES  FileInput_obj : public ::haxe::io::Input_obj{
	public:
		typedef ::haxe::io::Input_obj super;
		typedef FileInput_obj OBJ_;
		FileInput_obj();
		Void __construct(Dynamic f);

	public:
		static hx::ObjectPtr< FileInput_obj > __new(Dynamic f);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FileInput_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FileInput"); }

		virtual Void close( );

		virtual int readByte( );

		Dynamic __f;
		static Dynamic file_read_char;
		static Dynamic &file_read_char_dyn() { return file_read_char;}
		static Dynamic file_close;
		static Dynamic &file_close_dyn() { return file_close;}
};

} // end namespace sys
} // end namespace io

#endif /* INCLUDED_sys_io_FileInput */ 
