#include <hxcpp.h>

#ifndef INCLUDED_haxe_macro_Unop
#include <haxe/macro/Unop.h>
#endif
namespace haxe{
namespace macro{

::haxe::macro::Unop Unop_obj::OpDecrement;

::haxe::macro::Unop Unop_obj::OpIncrement;

::haxe::macro::Unop Unop_obj::OpNeg;

::haxe::macro::Unop Unop_obj::OpNegBits;

::haxe::macro::Unop Unop_obj::OpNot;

HX_DEFINE_CREATE_ENUM(Unop_obj)

int Unop_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("OpDecrement")) return 1;
	if (inName==HX_CSTRING("OpIncrement")) return 0;
	if (inName==HX_CSTRING("OpNeg")) return 3;
	if (inName==HX_CSTRING("OpNegBits")) return 4;
	if (inName==HX_CSTRING("OpNot")) return 2;
	return super::__FindIndex(inName);
}

int Unop_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("OpDecrement")) return 0;
	if (inName==HX_CSTRING("OpIncrement")) return 0;
	if (inName==HX_CSTRING("OpNeg")) return 0;
	if (inName==HX_CSTRING("OpNegBits")) return 0;
	if (inName==HX_CSTRING("OpNot")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Unop_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("OpDecrement")) return OpDecrement;
	if (inName==HX_CSTRING("OpIncrement")) return OpIncrement;
	if (inName==HX_CSTRING("OpNeg")) return OpNeg;
	if (inName==HX_CSTRING("OpNegBits")) return OpNegBits;
	if (inName==HX_CSTRING("OpNot")) return OpNot;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("OpIncrement"),
	HX_CSTRING("OpDecrement"),
	HX_CSTRING("OpNot"),
	HX_CSTRING("OpNeg"),
	HX_CSTRING("OpNegBits"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Unop_obj::OpDecrement,"OpDecrement");
	HX_MARK_MEMBER_NAME(Unop_obj::OpIncrement,"OpIncrement");
	HX_MARK_MEMBER_NAME(Unop_obj::OpNeg,"OpNeg");
	HX_MARK_MEMBER_NAME(Unop_obj::OpNegBits,"OpNegBits");
	HX_MARK_MEMBER_NAME(Unop_obj::OpNot,"OpNot");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Unop_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Unop_obj::OpDecrement,"OpDecrement");
	HX_VISIT_MEMBER_NAME(Unop_obj::OpIncrement,"OpIncrement");
	HX_VISIT_MEMBER_NAME(Unop_obj::OpNeg,"OpNeg");
	HX_VISIT_MEMBER_NAME(Unop_obj::OpNegBits,"OpNegBits");
	HX_VISIT_MEMBER_NAME(Unop_obj::OpNot,"OpNot");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Unop_obj::__mClass;

Dynamic __Create_Unop_obj() { return new Unop_obj; }

void Unop_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.macro.Unop"), hx::TCanCast< Unop_obj >,sStaticFields,sMemberFields,
	&__Create_Unop_obj, &__Create,
	&super::__SGetClass(), &CreateUnop_obj, sMarkStatics, sVisitStatic);
}

void Unop_obj::__boot()
{
hx::Static(OpDecrement) = hx::CreateEnum< Unop_obj >(HX_CSTRING("OpDecrement"),1);
hx::Static(OpIncrement) = hx::CreateEnum< Unop_obj >(HX_CSTRING("OpIncrement"),0);
hx::Static(OpNeg) = hx::CreateEnum< Unop_obj >(HX_CSTRING("OpNeg"),3);
hx::Static(OpNegBits) = hx::CreateEnum< Unop_obj >(HX_CSTRING("OpNegBits"),4);
hx::Static(OpNot) = hx::CreateEnum< Unop_obj >(HX_CSTRING("OpNot"),2);
}


} // end namespace haxe
} // end namespace macro
