#include <hxcpp.h>

#ifndef INCLUDED_haxe_macro_Binop
#include <haxe/macro/Binop.h>
#endif
namespace haxe{
namespace macro{

::haxe::macro::Binop Binop_obj::OpAdd;

::haxe::macro::Binop Binop_obj::OpAnd;

::haxe::macro::Binop Binop_obj::OpArrow;

::haxe::macro::Binop Binop_obj::OpAssign;

::haxe::macro::Binop  Binop_obj::OpAssignOp(::haxe::macro::Binop op)
	{ return hx::CreateEnum< Binop_obj >(HX_CSTRING("OpAssignOp"),20,hx::DynamicArray(0,1).Add(op)); }

::haxe::macro::Binop Binop_obj::OpBoolAnd;

::haxe::macro::Binop Binop_obj::OpBoolOr;

::haxe::macro::Binop Binop_obj::OpDiv;

::haxe::macro::Binop Binop_obj::OpEq;

::haxe::macro::Binop Binop_obj::OpGt;

::haxe::macro::Binop Binop_obj::OpGte;

::haxe::macro::Binop Binop_obj::OpInterval;

::haxe::macro::Binop Binop_obj::OpLt;

::haxe::macro::Binop Binop_obj::OpLte;

::haxe::macro::Binop Binop_obj::OpMod;

::haxe::macro::Binop Binop_obj::OpMult;

::haxe::macro::Binop Binop_obj::OpNotEq;

::haxe::macro::Binop Binop_obj::OpOr;

::haxe::macro::Binop Binop_obj::OpShl;

::haxe::macro::Binop Binop_obj::OpShr;

::haxe::macro::Binop Binop_obj::OpSub;

::haxe::macro::Binop Binop_obj::OpUShr;

::haxe::macro::Binop Binop_obj::OpXor;

HX_DEFINE_CREATE_ENUM(Binop_obj)

int Binop_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("OpAdd")) return 0;
	if (inName==HX_CSTRING("OpAnd")) return 11;
	if (inName==HX_CSTRING("OpArrow")) return 22;
	if (inName==HX_CSTRING("OpAssign")) return 4;
	if (inName==HX_CSTRING("OpAssignOp")) return 20;
	if (inName==HX_CSTRING("OpBoolAnd")) return 14;
	if (inName==HX_CSTRING("OpBoolOr")) return 15;
	if (inName==HX_CSTRING("OpDiv")) return 2;
	if (inName==HX_CSTRING("OpEq")) return 5;
	if (inName==HX_CSTRING("OpGt")) return 7;
	if (inName==HX_CSTRING("OpGte")) return 8;
	if (inName==HX_CSTRING("OpInterval")) return 21;
	if (inName==HX_CSTRING("OpLt")) return 9;
	if (inName==HX_CSTRING("OpLte")) return 10;
	if (inName==HX_CSTRING("OpMod")) return 19;
	if (inName==HX_CSTRING("OpMult")) return 1;
	if (inName==HX_CSTRING("OpNotEq")) return 6;
	if (inName==HX_CSTRING("OpOr")) return 12;
	if (inName==HX_CSTRING("OpShl")) return 16;
	if (inName==HX_CSTRING("OpShr")) return 17;
	if (inName==HX_CSTRING("OpSub")) return 3;
	if (inName==HX_CSTRING("OpUShr")) return 18;
	if (inName==HX_CSTRING("OpXor")) return 13;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC1(Binop_obj,OpAssignOp,return)

int Binop_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("OpAdd")) return 0;
	if (inName==HX_CSTRING("OpAnd")) return 0;
	if (inName==HX_CSTRING("OpArrow")) return 0;
	if (inName==HX_CSTRING("OpAssign")) return 0;
	if (inName==HX_CSTRING("OpAssignOp")) return 1;
	if (inName==HX_CSTRING("OpBoolAnd")) return 0;
	if (inName==HX_CSTRING("OpBoolOr")) return 0;
	if (inName==HX_CSTRING("OpDiv")) return 0;
	if (inName==HX_CSTRING("OpEq")) return 0;
	if (inName==HX_CSTRING("OpGt")) return 0;
	if (inName==HX_CSTRING("OpGte")) return 0;
	if (inName==HX_CSTRING("OpInterval")) return 0;
	if (inName==HX_CSTRING("OpLt")) return 0;
	if (inName==HX_CSTRING("OpLte")) return 0;
	if (inName==HX_CSTRING("OpMod")) return 0;
	if (inName==HX_CSTRING("OpMult")) return 0;
	if (inName==HX_CSTRING("OpNotEq")) return 0;
	if (inName==HX_CSTRING("OpOr")) return 0;
	if (inName==HX_CSTRING("OpShl")) return 0;
	if (inName==HX_CSTRING("OpShr")) return 0;
	if (inName==HX_CSTRING("OpSub")) return 0;
	if (inName==HX_CSTRING("OpUShr")) return 0;
	if (inName==HX_CSTRING("OpXor")) return 0;
	return super::__FindArgCount(inName);
}

