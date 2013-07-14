#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys__FileSystem_FileKind
#include <sys/_FileSystem/FileKind.h>
#endif
namespace sys{

Void FileSystem_obj::__construct()
{
	return null();
}

FileSystem_obj::~FileSystem_obj() { }

Dynamic FileSystem_obj::__CreateEmpty() { return  new FileSystem_obj; }
hx::ObjectPtr< FileSystem_obj > FileSystem_obj::__new()
{  hx::ObjectPtr< FileSystem_obj > result = new FileSystem_obj();
	result->__construct();
	return result;}

Dynamic FileSystem_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FileSystem_obj > result = new FileSystem_obj();
	result->__construct();
	return result;}

::sys::_FileSystem::FileKind FileSystem_obj::kind( ::String path){
	HX_STACK_PUSH("FileSystem::kind","sys/FileSystem.hx",56);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(57)
	::String k = ::sys::FileSystem_obj::sys_file_type(path);		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(58)
	::String _switch_1 = (k);
	if (  ( _switch_1==HX_CSTRING("file"))){
		HX_STACK_LINE(59)
		return ::sys::_FileSystem::FileKind_obj::kfile;
	}
	else if (  ( _switch_1==HX_CSTRING("dir"))){
		HX_STACK_LINE(60)
		return ::sys::_FileSystem::FileKind_obj::kdir;
	}
	else  {
		HX_STACK_LINE(61)
		return ::sys::_FileSystem::FileKind_obj::kother(k);
	}
;
;
	HX_STACK_LINE(58)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,kind,return )

bool FileSystem_obj::isDirectory( ::String path){
	HX_STACK_PUSH("FileSystem::isDirectory","sys/FileSystem.hx",66);
	HX_STACK_ARG(path,"path");
	HX_STACK_LINE(66)
	return (::sys::FileSystem_obj::kind(path) == ::sys::_FileSystem::FileKind_obj::kdir);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(FileSystem_obj,isDirectory,return )

Dynamic FileSystem_obj::sys_exists;

Dynamic FileSystem_obj::sys_file_type;


FileSystem_obj::FileSystem_obj()
{
}

void FileSystem_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FileSystem);
	HX_MARK_END_CLASS();
}

void FileSystem_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic FileSystem_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"kind") ) { return kind_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sys_exists") ) { return sys_exists; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"isDirectory") ) { return isDirectory_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"sys_file_type") ) { return sys_file_type; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FileSystem_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 10:
		if (HX_FIELD_EQ(inName,"sys_exists") ) { sys_exists=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"sys_file_type") ) { sys_file_type=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FileSystem_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("kind"),
	HX_CSTRING("isDirectory"),
	HX_CSTRING("sys_exists"),
	HX_CSTRING("sys_file_type"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileSystem_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_exists,"sys_exists");
	HX_MARK_MEMBER_NAME(FileSystem_obj::sys_file_type,"sys_file_type");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FileSystem_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FileSystem_obj::sys_exists,"sys_exists");
	HX_VISIT_MEMBER_NAME(FileSystem_obj::sys_file_type,"sys_file_type");
};

Class FileSystem_obj::__mClass;

void FileSystem_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.FileSystem"), hx::TCanCast< FileSystem_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FileSystem_obj::__boot()
{
	sys_exists= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_exists"),(int)1);
	sys_file_type= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_file_type"),(int)1);
}

} // end namespace sys
