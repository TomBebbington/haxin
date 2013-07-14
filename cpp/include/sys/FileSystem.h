#ifndef INCLUDED_sys_FileSystem
#define INCLUDED_sys_FileSystem

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS1(sys,FileSystem)
HX_DECLARE_CLASS2(sys,_FileSystem,FileKind)
namespace sys{


class HXCPP_CLASS_ATTRIBUTES  FileSystem_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef FileSystem_obj OBJ_;
		FileSystem_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< FileSystem_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~FileSystem_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("FileSystem"); }

		static ::sys::_FileSystem::FileKind kind( ::String path);
		static Dynamic kind_dyn();

		static bool isDirectory( ::String path);
		static Dynamic isDirectory_dyn();

		static Dynamic sys_exists;
		static Dynamic &sys_exists_dyn() { return sys_exists;}
		static Dynamic sys_file_type;
		static Dynamic &sys_file_type_dyn() { return sys_file_type;}
};

} // end namespace sys

#endif /* INCLUDED_sys_FileSystem */ 
