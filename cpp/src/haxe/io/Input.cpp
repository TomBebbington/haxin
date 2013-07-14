#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Input
#include <haxe/io/Input.h>
#endif
namespace haxe{
namespace io{

Void Input_obj::__construct()
{
	return null();
}

Input_obj::~Input_obj() { }

Dynamic Input_obj::__CreateEmpty() { return  new Input_obj; }
hx::ObjectPtr< Input_obj > Input_obj::__new()
{  hx::ObjectPtr< Input_obj > result = new Input_obj();
	result->__construct();
	return result;}

Dynamic Input_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Input_obj > result = new Input_obj();
	result->__construct();
	return result;}

int Input_obj::readInt32( ){
	HX_STACK_PUSH("Input::readInt32","haxe/io/Input.hx",310);
	HX_STACK_THIS(this);
	HX_STACK_LINE(311)
	int ch1 = this->readByte();		HX_STACK_VAR(ch1,"ch1");
	HX_STACK_LINE(312)
	int ch2 = this->readByte();		HX_STACK_VAR(ch2,"ch2");
	HX_STACK_LINE(313)
	int ch3 = this->readByte();		HX_STACK_VAR(ch3,"ch3");
	HX_STACK_LINE(314)
	int ch4 = this->readByte();		HX_STACK_VAR(ch4,"ch4");
	HX_STACK_LINE(315)
	if ((this->bigEndian)){
		HX_STACK_LINE(315)
		return (int((int((int(ch4) | int((int(ch3) << int((int)8))))) | int((int(ch2) << int((int)16))))) | int((int(ch1) << int((int)24))));
	}
	else{
		HX_STACK_LINE(315)
		return (int((int((int(ch1) | int((int(ch2) << int((int)8))))) | int((int(ch3) << int((int)16))))) | int((int(ch4) << int((int)24))));
	}
	HX_STACK_LINE(315)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readInt32,return )

bool Input_obj::set_bigEndian( bool b){
	HX_STACK_PUSH("Input::set_bigEndian","haxe/io/Input.hx",70);
	HX_STACK_THIS(this);
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(71)
	this->bigEndian = b;
	HX_STACK_LINE(72)
	return b;
}


HX_DEFINE_DYNAMIC_FUNC1(Input_obj,set_bigEndian,return )

Void Input_obj::close( ){
{
		HX_STACK_PUSH("Input::close","haxe/io/Input.hx",67);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,close,(void))

int Input_obj::readByte( ){
	HX_STACK_PUSH("Input::readByte","haxe/io/Input.hx",37);
	HX_STACK_THIS(this);
	HX_STACK_LINE(39)
	hx::Throw (HX_CSTRING("Not implemented"));
	HX_STACK_LINE(40)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC0(Input_obj,readByte,return )


Input_obj::Input_obj()
{
}

void Input_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Input);
	HX_MARK_MEMBER_NAME(bigEndian,"bigEndian");
	HX_MARK_END_CLASS();
}

void Input_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bigEndian,"bigEndian");
}

Dynamic Input_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"readByte") ) { return readByte_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"readInt32") ) { return readInt32_dyn(); }
		if (HX_FIELD_EQ(inName,"bigEndian") ) { return bigEndian; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"set_bigEndian") ) { return set_bigEndian_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Input_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"bigEndian") ) { if (inCallProp) return set_bigEndian(inValue);bigEndian=inValue.Cast< bool >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Input_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bigEndian"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("readInt32"),
	HX_CSTRING("set_bigEndian"),
	HX_CSTRING("close"),
	HX_CSTRING("readByte"),
	HX_CSTRING("bigEndian"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Input_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Input_obj::__mClass,"__mClass");
};

Class Input_obj::__mClass;

void Input_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.Input"), hx::TCanCast< Input_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Input_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
