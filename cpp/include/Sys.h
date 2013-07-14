#ifndef INCLUDED_Sys
#define INCLUDED_Sys

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(Sys)
HX_DECLARE_CLASS2(haxe,io,Output)


class HXCPP_CLASS_ATTRIBUTES  Sys_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Sys_obj OBJ_;
		Sys_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Sys_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Sys_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Sys"); }

		static Void print( Dynamic v);
		static Dynamic print_dyn();

		static Void println( Dynamic v);
		static Dynamic println_dyn();

		static ::haxe::io::Output _stderr( );
		static Dynamic _stderr_dyn();

		static Array< ::String > args( );
		static Dynamic args_dyn();

		static Void setCwd( ::String s);
		static Dynamic setCwd_dyn();

		static ::String systemName( );
		static Dynamic systemName_dyn();

		static ::String escapeArgument( ::String arg);
		static Dynamic escapeArgument_dyn();

		static int command( ::String cmd,Array< ::String > args);
		static Dynamic command_dyn();

		static Void exit( int code);
		static Dynamic exit_dyn();

		static Dynamic set_cwd;
		static Dynamic &set_cwd_dyn() { return set_cwd;}
		static Dynamic sys_string;
		static Dynamic &sys_string_dyn() { return sys_string;}
		static Dynamic sys_command;
		static Dynamic &sys_command_dyn() { return sys_command;}
		static Dynamic sys_exit;
		static Dynamic &sys_exit_dyn() { return sys_exit;}
		static Dynamic file_stderr;
		static Dynamic &file_stderr_dyn() { return file_stderr;}
};


#endif /* INCLUDED_Sys */ 
