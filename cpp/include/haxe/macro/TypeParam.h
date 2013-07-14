#ifndef INCLUDED_haxe_macro_TypeParam
#define INCLUDED_haxe_macro_TypeParam

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,macro,ComplexType)
HX_DECLARE_CLASS2(haxe,macro,TypeParam)
namespace haxe{
namespace macro{


class TypeParam_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TypeParam_obj OBJ_;

	public:
		TypeParam_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxe.macro.TypeParam"); }
		::String __ToString() const { return HX_CSTRING("TypeParam.") + tag; }

		static ::haxe::macro::TypeParam TPExpr(Dynamic e);
		static Dynamic TPExpr_dyn();
		static ::haxe::macro::TypeParam TPType(::haxe::macro::ComplexType t);
		static Dynamic TPType_dyn();
};

} // end namespace haxe
} // end namespace macro

#endif /* INCLUDED_haxe_macro_TypeParam */ 
