#include <hxcpp.h>

#ifndef INCLUDED_EReg
#include <EReg.h>
#endif
#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Sys
#include <Sys.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxin_Args
#include <haxin/Args.h>
#endif
#ifndef INCLUDED_sys_FileSystem
#include <sys/FileSystem.h>
#endif
namespace haxin{

Void Args_obj::__construct(Array< ::String > ovals)
{
HX_STACK_PUSH("Args::new","haxin/Args.hx",9);
{
	HX_STACK_LINE(10)
	if (((bool(::sys::FileSystem_obj::sys_exists(ovals->__get((ovals->length - (int)1)))) && bool(::sys::FileSystem_obj::isDirectory(ovals->__get((ovals->length - (int)1))))))){
		HX_STACK_LINE(11)
		::Sys_obj::setCwd(ovals->pop());
	}
	HX_STACK_LINE(12)
	::String avals = ovals->join(HX_CSTRING(" "));		HX_STACK_VAR(avals,"avals");
	HX_STACK_LINE(13)
	this->vals = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(14)
	{
		HX_STACK_LINE(14)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(14)
		Array< ::Dynamic > _g1 = ::haxin::Args_obj::matches(avals,::haxin::Args_obj::REGEX_ARGS,(int)2);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(14)
		while(((_g < _g1->length))){
			HX_STACK_LINE(14)
			Array< ::String > arg = _g1->__get(_g).StaticCast< Array< ::String > >();		HX_STACK_VAR(arg,"arg");
			HX_STACK_LINE(14)
			++(_g);
			HX_STACK_LINE(15)
			this->vals->set(arg->__get((int)0),arg->__get((int)1));
		}
	}
	HX_STACK_LINE(16)
	while((::haxin::Args_obj::REGEX_ARGS->match(avals))){
		HX_STACK_LINE(17)
		avals = ::haxin::Args_obj::REGEX_ARGS->replace(avals,HX_CSTRING(""));
	}
	HX_STACK_LINE(18)
	{
		HX_STACK_LINE(18)
		Array< ::String > _g = Array_obj< ::String >::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(18)
		{
			HX_STACK_LINE(18)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(18)
			Array< ::Dynamic > _g2 = ::haxin::Args_obj::matches(avals,::haxin::Args_obj::REGEX_FLAGS,(int)1);		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(18)
			while(((_g1 < _g2->length))){
				HX_STACK_LINE(18)
				Array< ::String > m = _g2->__get(_g1).StaticCast< Array< ::String > >();		HX_STACK_VAR(m,"m");
				HX_STACK_LINE(18)
				++(_g1);
				HX_STACK_LINE(18)
				_g->push(m->__get((int)0));
			}
		}
		HX_STACK_LINE(18)
		this->flags = _g;
	}
	HX_STACK_LINE(19)
	while((::haxin::Args_obj::REGEX_FLAGS->match(avals))){
		HX_STACK_LINE(20)
		avals = ::haxin::Args_obj::REGEX_FLAGS->replace(avals,HX_CSTRING(""));
	}
	HX_STACK_LINE(21)
	{
		HX_STACK_LINE(21)
		Array< ::String > _g1 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(21)
		{
			HX_STACK_LINE(21)
			int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
			HX_STACK_LINE(21)
			Array< ::String > _g3 = avals.split(HX_CSTRING(" "));		HX_STACK_VAR(_g3,"_g3");
			HX_STACK_LINE(21)
			while(((_g2 < _g3->length))){
				HX_STACK_LINE(21)
				::String v = _g3->__get(_g2);		HX_STACK_VAR(v,"v");
				HX_STACK_LINE(21)
				++(_g2);
				HX_STACK_LINE(21)
				if (((v.length > (int)0))){
					HX_STACK_LINE(21)
					_g1->push(v);
				}
			}
		}
		HX_STACK_LINE(21)
		this->args = _g1;
	}
}
;
	return null();
}

Args_obj::~Args_obj() { }

Dynamic Args_obj::__CreateEmpty() { return  new Args_obj; }
hx::ObjectPtr< Args_obj > Args_obj::__new(Array< ::String > ovals)
{  hx::ObjectPtr< Args_obj > result = new Args_obj();
	result->__construct(ovals);
	return result;}

Dynamic Args_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Args_obj > result = new Args_obj();
	result->__construct(inArgs[0]);
	return result;}

