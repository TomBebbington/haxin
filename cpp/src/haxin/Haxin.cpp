#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Lambda
#include <Lambda.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_haxin_Args
#include <haxin/Args.h>
#endif
#ifndef INCLUDED_haxin_Distro
#include <haxin/Distro.h>
#endif
#ifndef INCLUDED_haxin_HaxeGen
#include <haxin/HaxeGen.h>
#endif
#ifndef INCLUDED_haxin_Haxin
#include <haxin/Haxin.h>
#endif
#ifndef INCLUDED_haxin_OS
#include <haxin/OS.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
namespace haxin{

Void Haxin_obj::__construct()
{
	return null();
}

Haxin_obj::~Haxin_obj() { }

Dynamic Haxin_obj::__CreateEmpty() { return  new Haxin_obj; }
hx::ObjectPtr< Haxin_obj > Haxin_obj::__new()
{  hx::ObjectPtr< Haxin_obj > result = new Haxin_obj();
	result->__construct();
	return result;}

Dynamic Haxin_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Haxin_obj > result = new Haxin_obj();
	result->__construct();
	return result;}

::haxin::Args Haxin_obj::args;

int Haxin_obj::opts;

::haxin::OS Haxin_obj::os;

Void Haxin_obj::main( ){
{
		HX_STACK_PUSH("Haxin::main","haxin/Haxin.hx",11);
		HX_STACK_LINE(12)
		{
			HX_STACK_LINE(12)
			::String _g = ::Sys_obj::systemName();		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(12)
			::String _switch_1 = (_g);
			if (  ( _switch_1==HX_CSTRING("Windows"))){
				HX_STACK_LINE(12)
				::haxin::Haxin_obj::os = ::haxin::OS_obj::Windows;
			}
			else if (  ( _switch_1==HX_CSTRING("BSD"))){
				HX_STACK_LINE(12)
				::haxin::Haxin_obj::os = ::haxin::OS_obj::BSD;
			}
			else if (  ( _switch_1==HX_CSTRING("Mac"))){
				HX_STACK_LINE(12)
				::haxin::Haxin_obj::os = ::haxin::OS_obj::Mac;
			}
			else if (  ( _switch_1==HX_CSTRING("Linux"))){
				HX_STACK_LINE(17)
				::haxin::Distro dist;		HX_STACK_VAR(dist,"dist");
				HX_STACK_LINE(17)
				if ((::sys::FileSystem_obj::sys_exists(HX_CSTRING("/etc/debian_version")))){
					HX_STACK_LINE(18)
					::String cont = ::sys::io::File_obj::getContent(HX_CSTRING("/etc/lsb-release")).toLowerCase();		HX_STACK_VAR(cont,"cont");
					HX_STACK_LINE(19)
					dist = ::haxin::Distro_obj::Debian((bool((cont.indexOf(HX_CSTRING("ubuntu"),null()) != (int)-1)) || bool((cont.indexOf(HX_CSTRING("linux mint"),null()) != (int)-1))));
				}
				else{
					HX_STACK_LINE(21)
					if ((::sys::FileSystem_obj::sys_exists(HX_CSTRING("/etc/redhat-release")))){
						HX_STACK_LINE(21)
						dist = ::haxin::Distro_obj::RedHat;
					}
					else{
						HX_STACK_LINE(22)
						if ((::sys::FileSystem_obj::sys_exists(HX_CSTRING("/usr/bin/pacman")))){
							HX_STACK_LINE(22)
							dist = ::haxin::Distro_obj::Arch;
						}
						else{
							HX_STACK_LINE(23)
							dist = ::haxin::Distro_obj::Other(HX_CSTRING("???"));
						}
					}
				}
				HX_STACK_LINE(12)
				::haxin::Haxin_obj::os = ::haxin::OS_obj::Linux(dist);
			}
			else  {
				HX_STACK_LINE(12)
				::haxin::Haxin_obj::os = null();
			}
;
;
		}
		HX_STACK_LINE(27)
		if ((::Lambda_obj::has(::haxin::Haxin_obj::args->flags,HX_CSTRING("O1")))){
			HX_STACK_LINE(27)
			::haxin::Haxin_obj::opts = (int)1;
		}
		else{
			HX_STACK_LINE(28)
			if ((::Lambda_obj::has(::haxin::Haxin_obj::args->flags,HX_CSTRING("O2")))){
				HX_STACK_LINE(27)
				::haxin::Haxin_obj::opts = (int)2;
			}
			else{
				HX_STACK_LINE(29)
				if ((::Lambda_obj::has(::haxin::Haxin_obj::args->flags,HX_CSTRING("O3")))){
					HX_STACK_LINE(27)
					::haxin::Haxin_obj::opts = (int)3;
				}
				else{
					HX_STACK_LINE(30)
					if ((::Lambda_obj::has(::haxin::Haxin_obj::args->flags,HX_CSTRING("O4")))){
						HX_STACK_LINE(27)
						::haxin::Haxin_obj::opts = (int)4;
					}
					else{
						HX_STACK_LINE(27)
						::haxin::Haxin_obj::opts = (int)0;
					}
				}
			}
		}
		HX_STACK_LINE(32)
		{
			HX_STACK_LINE(32)
			Dynamic _g1 = hx::ClassOf< ::haxin::Haxin >();		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(32)
			switch( (int)(_g1->__Field(HX_CSTRING("args"),true)->__Field(HX_CSTRING("args"),true)->__Field(HX_CSTRING("length"),true))){
				case (int)1: {
					HX_STACK_LINE(32)
					::String _switch_2 = (_g1->__Field(HX_CSTRING("args"),true)->__Field(HX_CSTRING("args"),true)->__GetItem((int)0));
					if (  ( _switch_2==HX_CSTRING("setup"))){
						HX_STACK_LINE(33)
						Dynamic _g2 = hx::ClassOf< ::haxin::Haxin >();		HX_STACK_VAR(_g2,"_g2");
						HX_STACK_LINE(33)
						{
							HX_STACK_LINE(33)
							::haxin::OS all = _g2->__Field(HX_CSTRING("os"),true);		HX_STACK_VAR(all,"all");
							HX_STACK_LINE(33)
							switch( (int)(_g2->__Field(HX_CSTRING("os"),true)->__Index())){
								case (int)0: {
									HX_STACK_LINE(35)
									try{
										HX_STACK_LINE(35)
										::sys::io::File_obj::saveContent(HX_CSTRING("/usr/bin/haxin"),HX_CSTRING("#! /bin/bash\nhaxelib run haxin $@"));
										HX_STACK_LINE(35)
										::Sys_obj::command(HX_CSTRING("sudo chmod 557 /usr/bin/haxin"),null());
									}
									catch(Dynamic __e){
										{
											HX_STACK_BEGIN_CATCH
											Dynamic e = __e;{
												HX_STACK_LINE(35)
												::Sys_obj::_stderr()->writeString((HX_CSTRING("Couldn't open /usr/bin/haxin - did you forget to run this as sudo?") + HX_CSTRING("\n")));
												HX_STACK_LINE(35)
												::Sys_obj::exit((int)9);
											}
										}
									}
								}
								;break;
								default: {
									HX_STACK_LINE(37)
									::Sys_obj::println(((HX_CSTRING("Sorry, it looks like your ") + ::Std_obj::string(all)) + HX_CSTRING(" system cannot be automatically set up")));
								}
							}
						}
					}
					else if (  ( _switch_2==HX_CSTRING("help"))){
						HX_STACK_LINE(47)
						::Sys_obj::println(HX_CSTRING("Haxin, a LLVM bitcode to Haxe compiler"));
					}
					else  {
						HX_STACK_LINE(47)
						::Sys_obj::println(HX_CSTRING("Haxin, a LLVM bitcode to Haxe compiler"));
					}
;
;
				}
				;break;
				case (int)2: {
					HX_STACK_LINE(32)
					::String _switch_3 = (_g1->__Field(HX_CSTRING("args"),true)->__Field(HX_CSTRING("args"),true)->__GetItem((int)0));
					if (  ( _switch_3==HX_CSTRING("build"))){
						HX_STACK_LINE(32)
						::String s = _g1->__Field(HX_CSTRING("args"),true)->__Field(HX_CSTRING("args"),true)->__GetItem((int)1);		HX_STACK_VAR(s,"s");
						HX_STACK_LINE(39)
						{
							HX_STACK_LINE(40)
							::String file;		HX_STACK_VAR(file,"file");
							HX_STACK_LINE(40)
							if ((::haxin::Haxin_obj::args->vals->exists(HX_CSTRING("o")))){
								HX_STACK_LINE(40)
								file = ::haxin::Haxin_obj::args->vals->get(HX_CSTRING("o"));
							}
							else{
								HX_STACK_LINE(40)
								file = ::StringTools_obj::replace(s,HX_CSTRING(".bc"),HX_CSTRING(".hx"));
							}
							HX_STACK_LINE(41)
							::sys::io::File_obj::saveContent(file,::haxin::HaxeGen_obj::__new(s)->toString());
						}
					}
					else if (  ( _switch_3==HX_CSTRING("cc"))){
						HX_STACK_LINE(32)
						::String s = _g1->__Field(HX_CSTRING("args"),true)->__Field(HX_CSTRING("args"),true)->__GetItem((int)1);		HX_STACK_VAR(s,"s");
						HX_STACK_LINE(42)
						{
							HX_STACK_LINE(43)
							::String file = ::StringTools_obj::replace(::StringTools_obj::replace(s,HX_CSTRING(".cpp"),HX_CSTRING(".bc")),HX_CSTRING(".c"),HX_CSTRING(".bc"));		HX_STACK_VAR(file,"file");
							HX_STACK_LINE(44)
							::haxin::Haxin_obj::clangTo(file,(s.indexOf(HX_CSTRING(".cpp"),null()) != (int)-1));
							HX_STACK_LINE(45)
							::sys::io::File_obj::saveContent(file,::haxin::HaxeGen_obj::__new(file)->toString());
						}
					}
					else  {
						HX_STACK_LINE(47)
						::Sys_obj::println(HX_CSTRING("Haxin, a LLVM bitcode to Haxe compiler"));
					}
;
;
				}
				;break;
				default: {
					HX_STACK_LINE(47)
					::Sys_obj::println(HX_CSTRING("Haxin, a LLVM bitcode to Haxe compiler"));
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Haxin_obj,main,(void))

Void Haxin_obj::clangTo( ::String p,bool cpp){
{
		HX_STACK_PUSH("Haxin::clangTo","haxin/Haxin.hx",50);
		HX_STACK_ARG(p,"p");
		HX_STACK_ARG(cpp,"cpp");
		HX_STACK_LINE(51)
		Array< ::String > cargs = ::haxin::Haxin_obj::args->args;		HX_STACK_VAR(cargs,"cargs");
		HX_STACK_LINE(52)
		cargs = cargs->slice((int)1,null());
		HX_STACK_LINE(53)
		::String cmd;		HX_STACK_VAR(cmd,"cmd");
		HX_STACK_LINE(53)
		if ((cpp)){
			HX_STACK_LINE(53)
			cmd = HX_CSTRING("clang++");
		}
		else{
			HX_STACK_LINE(53)
			cmd = HX_CSTRING("clang");
		}
		HX_STACK_LINE(54)
		hx::AddEq(cmd,HX_CSTRING(" -emit-llvm"));
		HX_STACK_LINE(55)
		hx::AddEq(cmd,(HX_CSTRING(" -o ") + p));
		HX_STACK_LINE(56)
		hx::AddEq(cmd,(HX_CSTRING(" -O") + ::haxin::Haxin_obj::opts));
		struct _Function_1_1{
			inline static Array< ::String > Block( Array< ::String > &cargs){
				HX_STACK_PUSH("*::closure","haxin/Haxin.hx",57);
				{
					HX_STACK_LINE(57)
					Array< ::String > _g = Array_obj< ::String >::__new();		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(57)
					{
						HX_STACK_LINE(57)
						int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
						HX_STACK_LINE(57)
						while(((_g1 < cargs->length))){
							HX_STACK_LINE(57)
							::String a = cargs->__get(_g1);		HX_STACK_VAR(a,"a");
							HX_STACK_LINE(57)
							++(_g1);
							HX_STACK_LINE(57)
							_g->push((HX_CSTRING("-c ") + a));
						}
					}
					HX_STACK_LINE(57)
					return _g;
				}
				return null();
			}
		};
		HX_STACK_LINE(57)
		hx::AddEq(cmd,(HX_CSTRING(" ") + (_Function_1_1::Block(cargs))->join(HX_CSTRING(" "))));
		HX_STACK_LINE(58)
		::Sys_obj::println(cmd);
		HX_STACK_LINE(59)
		::Sys_obj::command(cmd,null());
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Haxin_obj,clangTo,(void))


Haxin_obj::Haxin_obj()
{
}

void Haxin_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Haxin);
	HX_MARK_END_CLASS();
}

void Haxin_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Haxin_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"os") ) { return os; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"args") ) { return args; }
		if (HX_FIELD_EQ(inName,"opts") ) { return opts; }
		if (HX_FIELD_EQ(inName,"main") ) { return main_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"clangTo") ) { return clangTo_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Haxin_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"os") ) { os=inValue.Cast< ::haxin::OS >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"args") ) { args=inValue.Cast< ::haxin::Args >(); return inValue; }
		if (HX_FIELD_EQ(inName,"opts") ) { opts=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Haxin_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("args"),
	HX_CSTRING("opts"),
	HX_CSTRING("os"),
	HX_CSTRING("main"),
	HX_CSTRING("clangTo"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Haxin_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Haxin_obj::args,"args");
	HX_MARK_MEMBER_NAME(Haxin_obj::opts,"opts");
	HX_MARK_MEMBER_NAME(Haxin_obj::os,"os");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Haxin_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Haxin_obj::args,"args");
	HX_VISIT_MEMBER_NAME(Haxin_obj::opts,"opts");
	HX_VISIT_MEMBER_NAME(Haxin_obj::os,"os");
};

Class Haxin_obj::__mClass;

void Haxin_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxin.Haxin"), hx::TCanCast< Haxin_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Haxin_obj::__boot()
{
	args= ::haxin::Args_obj::__new(::Sys_obj::args());
	opts= (int)0;
}

} // end namespace haxin
