#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
namespace haxe{
namespace io{

Void Bytes_obj::__construct(int length,Array< unsigned char > b)
{
HX_STACK_PUSH("Bytes::new","haxe/io/Bytes.hx",29);
{
	HX_STACK_LINE(30)
	this->length = length;
	HX_STACK_LINE(31)
	this->b = b;
}
;
	return null();
}

Bytes_obj::~Bytes_obj() { }

Dynamic Bytes_obj::__CreateEmpty() { return  new Bytes_obj; }
hx::ObjectPtr< Bytes_obj > Bytes_obj::__new(int length,Array< unsigned char > b)
{  hx::ObjectPtr< Bytes_obj > result = new Bytes_obj();
	result->__construct(length,b);
	return result;}

Dynamic Bytes_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Bytes_obj > result = new Bytes_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::String Bytes_obj::toString( ){
	HX_STACK_PUSH("Bytes::toString","haxe/io/Bytes.hx",228);
	HX_STACK_THIS(this);
	HX_STACK_LINE(228)
	return this->readString((int)0,this->length);
}


HX_DEFINE_DYNAMIC_FUNC0(Bytes_obj,toString,return )

::String Bytes_obj::readString( int pos,int len){
	HX_STACK_PUSH("Bytes::readString","haxe/io/Bytes.hx",163);
	HX_STACK_THIS(this);
	HX_STACK_ARG(pos,"pos");
	HX_STACK_ARG(len,"len");
	HX_STACK_LINE(165)
	if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > this->length))))){
		HX_STACK_LINE(165)
		hx::Throw (::haxe::io::Error_obj::OutsideBounds);
	}
	HX_STACK_LINE(175)
	::String result = HX_CSTRING("");		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(176)
	::__hxcpp_string_of_bytes(this->b,result,pos,len);
	HX_STACK_LINE(177)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(Bytes_obj,readString,return )

::haxe::io::Bytes Bytes_obj::ofString( ::String s){
	HX_STACK_PUSH("Bytes::ofString","haxe/io/Bytes.hx",275);
	HX_STACK_ARG(s,"s");
	HX_STACK_LINE(286)
	Array< unsigned char > a = Array_obj< unsigned char >::__new();		HX_STACK_VAR(a,"a");
	HX_STACK_LINE(287)
	::__hxcpp_bytes_of_string(a,s);
	HX_STACK_LINE(288)
	return ::haxe::io::Bytes_obj::__new(a->length,a);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,ofString,return )

::haxe::io::Bytes Bytes_obj::ofData( Array< unsigned char > b){
	HX_STACK_PUSH("Bytes::ofData","haxe/io/Bytes.hx",334);
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(334)
	return ::haxe::io::Bytes_obj::__new(b->length,b);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Bytes_obj,ofData,return )


Bytes_obj::Bytes_obj()
{
}

void Bytes_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Bytes);
	HX_MARK_MEMBER_NAME(b,"b");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_END_CLASS();
}

void Bytes_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(b,"b");
	HX_VISIT_MEMBER_NAME(length,"length");
}

Dynamic Bytes_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { return b; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"ofData") ) { return ofData_dyn(); }
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"ofString") ) { return ofString_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"readString") ) { return readString_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Bytes_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"b") ) { b=inValue.Cast< Array< unsigned char > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Bytes_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("b"));
	outFields->push(HX_CSTRING("length"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("ofString"),
	HX_CSTRING("ofData"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("toString"),
	HX_CSTRING("readString"),
	HX_CSTRING("b"),
	HX_CSTRING("length"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Bytes_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Bytes_obj::__mClass,"__mClass");
};

Class Bytes_obj::__mClass;

void Bytes_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.Bytes"), hx::TCanCast< Bytes_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Bytes_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
