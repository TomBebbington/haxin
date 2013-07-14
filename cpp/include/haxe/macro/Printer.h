#ifndef INCLUDED_haxe_macro_Printer
#define INCLUDED_haxe_macro_Printer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS2(haxe,macro,Access)
HX_DECLARE_CLASS2(haxe,macro,Binop)
HX_DECLARE_CLASS2(haxe,macro,ComplexType)
HX_DECLARE_CLASS2(haxe,macro,Constant)
HX_DECLARE_CLASS2(haxe,macro,Printer)
HX_DECLARE_CLASS2(haxe,macro,TypeParam)
HX_DECLARE_CLASS2(haxe,macro,Unop)
namespace haxe{
namespace macro{


class HXCPP_CLASS_ATTRIBUTES  Printer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Printer_obj OBJ_;
		Printer_obj();
		Void __construct(::String __o_tabString);

	public:
		static hx::ObjectPtr< Printer_obj > __new(::String __o_tabString);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Printer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Printer"); }

		virtual ::String opt( Dynamic v,Dynamic f,::String prefix);
		Dynamic opt_dyn();

		virtual ::String printTypeDefinition( Dynamic t,hx::Null< bool >  printPackage);
		Dynamic printTypeDefinition_dyn();

		virtual ::String printExprs( Dynamic el,::String sep);
		Dynamic printExprs_dyn();

		virtual ::String printExpr( Dynamic e);
		Dynamic printExpr_dyn();

		virtual ::String printVar( Dynamic v);
		Dynamic printVar_dyn();

		virtual ::String printFunction( Dynamic func);
		Dynamic printFunction_dyn();

		virtual ::String printFunctionArg( Dynamic arg);
		Dynamic printFunctionArg_dyn();

		virtual ::String printTypeParamDecl( Dynamic tpd);
		Dynamic printTypeParamDecl_dyn();

		virtual ::String printField( Dynamic field);
		Dynamic printField_dyn();

		virtual ::String printAccess( ::haxe::macro::Access access);
		Dynamic printAccess_dyn();

		virtual ::String printMetadata( Dynamic meta);
		Dynamic printMetadata_dyn();

		virtual ::String printComplexType( ::haxe::macro::ComplexType ct);
		Dynamic printComplexType_dyn();

		virtual ::String printTypePath( Dynamic tp);
		Dynamic printTypePath_dyn();

		virtual ::String printTypeParam( ::haxe::macro::TypeParam param);
		Dynamic printTypeParam_dyn();

		virtual ::String printConstant( ::haxe::macro::Constant c);
		Dynamic printConstant_dyn();

		virtual ::String printBinop( ::haxe::macro::Binop op);
		Dynamic printBinop_dyn();

		virtual ::String printUnop( ::haxe::macro::Unop op);
		Dynamic printUnop_dyn();

		::String tabString;
		::String tabs;
};

} // end namespace haxe
} // end namespace macro

#endif /* INCLUDED_haxe_macro_Printer */ 
