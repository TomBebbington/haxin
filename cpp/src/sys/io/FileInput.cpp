#include <hxcpp.h>

#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Eof
#include <haxe/io/Eof.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_sys_io_FileInput
#include <sys/io/FileInput.h>
#endif
namespace sys{
namespace io{

Void FileInput_obj::__construct(Dynamic f)
{
HX_STACK_PUSH("FileInput::new","sys/io/FileInput.hx",31);
{
	HX_STACK_LINE(31)
	this->__f = f;
}
;
	return null();
}

FileInput_obj::~FileInput_obj() { }

Dynamic FileInput_obj::__CreateEmpty() { return  new FileInput_obj; }
hx::ObjectPtr< FileInput_obj > FileInput_obj::__new(Dynamic f)
{  hx::ObjectPtr< FileInput_obj > result = new FileInput_obj();
	result->__construct(f);
	return result;}

Dynamic FileInput_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FileInput_obj > result = new FileInput_obj();
	result->__construct(inArgs[0]);
	return result;}

Void FileInput_obj::close( ){
{
		HX_STACK_PUSH("FileInput::close","sys/io/FileInput.hx",56);
		HX_STACK_THIS(this);
		HX_STACK_LINE(57)
		this->super::close();
		HX_STACK_LINE(58)
		::sys::io::FileInput_obj::file_close(this->__f);
	}
return null();
}


int FileInput_obj::readByte( ){
	HX_STACK_PUSH("FileInput::readByte","sys/io/FileInput.hx",35);
	HX_STACK_THIS(this);
	HX_STACK_LINE(35)
	try{
		HX_STACK_LINE(36)
		return ::sys::io::FileInput_obj::file_read_char(this->__f);
	}
	catch(Dynamic __e){
		{
			HX_STACK_BEGIN_CATCH
			Dynamic e = __e;{
				HX_STACK_LINE(38)
				if ((e->__IsArray())){
					HX_STACK_LINE(39)
					hx::Throw (::haxe::io::Eof_obj::__new());
				}
				else{
					HX_STACK_LINE(41)
					hx::Throw (::haxe::io::Error_obj::Custom(e));
				}
			}
		}
	}
	HX_STACK_LINE(35)
	return (int)0;
}


Dynamic FileInput_obj::file_read_char;

Dynamic FileInput_obj::file_close;


FileInput_obj::FileInput_obj()
{
}

void FileInput_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FileInput);
	HX_MARK_MEMBER_NAME(__f,"__f");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FileInput_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(__f,"__f");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FileInput_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__f") ) { return __f; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"file_close") ) { return file_close; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"file_read_char") ) { return file_read_char; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FileInput_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"__f") ) { __f=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"file_close") ) { file_close=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"file_read_char") ) { file_read_char=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FileInput_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("__f"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("file_read_char"),
	HX_CSTRING("file_close"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("close"),
	HX_CSTRING("readByte"),
	HX_CSTRING("__f"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FileInput_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_read_char,"file_read_char");
	HX_MARK_MEMBER_NAME(FileInput_obj::file_close,"file_close");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FileInput_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(FileInput_obj::file_read_char,"file_read_char");
	HX_VISIT_MEMBER_NAME(FileInput_obj::file_close,"file_close");
};

Class FileInput_obj::__mClass;

void FileInput_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("sys.io.FileInput"), hx::TCanCast< FileInput_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FileInput_obj::__boot()
{
	file_read_char= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_read_char"),(int)1);
	file_close= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_close"),(int)1);
}

} // end namespace sys
} // end namespace io
