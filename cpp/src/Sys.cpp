#include <hxcpp.h>

#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_cpp_Lib
#include <cpp/Lib.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_sys_io_FileOutput
#include <sys/io/FileOutput.h>
#endif

Void Sys_obj::__construct()
{
	return null();
}

Sys_obj::~Sys_obj() { }

Dynamic Sys_obj::__CreateEmpty() { return  new Sys_obj; }
hx::ObjectPtr< Sys_obj > Sys_obj::__new()
{  hx::ObjectPtr< Sys_obj > result = new Sys_obj();
	result->__construct();
	return result;}

Dynamic Sys_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Sys_obj > result = new Sys_obj();
	result->__construct();
	return result;}

Void Sys_obj::print( Dynamic v){
{
		HX_STACK_PUSH("Sys::print","Sys.hx",25);
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(25)
		::__hxcpp_print(v);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,print,(void))

Void Sys_obj::println( Dynamic v){
{
		HX_STACK_PUSH("Sys::println","Sys.hx",28);
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(29)
		::Sys_obj::print(v);
		HX_STACK_LINE(30)
		::Sys_obj::print(HX_CSTRING("\n"));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,println,(void))

::haxe::io::Output Sys_obj::_stderr( ){
	HX_STACK_PUSH("Sys::stderr","Sys.hx",42);
	HX_STACK_LINE(42)
	return ::sys::io::FileOutput_obj::__new(::Sys_obj::file_stderr());
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,_stderr,return )

Array< ::String > Sys_obj::args( ){
	HX_STACK_PUSH("Sys::args","Sys.hx",50);
	HX_STACK_LINE(50)
	return ::__get_args();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,args,return )

Void Sys_obj::setCwd( ::String s){
{
		HX_STACK_PUSH("Sys::setCwd","Sys.hx",77);
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(77)
		::Sys_obj::set_cwd(s);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,setCwd,(void))

::String Sys_obj::systemName( ){
	HX_STACK_PUSH("Sys::systemName","Sys.hx",81);
	HX_STACK_LINE(81)
	return ::Sys_obj::sys_string();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Sys_obj,systemName,return )

::String Sys_obj::escapeArgument( ::String arg){
	HX_STACK_PUSH("Sys::escapeArgument","Sys.hx",84);
	HX_STACK_ARG(arg,"arg");
	HX_STACK_LINE(85)
	bool ok = true;		HX_STACK_VAR(ok,"ok");
	HX_STACK_LINE(86)
	{
		HX_STACK_LINE(86)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(86)
		int _g = arg.length;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(86)
		while(((_g1 < _g))){
			HX_STACK_LINE(86)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(87)
			Dynamic _g2 = arg.charCodeAt(i);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(87)
			switch( (int)(_g2)){
				case (int)32: case (int)34: {
					HX_STACK_LINE(89)
					ok = false;
				}
				;break;
				case (int)0: case (int)13: case (int)10: {
					HX_STACK_LINE(91)
					arg = arg.substr((int)0,i);
				}
				;break;
			}
		}
	}
	HX_STACK_LINE(93)
	if ((ok)){
		HX_STACK_LINE(94)
		return arg;
	}
	HX_STACK_LINE(95)
	return ((HX_CSTRING("\"") + arg.split(HX_CSTRING("\""))->join(HX_CSTRING("\\\""))) + HX_CSTRING("\""));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,escapeArgument,return )

int Sys_obj::command( ::String cmd,Array< ::String > args){
	HX_STACK_PUSH("Sys::command","Sys.hx",98);
	HX_STACK_ARG(cmd,"cmd");
	HX_STACK_ARG(args,"args");
	HX_STACK_LINE(99)
	if (((args != null()))){
		HX_STACK_LINE(100)
		cmd = ::Sys_obj::escapeArgument(cmd);
		HX_STACK_LINE(101)
		{
			HX_STACK_LINE(101)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(101)
			while(((_g < args->length))){
				HX_STACK_LINE(101)
				::String a = args->__get(_g);		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(101)
				++(_g);
				HX_STACK_LINE(102)
				hx::AddEq(cmd,(HX_CSTRING(" ") + ::Sys_obj::escapeArgument(a)));
			}
		}
	}
	HX_STACK_LINE(104)
	return ::Sys_obj::sys_command(cmd);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Sys_obj,command,return )

Void Sys_obj::exit( int code){
{
		HX_STACK_PUSH("Sys::exit","Sys.hx",108);
		HX_STACK_ARG(code,"code");
		HX_STACK_LINE(108)
		::Sys_obj::sys_exit(code);
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Sys_obj,exit,(void))

Dynamic Sys_obj::set_cwd;

Dynamic Sys_obj::sys_string;

Dynamic Sys_obj::sys_command;

Dynamic Sys_obj::sys_exit;

Dynamic Sys_obj::file_stderr;


Sys_obj::Sys_obj()
{
}

void Sys_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Sys);
	HX_MARK_END_CLASS();
}

void Sys_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Sys_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"args") ) { return args_dyn(); }
		if (HX_FIELD_EQ(inName,"exit") ) { return exit_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"print") ) { return print_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"stderr") ) { return _stderr_dyn(); }
		if (HX_FIELD_EQ(inName,"setCwd") ) { return setCwd_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"println") ) { return println_dyn(); }
		if (HX_FIELD_EQ(inName,"command") ) { return command_dyn(); }
		if (HX_FIELD_EQ(inName,"set_cwd") ) { return set_cwd; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"sys_exit") ) { return sys_exit; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"systemName") ) { return systemName_dyn(); }
		if (HX_FIELD_EQ(inName,"sys_string") ) { return sys_string; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"sys_command") ) { return sys_command; }
		if (HX_FIELD_EQ(inName,"file_stderr") ) { return file_stderr; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"escapeArgument") ) { return escapeArgument_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Sys_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"set_cwd") ) { set_cwd=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"sys_exit") ) { sys_exit=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"sys_string") ) { sys_string=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"sys_command") ) { sys_command=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"file_stderr") ) { file_stderr=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Sys_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("print"),
	HX_CSTRING("println"),
	HX_CSTRING("stderr"),
	HX_CSTRING("args"),
	HX_CSTRING("setCwd"),
	HX_CSTRING("systemName"),
	HX_CSTRING("escapeArgument"),
	HX_CSTRING("command"),
	HX_CSTRING("exit"),
	HX_CSTRING("set_cwd"),
	HX_CSTRING("sys_string"),
	HX_CSTRING("sys_command"),
	HX_CSTRING("sys_exit"),
	HX_CSTRING("file_stderr"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Sys_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Sys_obj::set_cwd,"set_cwd");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_string,"sys_string");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_command,"sys_command");
	HX_MARK_MEMBER_NAME(Sys_obj::sys_exit,"sys_exit");
	HX_MARK_MEMBER_NAME(Sys_obj::file_stderr,"file_stderr");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Sys_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Sys_obj::set_cwd,"set_cwd");
	HX_VISIT_MEMBER_NAME(Sys_obj::sys_string,"sys_string");
	HX_VISIT_MEMBER_NAME(Sys_obj::sys_command,"sys_command");
	HX_VISIT_MEMBER_NAME(Sys_obj::sys_exit,"sys_exit");
	HX_VISIT_MEMBER_NAME(Sys_obj::file_stderr,"file_stderr");
};

Class Sys_obj::__mClass;

void Sys_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Sys"), hx::TCanCast< Sys_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Sys_obj::__boot()
{
	set_cwd= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("set_cwd"),(int)1);
	sys_string= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_string"),(int)0);
	sys_command= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_command"),(int)1);
	sys_exit= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("sys_exit"),(int)1);
	file_stderr= ::cpp::Lib_obj::load(HX_CSTRING("std"),HX_CSTRING("file_stderr"),(int)0);
}

