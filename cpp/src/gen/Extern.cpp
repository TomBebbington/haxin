#include <hxcpp.h>

#ifndef INCLUDED_gen_Extern
#include <gen/Extern.h>
#endif
namespace gen{

Void Extern_obj::__construct()
{
	return null();
}

Extern_obj::~Extern_obj() { }

Dynamic Extern_obj::__CreateEmpty() { return  new Extern_obj; }
hx::ObjectPtr< Extern_obj > Extern_obj::__new()
{  hx::ObjectPtr< Extern_obj > result = new Extern_obj();
	result->__construct();
	return result;}

Dynamic Extern_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Extern_obj > result = new Extern_obj();
	result->__construct();
	return result;}


Extern_obj::Extern_obj()
{
}

void Extern_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Extern);
	HX_MARK_END_CLASS();
}

void Extern_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Extern_obj::__Field(const ::String &inName,bool inCallProp)
{
	return super::__Field(inName,inCallProp);
}

Dynamic Extern_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Extern_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Extern_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Extern_obj::__mClass,"__mClass");
};

Class Extern_obj::__mClass;

void Extern_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("gen.Extern"), hx::TCanCast< Extern_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Extern_obj::__boot()
{
}

} // end namespace gen
