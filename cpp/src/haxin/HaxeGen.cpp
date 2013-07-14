#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_gen_Extern
#include <gen/Extern.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
#ifndef INCLUDED_haxe_macro_Access
#include <haxe/macro/Access.h>
#endif
#ifndef INCLUDED_haxe_macro_ComplexType
#include <haxe/macro/ComplexType.h>
#endif
#ifndef INCLUDED_haxe_macro_Constant
#include <haxe/macro/Constant.h>
#endif
#ifndef INCLUDED_haxe_macro_ExprDef
#include <haxe/macro/ExprDef.h>
#endif
#ifndef INCLUDED_haxe_macro_FieldType
#include <haxe/macro/FieldType.h>
#endif
#ifndef INCLUDED_haxe_macro_Printer
#include <haxe/macro/Printer.h>
#endif
#ifndef INCLUDED_haxe_macro_TypeDefKind
#include <haxe/macro/TypeDefKind.h>
#endif
#ifndef INCLUDED_haxe_macro_TypeParam
#include <haxe/macro/TypeParam.h>
#endif
#ifndef INCLUDED_haxin_HaxeGen
#include <haxin/HaxeGen.h>
#endif
#ifndef INCLUDED_llvm::LLVMContext
#include <llvm::LLVMContext.h>
#endif
#ifndef INCLUDED_llvm::Module
#include <llvm::Module.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
#ifndef INCLUDED_sys_io_File
#include <sys/io/File.h>
#endif
#ifndef INCLUDED_sys_io_FileInput
#include <sys/io/FileInput.h>
#endif
namespace haxin{

Void HaxeGen_obj::__construct(::String path)
{
HX_STACK_PUSH("HaxeGen::new","haxin/HaxeGen.hx",18);
{
	HX_STACK_LINE(19)
	this->path = path;
	struct _Function_1_1{
		inline static Dynamic Block( ::String &path){
			HX_STACK_PUSH("*::closure","haxin/HaxeGen.hx",20);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("min") , (int)0,false);
				__result->Add(HX_CSTRING("max") , (int)0,false);
				__result->Add(HX_CSTRING("file") , path,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(20)
	this->pos = _Function_1_1::Block(path);
	HX_STACK_LINE(21)
	this->name = ::haxin::HaxeGen_obj::toHaxeName(path);
	HX_STACK_LINE(22)
	this->fields = Dynamic( Array_obj<Dynamic>::__new());
	struct _Function_1_2{
		inline static Dynamic Block( ::haxin::HaxeGen_obj *__this){
			HX_STACK_PUSH("*::closure","haxin/HaxeGen.hx",23);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("name") , HX_CSTRING("main"),false);
				struct _Function_2_1{
					inline static Dynamic Block( ){
						HX_STACK_PUSH("*::closure","haxin/HaxeGen.hx",25);
						{
							hx::Anon __result = hx::Anon_obj::Create();
							struct _Function_3_1{
								inline static Dynamic Block( ){
									HX_STACK_PUSH("*::closure","haxin/HaxeGen.hx",26);
									{
										hx::Anon __result = hx::Anon_obj::Create();
										__result->Add(HX_CSTRING("pack") , Array_obj< ::String >::__new(),false);
										__result->Add(HX_CSTRING("name") , HX_CSTRING("Void"),false);
										__result->Add(HX_CSTRING("params") , Array_obj< ::Dynamic >::__new(),false);
										return __result;
									}
									return null();
								}
							};
							__result->Add(HX_CSTRING("ret") , ::haxe::macro::ComplexType_obj::TPath(_Function_3_1::Block()),false);
							__result->Add(HX_CSTRING("params") , Dynamic( Array_obj<Dynamic>::__new()),false);
							__result->Add(HX_CSTRING("args") , Dynamic( Array_obj<Dynamic>::__new()),false);
							struct _Function_3_2{
								inline static Dynamic Block( ){
									HX_STACK_PUSH("*::closure","haxin/HaxeGen.hx",29);
									{
										hx::Anon __result = hx::Anon_obj::Create();
										struct _Function_4_1{
											inline static Dynamic Block( ){
												HX_STACK_PUSH("*::closure","haxin/HaxeGen.hx",29);
												{
													hx::Anon __result = hx::Anon_obj::Create();
													__result->Add(HX_CSTRING("expr") , ::haxe::macro::ExprDef_obj::EConst(::haxe::macro::Constant_obj::CIdent(HX_CSTRING("trace"))),false);
													struct _Function_5_1{
														inline static Dynamic Block( ){
															HX_STACK_PUSH("*::closure","haxin/HaxeGen.hx",29);
															{
																hx::Anon __result = hx::Anon_obj::Create();
																__result->Add(HX_CSTRING("file") , HX_CSTRING("./haxin/HaxeGen.hx"),false);
																__result->Add(HX_CSTRING("min") , (int)645,false);
																__result->Add(HX_CSTRING("max") , (int)650,false);
																return __result;
															}
															return null();
														}
													};
													__result->Add(HX_CSTRING("pos") , _Function_5_1::Block(),false);
													return __result;
												}
												return null();
											}
										};
										struct _Function_4_2{
											inline static Dynamic Block( ){
												HX_STACK_PUSH("*::closure","haxin/HaxeGen.hx",29);
												{
													hx::Anon __result = hx::Anon_obj::Create();
													__result->Add(HX_CSTRING("expr") , ::haxe::macro::ExprDef_obj::EConst(::haxe::macro::Constant_obj::CString(HX_CSTRING("Hello, world!"))),false);
													struct _Function_5_1{
														inline static Dynamic Block( ){
															HX_STACK_PUSH("*::closure","haxin/HaxeGen.hx",29);
															{
																hx::Anon __result = hx::Anon_obj::Create();
																__result->Add(HX_CSTRING("file") , HX_CSTRING("./haxin/HaxeGen.hx"),false);
																__result->Add(HX_CSTRING("min") , (int)651,false);
																__result->Add(HX_CSTRING("max") , (int)666,false);
																return __result;
															}
															return null();
														}
													};
													__result->Add(HX_CSTRING("pos") , _Function_5_1::Block(),false);
													return __result;
												}
												return null();
											}
										};
										__result->Add(HX_CSTRING("expr") , ::haxe::macro::ExprDef_obj::ECall(_Function_4_1::Block(),Dynamic( Array_obj<Dynamic>::__new().Add(_Function_4_2::Block()))),false);
										struct _Function_4_3{
											inline static Dynamic Block( ){
												HX_STACK_PUSH("*::closure","haxin/HaxeGen.hx",29);
												{
													hx::Anon __result = hx::Anon_obj::Create();
													__result->Add(HX_CSTRING("file") , HX_CSTRING("./haxin/HaxeGen.hx"),false);
													__result->Add(HX_CSTRING("min") , (int)645,false);
													__result->Add(HX_CSTRING("max") , (int)667,false);
													return __result;
												}
												return null();
											}
										};
										__result->Add(HX_CSTRING("pos") , _Function_4_3::Block(),false);
										return __result;
									}
									return null();
								}
							};
							__result->Add(HX_CSTRING("expr") , _Function_3_2::Block(),false);
							return __result;
						}
						return null();
					}
				};
				__result->Add(HX_CSTRING("kind") , ::haxe::macro::FieldType_obj::FFun(_Function_2_1::Block()),false);
				__result->Add(HX_CSTRING("pos") , __this->pos,false);
				__result->Add(HX_CSTRING("access") , Array_obj< ::Dynamic >::__new().Add(::haxe::macro::Access_obj::APublic).Add(::haxe::macro::Access_obj::AStatic),false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(23)
	this->fields->__Field(HX_CSTRING("push"),true)(_Function_1_2::Block(this));
	HX_STACK_LINE(34)
	this->ctx = ::llvm::LLVMContext_obj::__new();
	HX_STACK_LINE(35)
	::haxe::Log_obj::trace(this->ctx,hx::SourceInfo(HX_CSTRING("HaxeGen.hx"),35,HX_CSTRING("haxin.HaxeGen"),HX_CSTRING("new")));
	HX_STACK_LINE(36)
	if ((!(::sys::FileSystem_obj::sys_exists(path)))){
		HX_STACK_LINE(37)
		::Sys_obj::_stderr()->writeString((((HX_CSTRING("\"") + path) + HX_CSTRING("\" does not exist")) + HX_CSTRING("\n")));
		HX_STACK_LINE(37)
		::Sys_obj::exit((int)9);
	}
	HX_STACK_LINE(38)
	::sys::io::FileInput i = ::sys::io::File_obj::read(path,null());		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(39)
	i->set_bigEndian(true);
	HX_STACK_LINE(40)
	if (((i->readInt32() != (int)1111736542))){
		HX_STACK_LINE(41)
		hx::Throw (HX_CSTRING("Invalid magic number"));
	}
	HX_STACK_LINE(42)
	i->close();
	HX_STACK_LINE(43)
	::Sys_obj::println(((HX_CSTRING("Parsing bitcode file at \"") + path) + HX_CSTRING("\"")));
	HX_STACK_LINE(44)
	::llvm::Module m = ::llvm::Module_obj::parseBitcodeFile(path,this->ctx);		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(45)
	::Sys_obj::println((HX_CSTRING("Parsed module: ") + HX_CSTRING("Module")));
}
;
	return null();
}

HaxeGen_obj::~HaxeGen_obj() { }

Dynamic HaxeGen_obj::__CreateEmpty() { return  new HaxeGen_obj; }
hx::ObjectPtr< HaxeGen_obj > HaxeGen_obj::__new(::String path)
{  hx::ObjectPtr< HaxeGen_obj > result = new HaxeGen_obj();
	result->__construct(path);
	return result;}

Dynamic HaxeGen_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< HaxeGen_obj > result = new HaxeGen_obj();
	result->__construct(inArgs[0]);
	return result;}

::String HaxeGen_obj::toString( ){
	HX_STACK_PUSH("HaxeGen::toString","haxin/HaxeGen.hx",51);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static Dynamic Block( ::haxin::HaxeGen_obj *__this){
			HX_STACK_PUSH("*::closure","haxin/HaxeGen.hx",52);
			{
				hx::Anon __result = hx::Anon_obj::Create();
				__result->Add(HX_CSTRING("pos") , __this->pos,false);
				__result->Add(HX_CSTRING("params") , Dynamic( Array_obj<Dynamic>::__new()),false);
				__result->Add(HX_CSTRING("pack") , Array_obj< ::String >::__new(),false);
				__result->Add(HX_CSTRING("name") , __this->name,false);
				__result->Add(HX_CSTRING("meta") , Dynamic( Array_obj<Dynamic>::__new()),false);
				__result->Add(HX_CSTRING("kind") , ::haxe::macro::TypeDefKind_obj::TDClass(null(),null(),null()),false);
				__result->Add(HX_CSTRING("isExtern") , false,false);
				__result->Add(HX_CSTRING("fields") , __this->fields,false);
				return __result;
			}
			return null();
		}
	};
	HX_STACK_LINE(52)
	Dynamic td = _Function_1_1::Block(this);		HX_STACK_VAR(td,"td");
	HX_STACK_LINE(62)
	return ::haxe::macro::Printer_obj::__new(null())->printTypeDefinition(td,null());
}


HX_DEFINE_DYNAMIC_FUNC0(HaxeGen_obj,toString,return )

::String HaxeGen_obj::haxeFilter( ::String n,hx::Null< bool >  __o_camel){
bool camel = __o_camel.Default(true);
	HX_STACK_PUSH("HaxeGen::haxeFilter","haxin/HaxeGen.hx",64);
	HX_STACK_ARG(n,"n");
	HX_STACK_ARG(camel,"camel");
{
		HX_STACK_LINE(65)
		::String notAllowed = HX_CSTRING("./+_-");		HX_STACK_VAR(notAllowed,"notAllowed");
		HX_STACK_LINE(66)
		{
			HX_STACK_LINE(66)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(66)
			int _g = notAllowed.length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(66)
			while(((_g1 < _g))){
				HX_STACK_LINE(66)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(67)
				::String c = notAllowed.charAt(i);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(68)
				int found = (int)0;		HX_STACK_VAR(found,"found");
				HX_STACK_LINE(69)
				int count = (int)0;		HX_STACK_VAR(count,"count");
				HX_STACK_LINE(70)
				while(((bool(((found = n.indexOf(c,null())) != (int)-1)) && bool(((count)++ < (int)500))))){
					HX_STACK_LINE(71)
					if ((camel)){
						HX_STACK_LINE(72)
						n = ((n.substr((int)0,found) + n.substr((found + (int)1),(int)1)) + n.substr((c.length + (int)1),null()));
					}
					else{
						HX_STACK_LINE(74)
						n = ((n.substr((int)0,found) + HX_CSTRING("_")) + n.substr(c.length,null()));
					}
				}
			}
		}
		HX_STACK_LINE(77)
		if (((n == HX_CSTRING("main")))){
			HX_STACK_LINE(78)
			n = (HX_CSTRING("_") + n);
		}
		HX_STACK_LINE(79)
		return n;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(HaxeGen_obj,haxeFilter,return )

::String HaxeGen_obj::toHaxeName( ::String n){
	HX_STACK_PUSH("HaxeGen::toHaxeName","haxin/HaxeGen.hx",81);
	HX_STACK_ARG(n,"n");
	HX_STACK_LINE(82)
	if ((::StringTools_obj::endsWith(n,HX_CSTRING(".bc")))){
		HX_STACK_LINE(82)
		n = n.substr((int)0,(n.length - (int)3));
	}
	HX_STACK_LINE(83)
	n = n.substr((n.indexOf(HX_CSTRING("."),null()) + (int)1),null());
	HX_STACK_LINE(84)
	n = n.substr((n.lastIndexOf(HX_CSTRING("/"),null()) + (int)1),null());
	HX_STACK_LINE(85)
	n = ::haxin::HaxeGen_obj::haxeFilter(n,true);
	HX_STACK_LINE(86)
	Array< ::String > parts = n.split(HX_CSTRING("::"));		HX_STACK_VAR(parts,"parts");
	HX_STACK_LINE(87)
	::String last = parts->__get((parts->length - (int)1));		HX_STACK_VAR(last,"last");
	HX_STACK_LINE(88)
	parts[(parts->length - (int)1)] = (last.charAt((int)0).toUpperCase() + last.substr((int)1,null()));
	HX_STACK_LINE(89)
	n = parts->join(HX_CSTRING("."));
	HX_STACK_LINE(90)
	return n;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(HaxeGen_obj,toHaxeName,return )


HaxeGen_obj::HaxeGen_obj()
{
}

void HaxeGen_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(HaxeGen);
	HX_MARK_MEMBER_NAME(pos,"pos");
	HX_MARK_MEMBER_NAME(path,"path");
	HX_MARK_MEMBER_NAME(name,"name");
	HX_MARK_MEMBER_NAME(fields,"fields");
	HX_MARK_MEMBER_NAME(ctx,"ctx");
	HX_MARK_END_CLASS();
}

void HaxeGen_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(pos,"pos");
	HX_VISIT_MEMBER_NAME(path,"path");
	HX_VISIT_MEMBER_NAME(name,"name");
	HX_VISIT_MEMBER_NAME(fields,"fields");
	HX_VISIT_MEMBER_NAME(ctx,"ctx");
}

Dynamic HaxeGen_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pos") ) { return pos; }
		if (HX_FIELD_EQ(inName,"ctx") ) { return ctx; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"path") ) { return path; }
		if (HX_FIELD_EQ(inName,"name") ) { return name; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"fields") ) { return fields; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"haxeFilter") ) { return haxeFilter_dyn(); }
		if (HX_FIELD_EQ(inName,"toHaxeName") ) { return toHaxeName_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic HaxeGen_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"pos") ) { pos=inValue.Cast< Dynamic >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ctx") ) { ctx=inValue.Cast< ::llvm::LLVMContext >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"path") ) { path=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"name") ) { name=inValue.Cast< ::String >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"fields") ) { fields=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void HaxeGen_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("pos"));
	outFields->push(HX_CSTRING("path"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("fields"));
	outFields->push(HX_CSTRING("ctx"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("haxeFilter"),
	HX_CSTRING("toHaxeName"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("pos"),
	HX_CSTRING("path"),
	HX_CSTRING("name"),
	HX_CSTRING("fields"),
	HX_CSTRING("ctx"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(HaxeGen_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(HaxeGen_obj::__mClass,"__mClass");
};

Class HaxeGen_obj::__mClass;

void HaxeGen_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxin.HaxeGen"), hx::TCanCast< HaxeGen_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void HaxeGen_obj::__boot()
{
}

} // end namespace haxin