Dynamic Binop_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("OpAdd")) return OpAdd;
	if (inName==HX_CSTRING("OpAnd")) return OpAnd;
	if (inName==HX_CSTRING("OpArrow")) return OpArrow;
	if (inName==HX_CSTRING("OpAssign")) return OpAssign;
	if (inName==HX_CSTRING("OpAssignOp")) return OpAssignOp_dyn();
	if (inName==HX_CSTRING("OpBoolAnd")) return OpBoolAnd;
	if (inName==HX_CSTRING("OpBoolOr")) return OpBoolOr;
	if (inName==HX_CSTRING("OpDiv")) return OpDiv;
	if (inName==HX_CSTRING("OpEq")) return OpEq;
	if (inName==HX_CSTRING("OpGt")) return OpGt;
	if (inName==HX_CSTRING("OpGte")) return OpGte;
	if (inName==HX_CSTRING("OpInterval")) return OpInterval;
	if (inName==HX_CSTRING("OpLt")) return OpLt;
	if (inName==HX_CSTRING("OpLte")) return OpLte;
	if (inName==HX_CSTRING("OpMod")) return OpMod;
	if (inName==HX_CSTRING("OpMult")) return OpMult;
	if (inName==HX_CSTRING("OpNotEq")) return OpNotEq;
	if (inName==HX_CSTRING("OpOr")) return OpOr;
	if (inName==HX_CSTRING("OpShl")) return OpShl;
	if (inName==HX_CSTRING("OpShr")) return OpShr;
	if (inName==HX_CSTRING("OpSub")) return OpSub;
	if (inName==HX_CSTRING("OpUShr")) return OpUShr;
	if (inName==HX_CSTRING("OpXor")) return OpXor;
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("OpAdd"),
	HX_CSTRING("OpMult"),
	HX_CSTRING("OpDiv"),
	HX_CSTRING("OpSub"),
	HX_CSTRING("OpAssign"),
	HX_CSTRING("OpEq"),
	HX_CSTRING("OpNotEq"),
	HX_CSTRING("OpGt"),
	HX_CSTRING("OpGte"),
	HX_CSTRING("OpLt"),
	HX_CSTRING("OpLte"),
	HX_CSTRING("OpAnd"),
	HX_CSTRING("OpOr"),
	HX_CSTRING("OpXor"),
	HX_CSTRING("OpBoolAnd"),
	HX_CSTRING("OpBoolOr"),
	HX_CSTRING("OpShl"),
	HX_CSTRING("OpShr"),
	HX_CSTRING("OpUShr"),
	HX_CSTRING("OpMod"),
	HX_CSTRING("OpAssignOp"),
	HX_CSTRING("OpInterval"),
	HX_CSTRING("OpArrow"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Binop_obj::OpAdd,"OpAdd");
	HX_MARK_MEMBER_NAME(Binop_obj::OpAnd,"OpAnd");
	HX_MARK_MEMBER_NAME(Binop_obj::OpArrow,"OpArrow");
	HX_MARK_MEMBER_NAME(Binop_obj::OpAssign,"OpAssign");
	HX_MARK_MEMBER_NAME(Binop_obj::OpBoolAnd,"OpBoolAnd");
	HX_MARK_MEMBER_NAME(Binop_obj::OpBoolOr,"OpBoolOr");
	HX_MARK_MEMBER_NAME(Binop_obj::OpDiv,"OpDiv");
	HX_MARK_MEMBER_NAME(Binop_obj::OpEq,"OpEq");
	HX_MARK_MEMBER_NAME(Binop_obj::OpGt,"OpGt");
	HX_MARK_MEMBER_NAME(Binop_obj::OpGte,"OpGte");
	HX_MARK_MEMBER_NAME(Binop_obj::OpInterval,"OpInterval");
	HX_MARK_MEMBER_NAME(Binop_obj::OpLt,"OpLt");
	HX_MARK_MEMBER_NAME(Binop_obj::OpLte,"OpLte");
	HX_MARK_MEMBER_NAME(Binop_obj::OpMod,"OpMod");
	HX_MARK_MEMBER_NAME(Binop_obj::OpMult,"OpMult");
	HX_MARK_MEMBER_NAME(Binop_obj::OpNotEq,"OpNotEq");
	HX_MARK_MEMBER_NAME(Binop_obj::OpOr,"OpOr");
	HX_MARK_MEMBER_NAME(Binop_obj::OpShl,"OpShl");
	HX_MARK_MEMBER_NAME(Binop_obj::OpShr,"OpShr");
	HX_MARK_MEMBER_NAME(Binop_obj::OpSub,"OpSub");
	HX_MARK_MEMBER_NAME(Binop_obj::OpUShr,"OpUShr");
	HX_MARK_MEMBER_NAME(Binop_obj::OpXor,"OpXor");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Binop_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpAdd,"OpAdd");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpAnd,"OpAnd");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpArrow,"OpArrow");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpAssign,"OpAssign");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpBoolAnd,"OpBoolAnd");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpBoolOr,"OpBoolOr");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpDiv,"OpDiv");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpEq,"OpEq");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpGt,"OpGt");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpGte,"OpGte");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpInterval,"OpInterval");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpLt,"OpLt");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpLte,"OpLte");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpMod,"OpMod");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpMult,"OpMult");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpNotEq,"OpNotEq");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpOr,"OpOr");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpShl,"OpShl");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpShr,"OpShr");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpSub,"OpSub");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpUShr,"OpUShr");
	HX_VISIT_MEMBER_NAME(Binop_obj::OpXor,"OpXor");
};

