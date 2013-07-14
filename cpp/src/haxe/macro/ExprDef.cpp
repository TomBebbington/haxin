#include <hxcpp.h>

#ifndef INCLUDED_haxe_macro_Binop
#include <haxe/macro/Binop.h>
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
#ifndef INCLUDED_haxe_macro_Unop
#include <haxe/macro/Unop.h>
#endif
namespace haxe{
namespace macro{

::haxe::macro::ExprDef  ExprDef_obj::EArray(Dynamic e1,Dynamic e2)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EArray"),1,hx::DynamicArray(0,2).Add(e1).Add(e2)); }

::haxe::macro::ExprDef  ExprDef_obj::EArrayDecl(Dynamic values)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EArrayDecl"),6,hx::DynamicArray(0,1).Add(values)); }

::haxe::macro::ExprDef  ExprDef_obj::EBinop(::haxe::macro::Binop op,Dynamic e1,Dynamic e2)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EBinop"),2,hx::DynamicArray(0,3).Add(op).Add(e1).Add(e2)); }

::haxe::macro::ExprDef  ExprDef_obj::EBlock(Dynamic exprs)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EBlock"),12,hx::DynamicArray(0,1).Add(exprs)); }

::haxe::macro::ExprDef ExprDef_obj::EBreak;

::haxe::macro::ExprDef  ExprDef_obj::ECall(Dynamic e,Dynamic params)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("ECall"),7,hx::DynamicArray(0,2).Add(e).Add(params)); }

::haxe::macro::ExprDef  ExprDef_obj::ECast(Dynamic e,::haxe::macro::ComplexType t)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("ECast"),24,hx::DynamicArray(0,2).Add(e).Add(t)); }

::haxe::macro::ExprDef  ExprDef_obj::ECheckType(Dynamic e,::haxe::macro::ComplexType t)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("ECheckType"),28,hx::DynamicArray(0,2).Add(e).Add(t)); }

::haxe::macro::ExprDef  ExprDef_obj::EConst(::haxe::macro::Constant c)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EConst"),0,hx::DynamicArray(0,1).Add(c)); }

::haxe::macro::ExprDef ExprDef_obj::EContinue;

::haxe::macro::ExprDef  ExprDef_obj::EDisplay(Dynamic e,bool isCall)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EDisplay"),25,hx::DynamicArray(0,2).Add(e).Add(isCall)); }

::haxe::macro::ExprDef  ExprDef_obj::EDisplayNew(Dynamic t)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EDisplayNew"),26,hx::DynamicArray(0,1).Add(t)); }

::haxe::macro::ExprDef  ExprDef_obj::EField(Dynamic e,::String field)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EField"),3,hx::DynamicArray(0,2).Add(e).Add(field)); }

::haxe::macro::ExprDef  ExprDef_obj::EFor(Dynamic it,Dynamic expr)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EFor"),13,hx::DynamicArray(0,2).Add(it).Add(expr)); }

::haxe::macro::ExprDef  ExprDef_obj::EFunction(::String name,Dynamic f)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EFunction"),11,hx::DynamicArray(0,2).Add(name).Add(f)); }

::haxe::macro::ExprDef  ExprDef_obj::EIf(Dynamic econd,Dynamic eif,Dynamic eelse)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EIf"),15,hx::DynamicArray(0,3).Add(econd).Add(eif).Add(eelse)); }

::haxe::macro::ExprDef  ExprDef_obj::EIn(Dynamic e1,Dynamic e2)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EIn"),14,hx::DynamicArray(0,2).Add(e1).Add(e2)); }

::haxe::macro::ExprDef  ExprDef_obj::EMeta(Dynamic s,Dynamic e)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EMeta"),29,hx::DynamicArray(0,2).Add(s).Add(e)); }

::haxe::macro::ExprDef  ExprDef_obj::ENew(Dynamic t,Dynamic params)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("ENew"),8,hx::DynamicArray(0,2).Add(t).Add(params)); }

::haxe::macro::ExprDef  ExprDef_obj::EObjectDecl(Dynamic fields)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EObjectDecl"),5,hx::DynamicArray(0,1).Add(fields)); }

