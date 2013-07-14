#ifndef INCLUDED_haxe_macro_TypeDefKind
#define INCLUDED_haxe_macro_TypeDefKind

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,macro,ComplexType)
HX_DECLARE_CLASS2(haxe,macro,TypeDefKind)
namespace haxe{
namespace macro{


class TypeDefKind_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef TypeDefKind_obj OBJ_;

	public:
		TypeDefKind_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxe.macro.TypeDefKind"); }
		::String __ToString() const { return HX_CSTRING("TypeDefKind.") + tag; }

		static ::haxe::macro::TypeDefKind TDAbstract(::haxe::macro::ComplexType tthis,Array< ::Dynamic > from,Array< ::Dynamic > to);
		static Dynamic TDAbstract_dyn();
		static ::haxe::macro::TypeDefKind TDAlias(::haxe::macro::ComplexType t);
		static Dynamic TDAlias_dyn();
		static ::haxe::macro::TypeDefKind TDClass(Dynamic superClass,Dynamic interfaces,Dynamic isInterface);
		static Dynamic TDClass_dyn();
		static ::haxe::macro::TypeDefKind TDEnum;
		static inline ::haxe::macro::TypeDefKind TDEnum_dyn() { return TDEnum; }
		static ::haxe::macro::TypeDefKind TDStructure;
		static inline ::haxe::macro::TypeDefKind TDStructure_dyn() { return TDStructure; }
};

} // end namespace haxe
} // end namespace macro

#endif /* INCLUDED_haxe_macro_TypeDefKind */ 