static ::String sMemberFields[] = { ::String(null()) };
Class Binop_obj::__mClass;

Dynamic __Create_Binop_obj() { return new Binop_obj; }

void Binop_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.macro.Binop"), hx::TCanCast< Binop_obj >,sStaticFields,sMemberFields,
	&__Create_Binop_obj, &__Create,
	&super::__SGetClass(), &CreateBinop_obj, sMarkStatics, sVisitStatic);
}

void Binop_obj::__boot()
{
hx::Static(OpAdd) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpAdd"),0);
hx::Static(OpAnd) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpAnd"),11);
hx::Static(OpArrow) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpArrow"),22);
hx::Static(OpAssign) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpAssign"),4);
hx::Static(OpBoolAnd) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpBoolAnd"),14);
hx::Static(OpBoolOr) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpBoolOr"),15);
hx::Static(OpDiv) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpDiv"),2);
hx::Static(OpEq) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpEq"),5);
hx::Static(OpGt) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpGt"),7);
hx::Static(OpGte) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpGte"),8);
hx::Static(OpInterval) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpInterval"),21);
hx::Static(OpLt) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpLt"),9);
hx::Static(OpLte) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpLte"),10);
hx::Static(OpMod) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpMod"),19);
hx::Static(OpMult) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpMult"),1);
hx::Static(OpNotEq) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpNotEq"),6);
hx::Static(OpOr) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpOr"),12);
hx::Static(OpShl) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpShl"),16);
hx::Static(OpShr) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpShr"),17);
hx::Static(OpSub) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpSub"),3);
hx::Static(OpUShr) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpUShr"),18);
hx::Static(OpXor) = hx::CreateEnum< Binop_obj >(HX_CSTRING("OpXor"),13);
}


} // end namespace haxe
} // end namespace macro