::haxe::macro::ExprDef  ExprDef_obj::EParenthesis(Dynamic e)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EParenthesis"),4,hx::DynamicArray(0,1).Add(e)); }

::haxe::macro::ExprDef  ExprDef_obj::EReturn(Dynamic e)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EReturn"),19,hx::DynamicArray(0,1).Add(e)); }

::haxe::macro::ExprDef  ExprDef_obj::ESwitch(Dynamic e,Dynamic cases,Dynamic edef)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("ESwitch"),17,hx::DynamicArray(0,3).Add(e).Add(cases).Add(edef)); }

::haxe::macro::ExprDef  ExprDef_obj::ETernary(Dynamic econd,Dynamic eif,Dynamic eelse)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("ETernary"),27,hx::DynamicArray(0,3).Add(econd).Add(eif).Add(eelse)); }

::haxe::macro::ExprDef  ExprDef_obj::EThrow(Dynamic e)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EThrow"),23,hx::DynamicArray(0,1).Add(e)); }

::haxe::macro::ExprDef  ExprDef_obj::ETry(Dynamic e,Dynamic catches)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("ETry"),18,hx::DynamicArray(0,2).Add(e).Add(catches)); }

::haxe::macro::ExprDef  ExprDef_obj::EUnop(::haxe::macro::Unop op,bool postFix,Dynamic e)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EUnop"),9,hx::DynamicArray(0,3).Add(op).Add(postFix).Add(e)); }

::haxe::macro::ExprDef  ExprDef_obj::EUntyped(Dynamic e)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EUntyped"),22,hx::DynamicArray(0,1).Add(e)); }

::haxe::macro::ExprDef  ExprDef_obj::EVars(Dynamic vars)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EVars"),10,hx::DynamicArray(0,1).Add(vars)); }

