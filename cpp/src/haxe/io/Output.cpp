#include <hxcpp.h>

#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_haxe_io_Error
#include <haxe/io/Error.h>
#endif
#ifndef INCLUDED_haxe_io_Output
#include <haxe/io/Output.h>
#endif
namespace haxe{
namespace io{

Void Output_obj::__construct()
{
	return null();
}

Output_obj::~Output_obj() { }

Dynamic Output_obj::__CreateEmpty() { return  new Output_obj; }
hx::ObjectPtr< Output_obj > Output_obj::__new()
{  hx::ObjectPtr< Output_obj > result = new Output_obj();
	result->__construct();
	return result;}

Dynamic Output_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Output_obj > result = new Output_obj();
	result->__construct();
	return result;}

Void Output_obj::writeString( ::String s){
{
		HX_STACK_PUSH("Output::writeString","haxe/io/Output.hx",313);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_LINE(317)
		::haxe::io::Bytes b = ::haxe::io::Bytes_obj::ofString(s);		HX_STACK_VAR(b,"b");
		HX_STACK_LINE(319)
		this->writeFullBytes(b,(int)0,b->length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeString,(void))

Void Output_obj::writeFullBytes( ::haxe::io::Bytes s,int pos,int len){
{
		HX_STACK_PUSH("Output::writeFullBytes","haxe/io/Output.hx",90);
		HX_STACK_THIS(this);
		HX_STACK_ARG(s,"s");
		HX_STACK_ARG(pos,"pos");
		HX_STACK_ARG(len,"len");
		HX_STACK_LINE(90)
		while(((len > (int)0))){
			HX_STACK_LINE(91)
			int k = this->writeBytes(s,pos,len);		HX_STACK_VAR(k,"k");
			HX_STACK_LINE(92)
			hx::AddEq(pos,k);
			HX_STACK_LINE(93)
			hx::SubEq(len,k);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Output_obj,writeFullBytes,(void))

Void Output_obj::close( ){
{
		HX_STACK_PUSH("Output::close","haxe/io/Output.hx",68);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Output_obj,close,(void))

int Output_obj::writeBytes( ::haxe::io::Bytes s,int pos,int len){
	HX_STACK_PUSH("Output::writeBytes","haxe/io/Output.hx",42);
	HX_STACK_THIS(this);
	HX_STACK_ARG(s,"s");
	HX_STACK_ARG(pos,"pos");
	HX_STACK_ARG(len,"len");
	HX_STACK_LINE(43)
	int k = len;		HX_STACK_VAR(k,"k");
	HX_STACK_LINE(44)
	Array< unsigned char > b = s->b;		HX_STACK_VAR(b,"b");
	HX_STACK_LINE(46)
	if (((bool((bool((pos < (int)0)) || bool((len < (int)0)))) || bool(((pos + len) > s->length))))){
		HX_STACK_LINE(47)
		hx::Throw (::haxe::io::Error_obj::OutsideBounds);
	}
	HX_STACK_LINE(49)
	while(((k > (int)0))){
		HX_STACK_LINE(55)
		this->writeByte(b->__get(pos));
		HX_STACK_LINE(59)
		(pos)++;
		HX_STACK_LINE(60)
		(k)--;
	}
	HX_STACK_LINE(62)
	return len;
}


HX_DEFINE_DYNAMIC_FUNC3(Output_obj,writeBytes,return )

Void Output_obj::writeByte( int c){
{
		HX_STACK_PUSH("Output::writeByte","haxe/io/Output.hx",39);
		HX_STACK_THIS(this);
		HX_STACK_ARG(c,"c");
		HX_STACK_LINE(39)
		hx::Throw (HX_CSTRING("Not implemented"));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Output_obj,writeByte,(void))


Output_obj::Output_obj()
{
}

void Output_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Output);
	HX_MARK_END_CLASS();
}

void Output_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Output_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"close") ) { return close_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"writeByte") ) { return writeByte_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"writeBytes") ) { return writeBytes_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"writeString") ) { return writeString_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"writeFullBytes") ) { return writeFullBytes_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Output_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void Output_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("writeString"),
	HX_CSTRING("writeFullBytes"),
	HX_CSTRING("close"),
	HX_CSTRING("writeBytes"),
	HX_CSTRING("writeByte"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Output_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Output_obj::__mClass,"__mClass");
};

Class Output_obj::__mClass;

void Output_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.io.Output"), hx::TCanCast< Output_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Output_obj::__boot()
{
}

} // end namespace haxe
} // end namespace io