::EReg Args_obj::REGEX_ARGS;

::EReg Args_obj::REGEX_FLAGS;

Array< ::Dynamic > Args_obj::matches( ::String s,::EReg r,int ms){
	HX_STACK_PUSH("Args::matches","haxin/Args.hx",23);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(r,"r");
	HX_STACK_ARG(ms,"ms");
	HX_STACK_LINE(24)
	Array< ::Dynamic > a = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(25)
	int pos = (int)0;		HX_STACK_VAR(pos,"pos");
	HX_STACK_LINE(26)
	while((r->matchSub(s,pos,null()))){
		HX_STACK_LINE(27)
		Dynamic cpos = r->matchedPos();		HX_STACK_VAR(cpos,"cpos");
		HX_STACK_LINE(28)
		Array< ::String > ma = Array_obj< ::String >::__new();		HX_STACK_VAR(ma,"ma");
		HX_STACK_LINE(29)
		{
			HX_STACK_LINE(29)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(29)
			int _g = (ms + (int)1);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(29)
			while(((_g1 < _g))){
				HX_STACK_LINE(29)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(30)
				ma[i] = r->matched(i);
			}
		}
		HX_STACK_LINE(31)
		ma = ma->slice((int)1,null());
		HX_STACK_LINE(32)
		a->push(ma);
		HX_STACK_LINE(33)
		pos = (cpos->__Field(HX_CSTRING("pos"),true) + cpos->__Field(HX_CSTRING("len"),true));
	}
	HX_STACK_LINE(35)
	return a;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Args_obj,matches,return )


Args_obj::Args_obj()
{
}

void Args_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Args);
	HX_MARK_MEMBER_NAME(args,"args");
	HX_MARK_MEMBER_NAME(flags,"flags");
	HX_MARK_MEMBER_NAME(vals,"vals");
	HX_MARK_END_CLASS();
}

void Args_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(args,"args");
	HX_VISIT_MEMBER_NAME(flags,"flags");
	HX_VISIT_MEMBER_NAME(vals,"vals");
}

Dynamic Args_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"args") ) { return args; }
		if (HX_FIELD_EQ(inName,"vals") ) { return vals; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"flags") ) { return flags; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"matches") ) { return matches_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"REGEX_ARGS") ) { return REGEX_ARGS; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"REGEX_FLAGS") ) { return REGEX_FLAGS; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Args_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"args") ) { args=inValue.Cast< Array< ::String > >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vals") ) { vals=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"flags") ) { flags=inValue.Cast< Array< ::String > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"REGEX_ARGS") ) { REGEX_ARGS=inValue.Cast< ::EReg >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"REGEX_FLAGS") ) { REGEX_FLAGS=inValue.Cast< ::EReg >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Args_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("args"));
	outFields->push(HX_CSTRING("flags"));
	outFields->push(HX_CSTRING("vals"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("REGEX_ARGS"),
	HX_CSTRING("REGEX_FLAGS"),
	HX_CSTRING("matches"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("args"),
	HX_CSTRING("flags"),
	HX_CSTRING("vals"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Args_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Args_obj::REGEX_ARGS,"REGEX_ARGS");
	HX_MARK_MEMBER_NAME(Args_obj::REGEX_FLAGS,"REGEX_FLAGS");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Args_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Args_obj::REGEX_ARGS,"REGEX_ARGS");
	HX_VISIT_MEMBER_NAME(Args_obj::REGEX_FLAGS,"REGEX_FLAGS");
};

Class Args_obj::__mClass;

void Args_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxin.Args"), hx::TCanCast< Args_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Args_obj::__boot()
{
	REGEX_ARGS= ::EReg_obj::__new(HX_CSTRING("-([a-zA-Z0-9-]*) ([^- ][^ ]*)"),HX_CSTRING(""));
	REGEX_FLAGS= ::EReg_obj::__new(HX_CSTRING("-([a-zA-Z0-9-]*)"),HX_CSTRING(""));
}

} // end namespace haxin