::haxe::macro::ExprDef  ExprDef_obj::EWhile(Dynamic econd,Dynamic e,bool normalWhile)
	{ return hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EWhile"),16,hx::DynamicArray(0,3).Add(econd).Add(e).Add(normalWhile)); }

HX_DEFINE_CREATE_ENUM(ExprDef_obj)

int ExprDef_obj::__FindIndex(::String inName)
{
	if (inName==HX_CSTRING("EArray")) return 1;
	if (inName==HX_CSTRING("EArrayDecl")) return 6;
	if (inName==HX_CSTRING("EBinop")) return 2;
	if (inName==HX_CSTRING("EBlock")) return 12;
	if (inName==HX_CSTRING("EBreak")) return 20;
	if (inName==HX_CSTRING("ECall")) return 7;
	if (inName==HX_CSTRING("ECast")) return 24;
	if (inName==HX_CSTRING("ECheckType")) return 28;
	if (inName==HX_CSTRING("EConst")) return 0;
	if (inName==HX_CSTRING("EContinue")) return 21;
	if (inName==HX_CSTRING("EDisplay")) return 25;
	if (inName==HX_CSTRING("EDisplayNew")) return 26;
	if (inName==HX_CSTRING("EField")) return 3;
	if (inName==HX_CSTRING("EFor")) return 13;
	if (inName==HX_CSTRING("EFunction")) return 11;
	if (inName==HX_CSTRING("EIf")) return 15;
	if (inName==HX_CSTRING("EIn")) return 14;
	if (inName==HX_CSTRING("EMeta")) return 29;
	if (inName==HX_CSTRING("ENew")) return 8;
	if (inName==HX_CSTRING("EObjectDecl")) return 5;
	if (inName==HX_CSTRING("EParenthesis")) return 4;
	if (inName==HX_CSTRING("EReturn")) return 19;
	if (inName==HX_CSTRING("ESwitch")) return 17;
	if (inName==HX_CSTRING("ETernary")) return 27;
	if (inName==HX_CSTRING("EThrow")) return 23;
	if (inName==HX_CSTRING("ETry")) return 18;
	if (inName==HX_CSTRING("EUnop")) return 9;
	if (inName==HX_CSTRING("EUntyped")) return 22;
	if (inName==HX_CSTRING("EVars")) return 10;
	if (inName==HX_CSTRING("EWhile")) return 16;
	return super::__FindIndex(inName);
}

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ExprDef_obj,EArray,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ExprDef_obj,EArrayDecl,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(ExprDef_obj,EBinop,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ExprDef_obj,EBlock,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ExprDef_obj,ECall,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ExprDef_obj,ECast,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ExprDef_obj,ECheckType,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ExprDef_obj,EConst,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ExprDef_obj,EDisplay,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ExprDef_obj,EDisplayNew,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ExprDef_obj,EField,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ExprDef_obj,EFor,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ExprDef_obj,EFunction,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(ExprDef_obj,EIf,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ExprDef_obj,EIn,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ExprDef_obj,EMeta,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ExprDef_obj,ENew,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ExprDef_obj,EObjectDecl,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ExprDef_obj,EParenthesis,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ExprDef_obj,EReturn,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(ExprDef_obj,ESwitch,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(ExprDef_obj,ETernary,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ExprDef_obj,EThrow,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC2(ExprDef_obj,ETry,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(ExprDef_obj,EUnop,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ExprDef_obj,EUntyped,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC1(ExprDef_obj,EVars,return)

STATIC_HX_DEFINE_DYNAMIC_FUNC3(ExprDef_obj,EWhile,return)

int ExprDef_obj::__FindArgCount(::String inName)
{
	if (inName==HX_CSTRING("EArray")) return 2;
	if (inName==HX_CSTRING("EArrayDecl")) return 1;
	if (inName==HX_CSTRING("EBinop")) return 3;
	if (inName==HX_CSTRING("EBlock")) return 1;
	if (inName==HX_CSTRING("EBreak")) return 0;
	if (inName==HX_CSTRING("ECall")) return 2;
	if (inName==HX_CSTRING("ECast")) return 2;
	if (inName==HX_CSTRING("ECheckType")) return 2;
	if (inName==HX_CSTRING("EConst")) return 1;
	if (inName==HX_CSTRING("EContinue")) return 0;
	if (inName==HX_CSTRING("EDisplay")) return 2;
	if (inName==HX_CSTRING("EDisplayNew")) return 1;
	if (inName==HX_CSTRING("EField")) return 2;
	if (inName==HX_CSTRING("EFor")) return 2;
	if (inName==HX_CSTRING("EFunction")) return 2;
	if (inName==HX_CSTRING("EIf")) return 3;
	if (inName==HX_CSTRING("EIn")) return 2;
	if (inName==HX_CSTRING("EMeta")) return 2;
	if (inName==HX_CSTRING("ENew")) return 2;
	if (inName==HX_CSTRING("EObjectDecl")) return 1;
	if (inName==HX_CSTRING("EParenthesis")) return 1;
	if (inName==HX_CSTRING("EReturn")) return 1;
	if (inName==HX_CSTRING("ESwitch")) return 3;
	if (inName==HX_CSTRING("ETernary")) return 3;
	if (inName==HX_CSTRING("EThrow")) return 1;
	if (inName==HX_CSTRING("ETry")) return 2;
	if (inName==HX_CSTRING("EUnop")) return 3;
	if (inName==HX_CSTRING("EUntyped")) return 1;
	if (inName==HX_CSTRING("EVars")) return 1;
	if (inName==HX_CSTRING("EWhile")) return 3;
	return super::__FindArgCount(inName);
}

Dynamic ExprDef_obj::__Field(const ::String &inName,bool inCallProp)
{
	if (inName==HX_CSTRING("EArray")) return EArray_dyn();
	if (inName==HX_CSTRING("EArrayDecl")) return EArrayDecl_dyn();
	if (inName==HX_CSTRING("EBinop")) return EBinop_dyn();
	if (inName==HX_CSTRING("EBlock")) return EBlock_dyn();
	if (inName==HX_CSTRING("EBreak")) return EBreak;
	if (inName==HX_CSTRING("ECall")) return ECall_dyn();
	if (inName==HX_CSTRING("ECast")) return ECast_dyn();
	if (inName==HX_CSTRING("ECheckType")) return ECheckType_dyn();
	if (inName==HX_CSTRING("EConst")) return EConst_dyn();
	if (inName==HX_CSTRING("EContinue")) return EContinue;
	if (inName==HX_CSTRING("EDisplay")) return EDisplay_dyn();
	if (inName==HX_CSTRING("EDisplayNew")) return EDisplayNew_dyn();
	if (inName==HX_CSTRING("EField")) return EField_dyn();
	if (inName==HX_CSTRING("EFor")) return EFor_dyn();
	if (inName==HX_CSTRING("EFunction")) return EFunction_dyn();
	if (inName==HX_CSTRING("EIf")) return EIf_dyn();
	if (inName==HX_CSTRING("EIn")) return EIn_dyn();
	if (inName==HX_CSTRING("EMeta")) return EMeta_dyn();
	if (inName==HX_CSTRING("ENew")) return ENew_dyn();
	if (inName==HX_CSTRING("EObjectDecl")) return EObjectDecl_dyn();
	if (inName==HX_CSTRING("EParenthesis")) return EParenthesis_dyn();
	if (inName==HX_CSTRING("EReturn")) return EReturn_dyn();
	if (inName==HX_CSTRING("ESwitch")) return ESwitch_dyn();
	if (inName==HX_CSTRING("ETernary")) return ETernary_dyn();
	if (inName==HX_CSTRING("EThrow")) return EThrow_dyn();
	if (inName==HX_CSTRING("ETry")) return ETry_dyn();
	if (inName==HX_CSTRING("EUnop")) return EUnop_dyn();
	if (inName==HX_CSTRING("EUntyped")) return EUntyped_dyn();
	if (inName==HX_CSTRING("EVars")) return EVars_dyn();
	if (inName==HX_CSTRING("EWhile")) return EWhile_dyn();
	return super::__Field(inName,inCallProp);
}

static ::String sStaticFields[] = {
	HX_CSTRING("EConst"),
	HX_CSTRING("EArray"),
	HX_CSTRING("EBinop"),
	HX_CSTRING("EField"),
	HX_CSTRING("EParenthesis"),
	HX_CSTRING("EObjectDecl"),
	HX_CSTRING("EArrayDecl"),
	HX_CSTRING("ECall"),
	HX_CSTRING("ENew"),
	HX_CSTRING("EUnop"),
	HX_CSTRING("EVars"),
	HX_CSTRING("EFunction"),
	HX_CSTRING("EBlock"),
	HX_CSTRING("EFor"),
	HX_CSTRING("EIn"),
	HX_CSTRING("EIf"),
	HX_CSTRING("EWhile"),
	HX_CSTRING("ESwitch"),
	HX_CSTRING("ETry"),
	HX_CSTRING("EReturn"),
	HX_CSTRING("EBreak"),
	HX_CSTRING("EContinue"),
	HX_CSTRING("EUntyped"),
	HX_CSTRING("EThrow"),
	HX_CSTRING("ECast"),
	HX_CSTRING("EDisplay"),
	HX_CSTRING("EDisplayNew"),
	HX_CSTRING("ETernary"),
	HX_CSTRING("ECheckType"),
	HX_CSTRING("EMeta"),
	::String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(ExprDef_obj::EBreak,"EBreak");
	HX_MARK_MEMBER_NAME(ExprDef_obj::EContinue,"EContinue");
};

static void sVisitStatic(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(ExprDef_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(ExprDef_obj::EBreak,"EBreak");
	HX_VISIT_MEMBER_NAME(ExprDef_obj::EContinue,"EContinue");
};

static ::String sMemberFields[] = { ::String(null()) };
Class ExprDef_obj::__mClass;

Dynamic __Create_ExprDef_obj() { return new ExprDef_obj; }

void ExprDef_obj::__register()
{

hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.macro.ExprDef"), hx::TCanCast< ExprDef_obj >,sStaticFields,sMemberFields,
	&__Create_ExprDef_obj, &__Create,
	&super::__SGetClass(), &CreateExprDef_obj, sMarkStatics, sVisitStatic);
}

void ExprDef_obj::__boot()
{
hx::Static(EBreak) = hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EBreak"),20);
hx::Static(EContinue) = hx::CreateEnum< ExprDef_obj >(HX_CSTRING("EContinue"),21);
}


} // end namespace haxe
} // end namespace macro
