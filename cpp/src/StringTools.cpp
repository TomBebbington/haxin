#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif

Void StringTools_obj::__construct()
{
	return null();
}

StringTools_obj::~StringTools_obj() { }

Dynamic StringTools_obj::__CreateEmpty() { return  new StringTools_obj; }
hx::ObjectPtr< StringTools_obj > StringTools_obj::__new()
{  hx::ObjectPtr< StringTools_obj > result = new StringTools_obj();
	result->__construct();
	return result;}

Dynamic StringTools_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< StringTools_obj > result = new StringTools_obj();
	result->__construct();
	return result;}

bool StringTools_obj::endsWith( ::String s,::String end){
	HX_STACK_PUSH("StringTools::endsWith","StringTools.hx",145);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(end,"end");
	HX_STACK_LINE(151)
	int elen = end.length;		HX_STACK_VAR(elen,"elen");
	HX_STACK_LINE(152)
	int slen = s.length;		HX_STACK_VAR(slen,"slen");
	HX_STACK_LINE(153)
	return (bool((slen >= elen)) && bool((s.substr((slen - elen),elen) == end)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(StringTools_obj,endsWith,return )

::String StringTools_obj::replace( ::String s,::String sub,::String by){
	HX_STACK_PUSH("StringTools::replace","StringTools.hx",304);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(sub,"sub");
	HX_STACK_ARG(by,"by");
	HX_STACK_LINE(304)
	return s.split(sub)->join(by);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(StringTools_obj,replace,return )


StringTools_obj::StringTools_obj()
{
}

void StringTools_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(StringTools);
	HX_MARK_END_CLASS();
}

void StringTools_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic StringTools_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"replace") ) { return replace_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"endsWith") ) { return endsWith_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic StringTools_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void StringTools_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("endsWith"),
	HX_CSTRING("replace"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(StringTools_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(StringTools_obj::__mClass,"__mClass");
};

Class StringTools_obj::__mClass;

void StringTools_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("StringTools"), hx::TCanCast< StringTools_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void StringTools_obj::__boot()
{
}

