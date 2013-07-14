#ifndef INCLUDED_haxe_macro_Binop
#define INCLUDED_haxe_macro_Binop

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,macro,Binop)
namespace haxe{
namespace macro{


class Binop_obj : public hx::EnumBase_obj
{
	typedef hx::EnumBase_obj super;
		typedef Binop_obj OBJ_;

	public:
		Binop_obj() {};
		HX_DO_ENUM_RTTI;
		static void __boot();
		static void __register();
		::String GetEnumName( ) const { return HX_CSTRING("haxe.macro.Binop"); }
		::String __ToString() const { return HX_CSTRING("Binop.") + tag; }

		static ::haxe::macro::Binop OpAdd;
		static inline ::haxe::macro::Binop OpAdd_dyn() { return OpAdd; }
		static ::haxe::macro::Binop OpAnd;
		static inline ::haxe::macro::Binop OpAnd_dyn() { return OpAnd; }
		static ::haxe::macro::Binop OpArrow;
		static inline ::haxe::macro::Binop OpArrow_dyn() { return OpArrow; }
		static ::haxe::macro::Binop OpAssign;
		static inline ::haxe::macro::Binop OpAssign_dyn() { return OpAssign; }
		static ::haxe::macro::Binop OpAssignOp(::haxe::macro::Binop op);
		static Dynamic OpAssignOp_dyn();
		static ::haxe::macro::Binop OpBoolAnd;
		static inline ::haxe::macro::Binop OpBoolAnd_dyn() { return OpBoolAnd; }
		static ::haxe::macro::Binop OpBoolOr;
		static inline ::haxe::macro::Binop OpBoolOr_dyn() { return OpBoolOr; }
		static ::haxe::macro::Binop OpDiv;
		static inline ::haxe::macro::Binop OpDiv_dyn() { return OpDiv; }
		static ::haxe::macro::Binop OpEq;
		static inline ::haxe::macro::Binop OpEq_dyn() { return OpEq; }
		static ::haxe::macro::Binop OpGt;
		static inline ::haxe::macro::Binop OpGt_dyn() { return OpGt; }
		static ::haxe::macro::Binop OpGte;
		static inline ::haxe::macro::Binop OpGte_dyn() { return OpGte; }
		static ::haxe::macro::Binop OpInterval;
		static inline ::haxe::macro::Binop OpInterval_dyn() { return OpInterval; }
		static ::haxe::macro::Binop OpLt;
		static inline ::haxe::macro::Binop OpLt_dyn() { return OpLt; }
		static ::haxe::macro::Binop OpLte;
		static inline ::haxe::macro::Binop OpLte_dyn() { return OpLte; }
		static ::haxe::macro::Binop OpMod;
		static inline ::haxe::macro::Binop OpMod_dyn() { return OpMod; }
		static ::haxe::macro::Binop OpMult;
		static inline ::haxe::macro::Binop OpMult_dyn() { return OpMult; }
		static ::haxe::macro::Binop OpNotEq;
		static inline ::haxe::macro::Binop OpNotEq_dyn() { return OpNotEq; }
		static ::haxe::macro::Binop OpOr;
		static inline ::haxe::macro::Binop OpOr_dyn() { return OpOr; }
		static ::haxe::macro::Binop OpShl;
		static inline ::haxe::macro::Binop OpShl_dyn() { return OpShl; }
		static ::haxe::macro::Binop OpShr;
		static inline ::haxe::macro::Binop OpShr_dyn() { return OpShr; }
		static ::haxe::macro::Binop OpSub;
		static inline ::haxe::macro::Binop OpSub_dyn() { return OpSub; }
		static ::haxe::macro::Binop OpUShr;
		static inline ::haxe::macro::Binop OpUShr_dyn() { return OpUShr; }
		static ::haxe::macro::Binop OpXor;
		static inline ::haxe::macro::Binop OpXor_dyn() { return OpXor; }
};

} // end namespace haxe
} // end namespace macro

#endif /* INCLUDED_haxe_macro_Binop */ 
