#ifndef INCLUDED_haxe_macro_Unop
#define INCLUDED_haxe_macro_Unop

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,macro,Unop)
namespace haxe{
namespace macro{


class Unop_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Unop_obj OBJ_;

	public:
		Unop_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxe.macro.Unop"); }
		::String __ToString() const { return HX_CSTRING("Unop.") + tag; }

		static ::haxe::macro::Unop OpDecrement;
		static inline ::haxe::macro::Unop OpDecrement_dyn() { return OpDecrement; }
		static ::haxe::macro::Unop OpIncrement;
		static inline ::haxe::macro::Unop OpIncrement_dyn() { return OpIncrement; }
		static ::haxe::macro::Unop OpNeg;
		static inline ::haxe::macro::Unop OpNeg_dyn() { return OpNeg; }
		static ::haxe::macro::Unop OpNegBits;
		static inline ::haxe::macro::Unop OpNegBits_dyn() { return OpNegBits; }
		static ::haxe::macro::Unop OpNot;
		static inline ::haxe::macro::Unop OpNot_dyn() { return OpNot; }
};

} // end namespace haxe
} // end namespace macro

#endif /* INCLUDED_haxe_macro_Unop */ 
