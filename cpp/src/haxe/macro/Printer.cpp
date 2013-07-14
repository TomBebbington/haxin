#include <hxcpp.h>

#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_haxe_macro_Access
#include <haxe/macro/Access.h>
#endif
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
#ifndef INCLUDED_haxe_macro_FieldType
#include <haxe/macro/FieldType.h>
#endif
#ifndef INCLUDED_haxe_macro_Printer
#include <haxe/macro/Printer.h>
#endif
#ifndef INCLUDED_haxe_macro_TypeDefKind
#include <haxe/macro/TypeDefKind.h>
#endif
#ifndef INCLUDED_haxe_macro_TypeParam
#include <haxe/macro/TypeParam.h>
#endif
#ifndef INCLUDED_haxe_macro_Unop
#include <haxe/macro/Unop.h>
#endif
namespace haxe{
namespace macro{

Void Printer_obj::__construct(::String __o_tabString)
{
HX_STACK_PUSH("Printer::new","haxe/macro/Printer.hx",32);
::String tabString = __o_tabString.Default(HX_CSTRING("\t"));
{
	HX_STACK_LINE(33)
	this->tabs = HX_CSTRING("");
	HX_STACK_LINE(34)
	this->tabString = tabString;
}
;
	return null();
}

Printer_obj::~Printer_obj() { }

Dynamic Printer_obj::__CreateEmpty() { return  new Printer_obj; }
hx::ObjectPtr< Printer_obj > Printer_obj::__new(::String __o_tabString)
{  hx::ObjectPtr< Printer_obj > result = new Printer_obj();
	result->__construct(__o_tabString);
	return result;}

Dynamic Printer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Printer_obj > result = new Printer_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Printer_obj::opt( Dynamic v,Dynamic f,::String __o_prefix){
::String prefix = __o_prefix.Default(HX_CSTRING(""));
	HX_STACK_PUSH("Printer::opt","haxe/macro/Printer.hx",277);
	HX_STACK_THIS(this);
	HX_STACK_ARG(v,"v");
	HX_STACK_ARG(f,"f");
	HX_STACK_ARG(prefix,"prefix");
{
		HX_STACK_LINE(277)
		if (((v == null()))){
			HX_STACK_LINE(277)
			return HX_CSTRING("");
		}
		else{
			HX_STACK_LINE(277)
			return (prefix + f(v).Cast< ::String >());
		}
		HX_STACK_LINE(277)
		return null();
	}
}


HX_DEFINE_DYNAMIC_FUNC3(Printer_obj,opt,return )

::String Printer_obj::printTypeDefinition( Dynamic t,hx::Null< bool >  __o_printPackage){
bool printPackage = __o_printPackage.Default(true);
	HX_STACK_PUSH("Printer::printTypeDefinition","haxe/macro/Printer.hx",212);
	HX_STACK_THIS(this);
	HX_STACK_ARG(t,"t");
	HX_STACK_ARG(printPackage,"printPackage");
{
		HX_STACK_LINE(213)
		::String old = this->tabs;		HX_STACK_VAR(old,"old");
		HX_STACK_LINE(214)
		this->tabs = this->tabString;
		HX_STACK_LINE(216)
		::String str;		HX_STACK_VAR(str,"str");
		HX_STACK_LINE(216)
		if (((t == null()))){
			HX_STACK_LINE(216)
			str = HX_CSTRING("#NULL");
		}
		else{
			struct _Function_2_1{
				inline static ::String Block( ::haxe::macro::Printer_obj *__this,Dynamic &t){
					HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",218);
					{
						HX_STACK_LINE(218)
						switch( (int)(t->__Field(HX_CSTRING("kind"),true)->__Index())){
							case (int)0: {
								struct _Function_4_1{
									inline static Array< ::String > Block( ::haxe::macro::Printer_obj *__this,Dynamic &t){
										HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",221);
										{
											HX_STACK_LINE(222)
											Array< ::String > _g = Array_obj< ::String >::__new();		HX_STACK_VAR(_g,"_g");
											HX_STACK_LINE(221)
											{
												HX_STACK_LINE(221)
												int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
												HX_STACK_LINE(221)
												Dynamic _g2 = t->__Field(HX_CSTRING("fields"),true);		HX_STACK_VAR(_g2,"_g2");
												HX_STACK_LINE(221)
												while(((_g1 < _g2->__Field(HX_CSTRING("length"),true)))){
													HX_STACK_LINE(221)
													Dynamic field = _g2->__GetItem(_g1);		HX_STACK_VAR(field,"field");
													HX_STACK_LINE(221)
													++(_g1);
													struct _Function_7_1{
														inline static ::String Block( ::haxe::macro::Printer_obj *__this,Dynamic &field){
															HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",224);
															{
																HX_STACK_LINE(224)
																switch( (int)(field->__Field(HX_CSTRING("kind"),true)->__Index())){
																	case (int)0: {
																		HX_STACK_LINE(225)
																		return field->__Field(HX_CSTRING("name"),true);
																	}
																	;break;
																	case (int)2: {
																		HX_STACK_LINE(226)
																		return hx::Throw (HX_CSTRING("FProp is invalid for TDEnum."));
																	}
																	;break;
																	case (int)1: {
																		HX_STACK_LINE(224)
																		Dynamic func = (::haxe::macro::FieldType(field->__Field(HX_CSTRING("kind"),true)))->__Param(0);		HX_STACK_VAR(func,"func");
																		HX_STACK_LINE(227)
																		return (field->__Field(HX_CSTRING("name"),true) + __this->printFunction(func));
																	}
																	;break;
																}
															}
															return null();
														}
													};
													HX_STACK_LINE(222)
													_g->push(((((__this->tabs + ((  (((bool((field->__Field(HX_CSTRING("doc"),true) != null())) && bool((field->__Field(HX_CSTRING("doc"),true) != HX_CSTRING("")))))) ? ::String((((((((HX_CSTRING("/**\n") + __this->tabs) + __this->tabString) + ::StringTools_obj::replace(field->__Field(HX_CSTRING("doc"),true),HX_CSTRING("\n"),((HX_CSTRING("\n") + __this->tabs) + __this->tabString))) + HX_CSTRING("\n")) + __this->tabs) + HX_CSTRING("**/\n")) + __this->tabs)) : ::String(HX_CSTRING("")) ))) + ((  (((bool((field->__Field(HX_CSTRING("meta"),true) != null())) && bool((field->__Field(HX_CSTRING("meta"),true)->__Field(HX_CSTRING("length"),true) > (int)0))))) ? ::String((field->__Field(HX_CSTRING("meta"),true)->__Field(HX_CSTRING("map"),true)(__this->printMetadata_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(" ")) + HX_CSTRING(" "))) : ::String(HX_CSTRING("")) ))) + _Function_7_1::Block(__this,field)) + HX_CSTRING(";")));
												}
											}
											HX_STACK_LINE(221)
											return _g;
										}
										return null();
									}
								};
								HX_STACK_LINE(220)
								return (((((HX_CSTRING("enum ") + t->__Field(HX_CSTRING("name"),true)) + ((  (((t->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("length"),true) > (int)0))) ? ::String(((HX_CSTRING("<") + t->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("map"),true)(__this->printTypeParamDecl_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", "))) + HX_CSTRING(">"))) : ::String(HX_CSTRING("")) ))) + HX_CSTRING(" {\n")) + (_Function_4_1::Block(__this,t))->join(HX_CSTRING("\n"))) + HX_CSTRING("\n}"));
							}
							;break;
							case (int)1: {
								struct _Function_4_1{
									inline static Array< ::String > Block( ::haxe::macro::Printer_obj *__this,Dynamic &t){
										HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",233);
										{
											HX_STACK_LINE(234)
											Array< ::String > _g = Array_obj< ::String >::__new();		HX_STACK_VAR(_g,"_g");
											HX_STACK_LINE(233)
											{
												HX_STACK_LINE(233)
												int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
												HX_STACK_LINE(233)
												Dynamic _g2 = t->__Field(HX_CSTRING("fields"),true);		HX_STACK_VAR(_g2,"_g2");
												HX_STACK_LINE(233)
												while(((_g1 < _g2->__Field(HX_CSTRING("length"),true)))){
													HX_STACK_LINE(233)
													Dynamic f = _g2->__GetItem(_g1);		HX_STACK_VAR(f,"f");
													HX_STACK_LINE(233)
													++(_g1);
													HX_STACK_LINE(234)
													_g->push(((__this->tabs + __this->printField(f)) + HX_CSTRING(";")));
												}
											}
											HX_STACK_LINE(233)
											return _g;
										}
										return null();
									}
								};
								HX_STACK_LINE(232)
								return (((((HX_CSTRING("typedef ") + t->__Field(HX_CSTRING("name"),true)) + ((  (((t->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("length"),true) > (int)0))) ? ::String(((HX_CSTRING("<") + t->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("map"),true)(__this->printTypeParamDecl_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", "))) + HX_CSTRING(">"))) : ::String(HX_CSTRING("")) ))) + HX_CSTRING(" = {\n")) + (_Function_4_1::Block(__this,t))->join(HX_CSTRING("\n"))) + HX_CSTRING("\n}"));
							}
							;break;
							case (int)2: {
								HX_STACK_LINE(218)
								Dynamic isInterface = (::haxe::macro::TypeDefKind(t->__Field(HX_CSTRING("kind"),true)))->__Param(2);		HX_STACK_VAR(isInterface,"isInterface");
								HX_STACK_LINE(218)
								Dynamic interfaces = (::haxe::macro::TypeDefKind(t->__Field(HX_CSTRING("kind"),true)))->__Param(1);		HX_STACK_VAR(interfaces,"interfaces");
								HX_STACK_LINE(218)
								Dynamic superClass = (::haxe::macro::TypeDefKind(t->__Field(HX_CSTRING("kind"),true)))->__Param(0);		HX_STACK_VAR(superClass,"superClass");
								struct _Function_4_1{
									inline static Array< ::String > Block( ::haxe::macro::Printer_obj *__this,Dynamic &interfaces){
										HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",240);
										{
											HX_STACK_LINE(240)
											Array< ::String > _g = Array_obj< ::String >::__new();		HX_STACK_VAR(_g,"_g");
											HX_STACK_LINE(240)
											{
												HX_STACK_LINE(240)
												int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
												HX_STACK_LINE(240)
												while(((_g1 < interfaces->__Field(HX_CSTRING("length"),true)))){
													HX_STACK_LINE(240)
													Dynamic tp = interfaces->__GetItem(_g1);		HX_STACK_VAR(tp,"tp");
													HX_STACK_LINE(240)
													++(_g1);
													HX_STACK_LINE(240)
													_g->push((HX_CSTRING(" extends ") + __this->printTypePath(tp)));
												}
											}
											HX_STACK_LINE(240)
											return _g;
										}
										return null();
									}
								};
								struct _Function_4_2{
									inline static Array< ::String > Block( ::haxe::macro::Printer_obj *__this,Dynamic &interfaces){
										HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",240);
										{
											HX_STACK_LINE(240)
											Array< ::String > _g1 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g1,"_g1");
											HX_STACK_LINE(240)
											{
												HX_STACK_LINE(240)
												int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
												HX_STACK_LINE(240)
												while(((_g2 < interfaces->__Field(HX_CSTRING("length"),true)))){
													HX_STACK_LINE(240)
													Dynamic tp = interfaces->__GetItem(_g2);		HX_STACK_VAR(tp,"tp");
													HX_STACK_LINE(240)
													++(_g2);
													HX_STACK_LINE(240)
													_g1->push((HX_CSTRING(" implements ") + __this->printTypePath(tp)));
												}
											}
											HX_STACK_LINE(240)
											return _g1;
										}
										return null();
									}
								};
								struct _Function_4_3{
									inline static Array< ::String > Block( ::haxe::macro::Printer_obj *__this,Dynamic &t){
										HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",242);
										{
											HX_STACK_LINE(242)
											Array< ::String > _g2 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g2,"_g2");
											HX_STACK_LINE(242)
											{
												HX_STACK_LINE(242)
												int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
												HX_STACK_LINE(242)
												Dynamic _g4 = t->__Field(HX_CSTRING("fields"),true);		HX_STACK_VAR(_g4,"_g4");
												HX_STACK_LINE(242)
												while(((_g3 < _g4->__Field(HX_CSTRING("length"),true)))){
													HX_STACK_LINE(242)
													Dynamic f = _g4->__GetItem(_g3);		HX_STACK_VAR(f,"f");
													HX_STACK_LINE(242)
													++(_g3);
													struct _Function_7_1{
														inline static ::String Block( ::haxe::macro::Printer_obj *__this,Dynamic &f){
															HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",242);
															{
																HX_STACK_LINE(243)
																::String fstr = __this->printField(f);		HX_STACK_VAR(fstr,"fstr");
																struct _Function_8_1{
																	inline static ::String Block( Dynamic &f){
																		HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",244);
																		{
																			HX_STACK_LINE(244)
																			switch( (int)(f->__Field(HX_CSTRING("kind"),true)->__Index())){
																				case (int)0: case (int)2: {
																					HX_STACK_LINE(245)
																					return HX_CSTRING(";");
																				}
																				;break;
																				case (int)1: {
																					HX_STACK_LINE(244)
																					Dynamic func = (::haxe::macro::FieldType(f->__Field(HX_CSTRING("kind"),true)))->__Param(0);		HX_STACK_VAR(func,"func");
																					HX_STACK_LINE(246)
																					return (  (((func->__Field(HX_CSTRING("expr"),true) == null()))) ? ::String(HX_CSTRING(";")) : ::String(HX_CSTRING("")) );
																				}
																				;break;
																				default: {
																					HX_STACK_LINE(247)
																					return HX_CSTRING("");
																				}
																			}
																		}
																		return null();
																	}
																};
																HX_STACK_LINE(244)
																return ((__this->tabs + fstr) + _Function_8_1::Block(f));
															}
															return null();
														}
													};
													HX_STACK_LINE(242)
													_g2->push(_Function_7_1::Block(__this,f));
												}
											}
											HX_STACK_LINE(242)
											return _g2;
										}
										return null();
									}
								};
								HX_STACK_LINE(238)
								return (((((((((  ((isInterface)) ? ::String(HX_CSTRING("interface ")) : ::String(HX_CSTRING("class ")) )) + t->__Field(HX_CSTRING("name"),true)) + ((  (((t->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("length"),true) > (int)0))) ? ::String(((HX_CSTRING("<") + t->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("map"),true)(__this->printTypeParamDecl_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", "))) + HX_CSTRING(">"))) : ::String(HX_CSTRING("")) ))) + ((  (((superClass != null()))) ? ::String((HX_CSTRING(" extends ") + __this->printTypePath(superClass))) : ::String(HX_CSTRING("")) ))) + ((  (((interfaces != null()))) ? ::String(((  ((isInterface)) ? Array< ::String >(_Function_4_1::Block(__this,interfaces)) : Array< ::String >(_Function_4_2::Block(__this,interfaces)) ))->join(HX_CSTRING(""))) : ::String(HX_CSTRING("")) ))) + HX_CSTRING(" {\n")) + (_Function_4_3::Block(__this,t))->join(HX_CSTRING("\n"))) + HX_CSTRING("\n}"));
							}
							;break;
							case (int)3: {
								HX_STACK_LINE(218)
								::haxe::macro::ComplexType ct = (::haxe::macro::TypeDefKind(t->__Field(HX_CSTRING("kind"),true)))->__Param(0);		HX_STACK_VAR(ct,"ct");
								HX_STACK_LINE(252)
								return (((((HX_CSTRING("typedef ") + t->__Field(HX_CSTRING("name"),true)) + ((  (((t->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("length"),true) > (int)0))) ? ::String(((HX_CSTRING("<") + t->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("map"),true)(__this->printTypeParamDecl_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", "))) + HX_CSTRING(">"))) : ::String(HX_CSTRING("")) ))) + HX_CSTRING(" = ")) + __this->printComplexType(ct)) + HX_CSTRING(";"));
							}
							;break;
							case (int)4: {
								HX_STACK_LINE(218)
								Array< ::Dynamic > to = (::haxe::macro::TypeDefKind(t->__Field(HX_CSTRING("kind"),true)))->__Param(2);		HX_STACK_VAR(to,"to");
								HX_STACK_LINE(218)
								Array< ::Dynamic > from = (::haxe::macro::TypeDefKind(t->__Field(HX_CSTRING("kind"),true)))->__Param(1);		HX_STACK_VAR(from,"from");
								HX_STACK_LINE(218)
								::haxe::macro::ComplexType tthis = (::haxe::macro::TypeDefKind(t->__Field(HX_CSTRING("kind"),true)))->__Param(0);		HX_STACK_VAR(tthis,"tthis");
								struct _Function_4_1{
									inline static Array< ::String > Block( ::haxe::macro::Printer_obj *__this,Array< ::Dynamic > &from){
										HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",259);
										{
											HX_STACK_LINE(259)
											Array< ::String > _g = Array_obj< ::String >::__new();		HX_STACK_VAR(_g,"_g");
											HX_STACK_LINE(259)
											{
												HX_STACK_LINE(259)
												int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
												HX_STACK_LINE(259)
												while(((_g1 < from->length))){
													HX_STACK_LINE(259)
													::haxe::macro::ComplexType f = from->__get(_g1).StaticCast< ::haxe::macro::ComplexType >();		HX_STACK_VAR(f,"f");
													HX_STACK_LINE(259)
													++(_g1);
													HX_STACK_LINE(259)
													_g->push((HX_CSTRING(" from ") + __this->printComplexType(f)));
												}
											}
											HX_STACK_LINE(259)
											return _g;
										}
										return null();
									}
								};
								struct _Function_4_2{
									inline static Array< ::String > Block( ::haxe::macro::Printer_obj *__this,Array< ::Dynamic > &to){
										HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",260);
										{
											HX_STACK_LINE(260)
											Array< ::String > _g1 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g1,"_g1");
											HX_STACK_LINE(260)
											{
												HX_STACK_LINE(260)
												int _g2 = (int)0;		HX_STACK_VAR(_g2,"_g2");
												HX_STACK_LINE(260)
												while(((_g2 < to->length))){
													HX_STACK_LINE(260)
													::haxe::macro::ComplexType t1 = to->__get(_g2).StaticCast< ::haxe::macro::ComplexType >();		HX_STACK_VAR(t1,"t1");
													HX_STACK_LINE(260)
													++(_g2);
													HX_STACK_LINE(260)
													_g1->push((HX_CSTRING(" to ") + __this->printComplexType(t1)));
												}
											}
											HX_STACK_LINE(260)
											return _g1;
										}
										return null();
									}
								};
								struct _Function_4_3{
									inline static Array< ::String > Block( ::haxe::macro::Printer_obj *__this,Dynamic &t){
										HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",262);
										{
											HX_STACK_LINE(262)
											Array< ::String > _g2 = Array_obj< ::String >::__new();		HX_STACK_VAR(_g2,"_g2");
											HX_STACK_LINE(262)
											{
												HX_STACK_LINE(262)
												int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
												HX_STACK_LINE(262)
												Dynamic _g4 = t->__Field(HX_CSTRING("fields"),true);		HX_STACK_VAR(_g4,"_g4");
												HX_STACK_LINE(262)
												while(((_g3 < _g4->__Field(HX_CSTRING("length"),true)))){
													HX_STACK_LINE(262)
													Dynamic f = _g4->__GetItem(_g3);		HX_STACK_VAR(f,"f");
													HX_STACK_LINE(262)
													++(_g3);
													struct _Function_7_1{
														inline static ::String Block( ::haxe::macro::Printer_obj *__this,Dynamic &f){
															HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",262);
															{
																HX_STACK_LINE(263)
																::String fstr = __this->printField(f);		HX_STACK_VAR(fstr,"fstr");
																struct _Function_8_1{
																	inline static ::String Block( Dynamic &f){
																		HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",264);
																		{
																			HX_STACK_LINE(264)
																			switch( (int)(f->__Field(HX_CSTRING("kind"),true)->__Index())){
																				case (int)0: case (int)2: {
																					HX_STACK_LINE(265)
																					return HX_CSTRING(";");
																				}
																				;break;
																				case (int)1: {
																					HX_STACK_LINE(264)
																					Dynamic func = (::haxe::macro::FieldType(f->__Field(HX_CSTRING("kind"),true)))->__Param(0);		HX_STACK_VAR(func,"func");
																					HX_STACK_LINE(266)
																					return (  (((func->__Field(HX_CSTRING("expr"),true) == null()))) ? ::String(HX_CSTRING(";")) : ::String(HX_CSTRING("")) );
																				}
																				;break;
																				default: {
																					HX_STACK_LINE(267)
																					return HX_CSTRING("");
																				}
																			}
																		}
																		return null();
																	}
																};
																HX_STACK_LINE(264)
																return ((__this->tabs + fstr) + _Function_8_1::Block(f));
															}
															return null();
														}
													};
													HX_STACK_LINE(262)
													_g2->push(_Function_7_1::Block(__this,f));
												}
											}
											HX_STACK_LINE(262)
											return _g2;
										}
										return null();
									}
								};
								HX_STACK_LINE(256)
								return ((((((((HX_CSTRING("abstract ") + t->__Field(HX_CSTRING("name"),true)) + ((  (((tthis == null()))) ? ::String(HX_CSTRING("")) : ::String(((HX_CSTRING("(") + __this->printComplexType(tthis)) + HX_CSTRING(")"))) ))) + ((  (((t->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("length"),true) > (int)0))) ? ::String(((HX_CSTRING("<") + t->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("map"),true)(__this->printTypeParamDecl_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", "))) + HX_CSTRING(">"))) : ::String(HX_CSTRING("")) ))) + ((  (((from == null()))) ? ::String(HX_CSTRING("")) : ::String((_Function_4_1::Block(__this,from))->join(HX_CSTRING(""))) ))) + ((  (((to == null()))) ? ::String(HX_CSTRING("")) : ::String((_Function_4_2::Block(__this,to))->join(HX_CSTRING(""))) ))) + HX_CSTRING(" {\n")) + (_Function_4_3::Block(__this,t))->join(HX_CSTRING("\n"))) + HX_CSTRING("\n}"));
							}
							;break;
						}
					}
					return null();
				}
			};
			HX_STACK_LINE(217)
			str = (((((  (((bool((bool(printPackage) && bool((t->__Field(HX_CSTRING("pack"),true)->__Field(HX_CSTRING("length"),true) > (int)0)))) && bool((t->__Field(HX_CSTRING("pack"),true)->__GetItem((int)0) != HX_CSTRING("")))))) ? ::String(((HX_CSTRING("package ") + t->__Field(HX_CSTRING("pack"),true)->__Field(HX_CSTRING("join"),true)(HX_CSTRING("."))) + HX_CSTRING(";\n"))) : ::String(HX_CSTRING("")) )) + ((  (((bool((t->__Field(HX_CSTRING("meta"),true) != null())) && bool((t->__Field(HX_CSTRING("meta"),true)->__Field(HX_CSTRING("length"),true) > (int)0))))) ? ::String((t->__Field(HX_CSTRING("meta"),true)->__Field(HX_CSTRING("map"),true)(this->printMetadata_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(" ")) + HX_CSTRING(" "))) : ::String(HX_CSTRING("")) ))) + ((  ((t->__Field(HX_CSTRING("isExtern"),true))) ? ::String(HX_CSTRING("extern ")) : ::String(HX_CSTRING("")) ))) + _Function_2_1::Block(this,t));
		}
		HX_STACK_LINE(273)
		this->tabs = old;
		HX_STACK_LINE(274)
		return str;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Printer_obj,printTypeDefinition,return )

::String Printer_obj::printExprs( Dynamic el,::String sep){
	HX_STACK_PUSH("Printer::printExprs","haxe/macro/Printer.hx",209);
	HX_STACK_THIS(this);
	HX_STACK_ARG(el,"el");
	HX_STACK_ARG(sep,"sep");
	HX_STACK_LINE(209)
	return el->__Field(HX_CSTRING("map"),true)(this->printExpr_dyn())->__Field(HX_CSTRING("join"),true)(sep);
}


HX_DEFINE_DYNAMIC_FUNC2(Printer_obj,printExprs,return )

::String Printer_obj::printExpr( Dynamic e){
	HX_STACK_PUSH("Printer::printExpr","haxe/macro/Printer.hx",150);
	HX_STACK_THIS(this);
	HX_STACK_ARG(e,"e");
	HX_STACK_LINE(150)
	Array< ::Dynamic > _g = Array_obj< ::Dynamic >::__new().Add(hx::ObjectPtr<OBJ_>(this));		HX_STACK_VAR(_g,"_g");
	HX_STACK_LINE(150)
	if (((e == null()))){
		HX_STACK_LINE(150)
		return HX_CSTRING("#NULL");
	}
	else{
		HX_STACK_LINE(150)
		switch( (int)(e->__Field(HX_CSTRING("expr"),true)->__Index())){
			case (int)0: {
				HX_STACK_LINE(150)
				::haxe::macro::Constant c = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(151)
				return this->printConstant(c);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(150)
				Dynamic e2 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(e2,"e2");
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(152)
				return ((((HX_CSTRING("") + this->printExpr(e1)) + HX_CSTRING("[")) + this->printExpr(e2)) + HX_CSTRING("]"));
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(150)
				Dynamic e2 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(2);		HX_STACK_VAR(e2,"e2");
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(150)
				::haxe::macro::Binop op = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(op,"op");
				HX_STACK_LINE(153)
				return (((((HX_CSTRING("") + this->printExpr(e1)) + HX_CSTRING(" ")) + this->printBinop(op)) + HX_CSTRING(" ")) + this->printExpr(e2));
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(150)
				::String n = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(n,"n");
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(154)
				return (((HX_CSTRING("") + this->printExpr(e1)) + HX_CSTRING(".")) + n);
			}
			;break;
			case (int)4: {
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(155)
				return ((HX_CSTRING("(") + this->printExpr(e1)) + HX_CSTRING(")"));
			}
			;break;
			case (int)5: {
				HX_STACK_LINE(150)
				Dynamic fl = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(fl,"fl");

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Array< ::Dynamic >,_g)
				::String run(Dynamic fld){
					HX_STACK_PUSH("*::_Function_3_1","haxe/macro/Printer.hx",157);
					HX_STACK_ARG(fld,"fld");
					{
						HX_STACK_LINE(157)
						return ((((HX_CSTRING("") + fld->__Field(HX_CSTRING("field"),true)) + HX_CSTRING(" : ")) + _g->__get((int)0).StaticCast< ::haxe::macro::Printer >()->printExpr(fld->__Field(HX_CSTRING("expr"),true))) + HX_CSTRING(" "));
					}
					return null();
				}
				HX_END_LOCAL_FUNC1(return)

				HX_STACK_LINE(157)
				return ((HX_CSTRING("{ ") + fl->__Field(HX_CSTRING("map"),true)( Dynamic(new _Function_3_1(_g)))->__Field(HX_CSTRING("join"),true)(HX_CSTRING(","))) + HX_CSTRING("}"));
			}
			;break;
			case (int)6: {
				HX_STACK_LINE(150)
				Dynamic el = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(el,"el");
				HX_STACK_LINE(158)
				return ((HX_CSTRING("[") + this->printExprs(el,HX_CSTRING(", "))) + HX_CSTRING("]"));
			}
			;break;
			case (int)7: {
				HX_STACK_LINE(150)
				Dynamic el = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(el,"el");
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(159)
				return ((((HX_CSTRING("") + this->printExpr(e1)) + HX_CSTRING("(")) + this->printExprs(el,HX_CSTRING(", "))) + HX_CSTRING(")"));
			}
			;break;
			case (int)8: {
				HX_STACK_LINE(150)
				Dynamic el = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(el,"el");
				HX_STACK_LINE(150)
				Dynamic tp = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(tp,"tp");
				HX_STACK_LINE(160)
				return ((((HX_CSTRING("new ") + this->printTypePath(tp)) + HX_CSTRING("(")) + this->printExprs(el,HX_CSTRING(", "))) + HX_CSTRING(")"));
			}
			;break;
			case (int)9: {
				HX_STACK_LINE(150)
				bool _switch_1 = ((::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1));
				if (  ( _switch_1==true)){
					HX_STACK_LINE(150)
					Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(2);		HX_STACK_VAR(e1,"e1");
					HX_STACK_LINE(150)
					::haxe::macro::Unop op = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(op,"op");
					HX_STACK_LINE(161)
					return (this->printExpr(e1) + this->printUnop(op));
				}
				else if (  ( _switch_1==false)){
					HX_STACK_LINE(150)
					Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(2);		HX_STACK_VAR(e1,"e1");
					HX_STACK_LINE(150)
					::haxe::macro::Unop op = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(op,"op");
					HX_STACK_LINE(162)
					return (this->printUnop(op) + this->printExpr(e1));
				}
			}
			;break;
			case (int)11: {
				HX_STACK_LINE(150)
				Dynamic func = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(func,"func");
				HX_STACK_LINE(150)
				::String no = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(no,"no");
				HX_STACK_LINE(163)
				if (((no != null()))){
					HX_STACK_LINE(163)
					return ((HX_CSTRING("function ") + no) + this->printFunction(func));
				}
				else{
					HX_STACK_LINE(150)
					Dynamic func1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(func1,"func1");
					HX_STACK_LINE(164)
					return (HX_CSTRING("function ") + this->printFunction(func1));
				}
			}
			;break;
			case (int)10: {
				HX_STACK_LINE(150)
				Dynamic vl = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(vl,"vl");
				HX_STACK_LINE(165)
				return (HX_CSTRING("var ") + vl->__Field(HX_CSTRING("map"),true)(this->printVar_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", ")));
			}
			;break;
			case (int)12: {
				HX_STACK_LINE(150)
				Dynamic el = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(el,"el");
				HX_STACK_LINE(150)
				switch( (int)((::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0)->__Field(HX_CSTRING("length"),true))){
					case (int)0: {
						HX_STACK_LINE(166)
						return ((HX_CSTRING("{\n") + this->tabs) + HX_CSTRING("}"));
					}
					;break;
					default: {
						HX_STACK_LINE(168)
						::String old = this->tabs;		HX_STACK_VAR(old,"old");
						HX_STACK_LINE(169)
						hx::AddEq(this->tabs,this->tabString);
						HX_STACK_LINE(170)
						::String s = ((HX_CSTRING("{\n") + this->tabs) + this->printExprs(el,(HX_CSTRING(";\n") + this->tabs)));		HX_STACK_VAR(s,"s");
						HX_STACK_LINE(171)
						this->tabs = old;
						HX_STACK_LINE(172)
						return (s + (((HX_CSTRING(";\n") + this->tabs) + HX_CSTRING("}"))));
					}
				}
			}
			;break;
			case (int)13: {
				HX_STACK_LINE(150)
				Dynamic e2 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(e2,"e2");
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(173)
				return (((HX_CSTRING("for(") + this->printExpr(e1)) + HX_CSTRING(") ")) + this->printExpr(e2));
			}
			;break;
			case (int)14: {
				HX_STACK_LINE(150)
				Dynamic e2 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(e2,"e2");
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(174)
				return (((HX_CSTRING("") + this->printExpr(e1)) + HX_CSTRING(" in ")) + this->printExpr(e2));
			}
			;break;
			case (int)15: {
				HX_STACK_LINE(150)
				Dynamic eelse = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(2);		HX_STACK_VAR(eelse,"eelse");
				HX_STACK_LINE(150)
				Dynamic eif = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(eif,"eif");
				HX_STACK_LINE(150)
				Dynamic econd = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(econd,"econd");
				HX_STACK_LINE(175)
				return (((((HX_CSTRING("if(") + this->printExpr(econd)) + HX_CSTRING(") ")) + this->printExpr(eif)) + HX_CSTRING(" ")) + this->opt(eelse,this->printExpr_dyn(),HX_CSTRING("else ")));
			}
			;break;
			case (int)16: {
				HX_STACK_LINE(150)
				bool _switch_2 = ((::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(2));
				if (  ( _switch_2==true)){
					HX_STACK_LINE(150)
					Dynamic econd = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(econd,"econd");
					HX_STACK_LINE(150)
					Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(e1,"e1");
					HX_STACK_LINE(176)
					return (((HX_CSTRING("while(") + this->printExpr(econd)) + HX_CSTRING(") ")) + this->printExpr(e1));
				}
				else if (  ( _switch_2==false)){
					HX_STACK_LINE(150)
					Dynamic econd = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(econd,"econd");
					HX_STACK_LINE(150)
					Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(e1,"e1");
					HX_STACK_LINE(177)
					return ((((HX_CSTRING("do ") + this->printExpr(e1)) + HX_CSTRING(" while(")) + this->printExpr(econd)) + HX_CSTRING(")"));
				}
			}
			;break;
			case (int)17: {
				HX_STACK_LINE(150)
				Dynamic edef = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(2);		HX_STACK_VAR(edef,"edef");
				HX_STACK_LINE(150)
				Dynamic cl = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(cl,"cl");
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(178)
				{
					HX_STACK_LINE(179)
					::String old = this->tabs;		HX_STACK_VAR(old,"old");
					HX_STACK_LINE(180)
					hx::AddEq(this->tabs,this->tabString);

					HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_4_1,Array< ::Dynamic >,_g)
					::String run(Dynamic c){
						HX_STACK_PUSH("*::_Function_4_1","haxe/macro/Printer.hx",183);
						HX_STACK_ARG(c,"c");
						{
							HX_STACK_LINE(183)
							return (((HX_CSTRING("case ") + _g->__get((int)0).StaticCast< ::haxe::macro::Printer >()->printExprs(c->__Field(HX_CSTRING("values"),true),HX_CSTRING(", "))) + ((  (((c->__Field(HX_CSTRING("guard"),true) != null()))) ? ::String(((HX_CSTRING(" if(") + _g->__get((int)0).StaticCast< ::haxe::macro::Printer >()->printExpr(c->__Field(HX_CSTRING("guard"),true))) + HX_CSTRING("): "))) : ::String(HX_CSTRING(":")) ))) + ((  (((c->__Field(HX_CSTRING("expr"),true) != null()))) ? ::String((_g->__get((int)0).StaticCast< ::haxe::macro::Printer >()->opt(c->__Field(HX_CSTRING("expr"),true),_g->__get((int)0).StaticCast< ::haxe::macro::Printer >()->printExpr_dyn(),null()) + HX_CSTRING(";"))) : ::String(HX_CSTRING("")) )));
						}
						return null();
					}
					HX_END_LOCAL_FUNC1(return)

					HX_STACK_LINE(181)
					::String s = ((((HX_CSTRING("switch ") + this->printExpr(e1)) + HX_CSTRING(" {\n")) + this->tabs) + cl->__Field(HX_CSTRING("map"),true)( Dynamic(new _Function_4_1(_g)))->__Field(HX_CSTRING("join"),true)((HX_CSTRING("\n") + this->tabs)));		HX_STACK_VAR(s,"s");
					HX_STACK_LINE(187)
					if (((edef != null()))){
						HX_STACK_LINE(188)
						hx::AddEq(s,((((HX_CSTRING("\n") + this->tabs) + HX_CSTRING("default: ")) + ((  (((edef->__Field(HX_CSTRING("expr"),true) == null()))) ? ::String(HX_CSTRING("")) : ::String(this->printExpr(edef)) ))) + HX_CSTRING(";")));
					}
					HX_STACK_LINE(189)
					this->tabs = old;
					HX_STACK_LINE(190)
					return (s + (((HX_CSTRING("\n") + this->tabs) + HX_CSTRING("}"))));
				}
			}
			;break;
			case (int)18: {
				HX_STACK_LINE(150)
				Dynamic cl = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(cl,"cl");
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");

				HX_BEGIN_LOCAL_FUNC_S1(hx::LocalFunc,_Function_3_1,Array< ::Dynamic >,_g)
				::String run(Dynamic c){
					HX_STACK_PUSH("*::_Function_3_1","haxe/macro/Printer.hx",193);
					HX_STACK_ARG(c,"c");
					{
						HX_STACK_LINE(193)
						return (((((HX_CSTRING(" catch(") + c->__Field(HX_CSTRING("name"),true)) + HX_CSTRING(" : ")) + _g->__get((int)0).StaticCast< ::haxe::macro::Printer >()->printComplexType(c->__Field(HX_CSTRING("type"),true))) + HX_CSTRING(") ")) + _g->__get((int)0).StaticCast< ::haxe::macro::Printer >()->printExpr(c->__Field(HX_CSTRING("expr"),true)));
					}
					return null();
				}
				HX_END_LOCAL_FUNC1(return)

				HX_STACK_LINE(192)
				return ((HX_CSTRING("try ") + this->printExpr(e1)) + cl->__Field(HX_CSTRING("map"),true)( Dynamic(new _Function_3_1(_g)))->__Field(HX_CSTRING("join"),true)(HX_CSTRING("")));
			}
			;break;
			case (int)19: {
				HX_STACK_LINE(150)
				Dynamic eo = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(eo,"eo");
				HX_STACK_LINE(194)
				return (HX_CSTRING("return") + this->opt(eo,this->printExpr_dyn(),HX_CSTRING(" ")));
			}
			;break;
			case (int)20: {
				HX_STACK_LINE(195)
				return HX_CSTRING("break");
			}
			;break;
			case (int)21: {
				HX_STACK_LINE(196)
				return HX_CSTRING("continue");
			}
			;break;
			case (int)22: {
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(197)
				return (HX_CSTRING("untyped ") + this->printExpr(e1));
			}
			;break;
			case (int)23: {
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(198)
				return (HX_CSTRING("throw ") + this->printExpr(e1));
			}
			;break;
			case (int)24: {
				HX_STACK_LINE(150)
				::haxe::macro::ComplexType cto = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(cto,"cto");
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(199)
				if (((cto != null()))){
					HX_STACK_LINE(199)
					return ((((HX_CSTRING("cast(") + this->printExpr(e1)) + HX_CSTRING(", ")) + this->printComplexType(cto)) + HX_CSTRING(")"));
				}
				else{
					HX_STACK_LINE(150)
					Dynamic e11 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e11,"e11");
					HX_STACK_LINE(200)
					return (HX_CSTRING("cast ") + this->printExpr(e11));
				}
			}
			;break;
			case (int)25: {
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(201)
				return ((HX_CSTRING("#DISPLAY(") + this->printExpr(e1)) + HX_CSTRING(")"));
			}
			;break;
			case (int)26: {
				HX_STACK_LINE(150)
				Dynamic tp = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(tp,"tp");
				HX_STACK_LINE(202)
				return ((HX_CSTRING("#DISPLAY(") + this->printTypePath(tp)) + HX_CSTRING(")"));
			}
			;break;
			case (int)27: {
				HX_STACK_LINE(150)
				Dynamic eelse = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(2);		HX_STACK_VAR(eelse,"eelse");
				HX_STACK_LINE(150)
				Dynamic eif = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(eif,"eif");
				HX_STACK_LINE(150)
				Dynamic econd = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(econd,"econd");
				HX_STACK_LINE(203)
				return (((((HX_CSTRING("") + this->printExpr(econd)) + HX_CSTRING(" ? ")) + this->printExpr(eif)) + HX_CSTRING(" : ")) + this->printExpr(eelse));
			}
			;break;
			case (int)28: {
				HX_STACK_LINE(150)
				::haxe::macro::ComplexType ct = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(ct,"ct");
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(204)
				return ((((HX_CSTRING("#CHECK_TYPE(") + this->printExpr(e1)) + HX_CSTRING(", ")) + this->printComplexType(ct)) + HX_CSTRING(")"));
			}
			;break;
			case (int)29: {
				HX_STACK_LINE(150)
				Dynamic e1 = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(1);		HX_STACK_VAR(e1,"e1");
				HX_STACK_LINE(150)
				Dynamic meta = (::haxe::macro::ExprDef(e->__Field(HX_CSTRING("expr"),true)))->__Param(0);		HX_STACK_VAR(meta,"meta");
				HX_STACK_LINE(205)
				return ((this->printMetadata(meta) + HX_CSTRING(" ")) + this->printExpr(e1));
			}
			;break;
		}
	}
	HX_STACK_LINE(150)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printExpr,return )

::String Printer_obj::printVar( Dynamic v){
	HX_STACK_PUSH("Printer::printVar","haxe/macro/Printer.hx",145);
	HX_STACK_THIS(this);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(145)
	return ((v->__Field(HX_CSTRING("name"),true) + this->opt(v->__Field(HX_CSTRING("type"),true),this->printComplexType_dyn(),HX_CSTRING(" : "))) + this->opt(v->__Field(HX_CSTRING("expr"),true),this->printExpr_dyn(),HX_CSTRING(" = ")));
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printVar,return )

::String Printer_obj::printFunction( Dynamic func){
	HX_STACK_PUSH("Printer::printFunction","haxe/macro/Printer.hx",139);
	HX_STACK_THIS(this);
	HX_STACK_ARG(func,"func");
	HX_STACK_LINE(139)
	return (((((((  (((func->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("length"),true) > (int)0))) ? ::String(((HX_CSTRING("<") + func->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("map"),true)(this->printTypeParamDecl_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", "))) + HX_CSTRING(">"))) : ::String(HX_CSTRING("")) )) + HX_CSTRING("( ")) + func->__Field(HX_CSTRING("args"),true)->__Field(HX_CSTRING("map"),true)(this->printFunctionArg_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", "))) + HX_CSTRING(" )")) + this->opt(func->__Field(HX_CSTRING("ret"),true),this->printComplexType_dyn(),HX_CSTRING(" : "))) + this->opt(func->__Field(HX_CSTRING("expr"),true),this->printExpr_dyn(),HX_CSTRING(" ")));
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printFunction,return )

::String Printer_obj::printFunctionArg( Dynamic arg){
	HX_STACK_PUSH("Printer::printFunctionArg","haxe/macro/Printer.hx",133);
	HX_STACK_THIS(this);
	HX_STACK_ARG(arg,"arg");
	HX_STACK_LINE(133)
	return (((((  ((arg->__Field(HX_CSTRING("opt"),true))) ? ::String(HX_CSTRING("?")) : ::String(HX_CSTRING("")) )) + arg->__Field(HX_CSTRING("name"),true)) + this->opt(arg->__Field(HX_CSTRING("type"),true),this->printComplexType_dyn(),HX_CSTRING(" : "))) + this->opt(arg->__Field(HX_CSTRING("value"),true),this->printExpr_dyn(),HX_CSTRING(" = ")));
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printFunctionArg,return )

::String Printer_obj::printTypeParamDecl( Dynamic tpd){
	HX_STACK_PUSH("Printer::printTypeParamDecl","haxe/macro/Printer.hx",128);
	HX_STACK_THIS(this);
	HX_STACK_ARG(tpd,"tpd");
	HX_STACK_LINE(128)
	return ((tpd->__Field(HX_CSTRING("name"),true) + ((  (((bool((tpd->__Field(HX_CSTRING("params"),true) != null())) && bool((tpd->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("length"),true) > (int)0))))) ? ::String(((HX_CSTRING("<") + tpd->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("map"),true)(this->printTypeParamDecl_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", "))) + HX_CSTRING(">"))) : ::String(HX_CSTRING("")) ))) + ((  (((bool((tpd->__Field(HX_CSTRING("constraints"),true) != null())) && bool((tpd->__Field(HX_CSTRING("constraints"),true)->__Field(HX_CSTRING("length"),true) > (int)0))))) ? ::String(((HX_CSTRING(":(") + tpd->__Field(HX_CSTRING("constraints"),true)->__Field(HX_CSTRING("map"),true)(this->printComplexType_dyn()).StaticCast< Array< ::String > >()->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", "))) + HX_CSTRING(")"))) : ::String(HX_CSTRING("")) )));
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printTypeParamDecl,return )

::String Printer_obj::printField( Dynamic field){
	HX_STACK_PUSH("Printer::printField","haxe/macro/Printer.hx",118);
	HX_STACK_THIS(this);
	HX_STACK_ARG(field,"field");
	struct _Function_1_1{
		inline static ::String Block( ::haxe::macro::Printer_obj *__this,Dynamic &field){
			HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",121);
			{
				HX_STACK_LINE(121)
				switch( (int)(field->__Field(HX_CSTRING("kind"),true)->__Index())){
					case (int)0: {
						HX_STACK_LINE(121)
						Dynamic eo = (::haxe::macro::FieldType(field->__Field(HX_CSTRING("kind"),true)))->__Param(1);		HX_STACK_VAR(eo,"eo");
						HX_STACK_LINE(121)
						::haxe::macro::ComplexType t = (::haxe::macro::FieldType(field->__Field(HX_CSTRING("kind"),true)))->__Param(0);		HX_STACK_VAR(t,"t");
						HX_STACK_LINE(122)
						return (((HX_CSTRING("var ") + field->__Field(HX_CSTRING("name"),true)) + __this->opt(t,__this->printComplexType_dyn(),HX_CSTRING(" : "))) + __this->opt(eo,__this->printExpr_dyn(),HX_CSTRING(" = ")));
					}
					;break;
					case (int)2: {
						HX_STACK_LINE(121)
						Dynamic eo = (::haxe::macro::FieldType(field->__Field(HX_CSTRING("kind"),true)))->__Param(3);		HX_STACK_VAR(eo,"eo");
						HX_STACK_LINE(121)
						::haxe::macro::ComplexType t = (::haxe::macro::FieldType(field->__Field(HX_CSTRING("kind"),true)))->__Param(2);		HX_STACK_VAR(t,"t");
						HX_STACK_LINE(121)
						::String set = (::haxe::macro::FieldType(field->__Field(HX_CSTRING("kind"),true)))->__Param(1);		HX_STACK_VAR(set,"set");
						HX_STACK_LINE(121)
						::String get = (::haxe::macro::FieldType(field->__Field(HX_CSTRING("kind"),true)))->__Param(0);		HX_STACK_VAR(get,"get");
						HX_STACK_LINE(123)
						return ((((((((HX_CSTRING("var ") + field->__Field(HX_CSTRING("name"),true)) + HX_CSTRING("(")) + get) + HX_CSTRING(", ")) + set) + HX_CSTRING(")")) + __this->opt(t,__this->printComplexType_dyn(),HX_CSTRING(" : "))) + __this->opt(eo,__this->printExpr_dyn(),HX_CSTRING(" = ")));
					}
					;break;
					case (int)1: {
						HX_STACK_LINE(121)
						Dynamic func = (::haxe::macro::FieldType(field->__Field(HX_CSTRING("kind"),true)))->__Param(0);		HX_STACK_VAR(func,"func");
						HX_STACK_LINE(124)
						return ((HX_CSTRING("function ") + field->__Field(HX_CSTRING("name"),true)) + __this->printFunction(func));
					}
					;break;
				}
			}
			return null();
		}
	};
	HX_STACK_LINE(118)
	return (((((  (((bool((field->__Field(HX_CSTRING("doc"),true) != null())) && bool((field->__Field(HX_CSTRING("doc"),true) != HX_CSTRING("")))))) ? ::String((((((((HX_CSTRING("/**\n") + this->tabs) + this->tabString) + ::StringTools_obj::replace(field->__Field(HX_CSTRING("doc"),true),HX_CSTRING("\n"),((HX_CSTRING("\n") + this->tabs) + this->tabString))) + HX_CSTRING("\n")) + this->tabs) + HX_CSTRING("**/\n")) + this->tabs)) : ::String(HX_CSTRING("")) )) + ((  (((bool((field->__Field(HX_CSTRING("meta"),true) != null())) && bool((field->__Field(HX_CSTRING("meta"),true)->__Field(HX_CSTRING("length"),true) > (int)0))))) ? ::String((field->__Field(HX_CSTRING("meta"),true)->__Field(HX_CSTRING("map"),true)(this->printMetadata_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(" ")) + HX_CSTRING(" "))) : ::String(HX_CSTRING("")) ))) + ((  (((bool((field->__Field(HX_CSTRING("access"),true) != null())) && bool((field->__Field(HX_CSTRING("access"),true)->__Field(HX_CSTRING("length"),true) > (int)0))))) ? ::String((field->__Field(HX_CSTRING("access"),true)->__Field(HX_CSTRING("map"),true)(this->printAccess_dyn()).StaticCast< Array< ::String > >()->__Field(HX_CSTRING("join"),true)(HX_CSTRING(" ")) + HX_CSTRING(" "))) : ::String(HX_CSTRING("")) ))) + _Function_1_1::Block(this,field));
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printField,return )

::String Printer_obj::printAccess( ::haxe::macro::Access access){
	HX_STACK_PUSH("Printer::printAccess","haxe/macro/Printer.hx",107);
	HX_STACK_THIS(this);
	HX_STACK_ARG(access,"access");
	HX_STACK_LINE(107)
	switch( (int)(access->__Index())){
		case (int)2: {
			HX_STACK_LINE(108)
			return HX_CSTRING("static");
		}
		;break;
		case (int)0: {
			HX_STACK_LINE(109)
			return HX_CSTRING("public");
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(110)
			return HX_CSTRING("private");
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(111)
			return HX_CSTRING("override");
		}
		;break;
		case (int)5: {
			HX_STACK_LINE(112)
			return HX_CSTRING("inline");
		}
		;break;
		case (int)4: {
			HX_STACK_LINE(113)
			return HX_CSTRING("dynamic");
		}
		;break;
		case (int)6: {
			HX_STACK_LINE(114)
			return HX_CSTRING("macro");
		}
		;break;
	}
	HX_STACK_LINE(107)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printAccess,return )

::String Printer_obj::printMetadata( Dynamic meta){
	HX_STACK_PUSH("Printer::printMetadata","haxe/macro/Printer.hx",104);
	HX_STACK_THIS(this);
	HX_STACK_ARG(meta,"meta");
	HX_STACK_LINE(104)
	return ((HX_CSTRING("@") + meta->__Field(HX_CSTRING("name"),true)) + ((  (((meta->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("length"),true) > (int)0))) ? ::String(((HX_CSTRING("(") + this->printExprs(meta->__Field(HX_CSTRING("params"),true),HX_CSTRING(", "))) + HX_CSTRING(")"))) : ::String(HX_CSTRING("")) )));
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printMetadata,return )

::String Printer_obj::printComplexType( ::haxe::macro::ComplexType ct){
	HX_STACK_PUSH("Printer::printComplexType","haxe/macro/Printer.hx",94);
	HX_STACK_THIS(this);
	HX_STACK_ARG(ct,"ct");
	HX_STACK_LINE(94)
	switch( (int)(ct->__Index())){
		case (int)0: {
			HX_STACK_LINE(94)
			Dynamic tp = (::haxe::macro::ComplexType(ct))->__Param(0);		HX_STACK_VAR(tp,"tp");
			HX_STACK_LINE(95)
			return this->printTypePath(tp);
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(94)
			::haxe::macro::ComplexType ret = (::haxe::macro::ComplexType(ct))->__Param(1);		HX_STACK_VAR(ret,"ret");
			HX_STACK_LINE(94)
			Array< ::Dynamic > args = (::haxe::macro::ComplexType(ct))->__Param(0);		HX_STACK_VAR(args,"args");
			HX_STACK_LINE(96)
			return ((((  (((args->length > (int)0))) ? ::String(args->map(this->printComplexType_dyn()).StaticCast< Array< ::String > >()->join(HX_CSTRING(" -> "))) : ::String(HX_CSTRING("Void")) )) + HX_CSTRING(" -> ")) + this->printComplexType(ret));
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(94)
			Dynamic fields = (::haxe::macro::ComplexType(ct))->__Param(0);		HX_STACK_VAR(fields,"fields");
			struct _Function_2_1{
				inline static Array< ::String > Block( ::haxe::macro::Printer_obj *__this,Dynamic &fields){
					HX_STACK_PUSH("*::closure","haxe/macro/Printer.hx",97);
					{
						HX_STACK_LINE(97)
						Array< ::String > _g = Array_obj< ::String >::__new();		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(97)
						{
							HX_STACK_LINE(97)
							int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
							HX_STACK_LINE(97)
							while(((_g1 < fields->__Field(HX_CSTRING("length"),true)))){
								HX_STACK_LINE(97)
								Dynamic f = fields->__GetItem(_g1);		HX_STACK_VAR(f,"f");
								HX_STACK_LINE(97)
								++(_g1);
								HX_STACK_LINE(97)
								_g->push((__this->printField(f) + HX_CSTRING("; ")));
							}
						}
						HX_STACK_LINE(97)
						return _g;
					}
					return null();
				}
			};
			HX_STACK_LINE(97)
			return ((HX_CSTRING("{ ") + (_Function_2_1::Block(this,fields))->join(HX_CSTRING(""))) + HX_CSTRING("}"));
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(94)
			::haxe::macro::ComplexType ct1 = (::haxe::macro::ComplexType(ct))->__Param(0);		HX_STACK_VAR(ct1,"ct1");
			HX_STACK_LINE(98)
			return ((HX_CSTRING("(") + this->printComplexType(ct1)) + HX_CSTRING(")"));
		}
		;break;
		case (int)5: {
			HX_STACK_LINE(94)
			::haxe::macro::ComplexType ct1 = (::haxe::macro::ComplexType(ct))->__Param(0);		HX_STACK_VAR(ct1,"ct1");
			HX_STACK_LINE(99)
			return (HX_CSTRING("?") + this->printComplexType(ct1));
		}
		;break;
		case (int)4: {
			HX_STACK_LINE(94)
			Dynamic fields = (::haxe::macro::ComplexType(ct))->__Param(1);		HX_STACK_VAR(fields,"fields");
			HX_STACK_LINE(94)
			Dynamic tp = (::haxe::macro::ComplexType(ct))->__Param(0);		HX_STACK_VAR(tp,"tp");
			HX_STACK_LINE(100)
			return ((((HX_CSTRING("{") + this->printTypePath(tp)) + HX_CSTRING(" >, ")) + fields->__Field(HX_CSTRING("map"),true)(this->printField_dyn())->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", "))) + HX_CSTRING(" }"));
		}
		;break;
	}
	HX_STACK_LINE(94)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printComplexType,return )

::String Printer_obj::printTypePath( Dynamic tp){
	HX_STACK_PUSH("Printer::printTypePath","haxe/macro/Printer.hx",88);
	HX_STACK_THIS(this);
	HX_STACK_ARG(tp,"tp");
	HX_STACK_LINE(88)
	return (((((  (((tp->__Field(HX_CSTRING("pack"),true)->__Field(HX_CSTRING("length"),true) > (int)0))) ? ::String((tp->__Field(HX_CSTRING("pack"),true)->__Field(HX_CSTRING("join"),true)(HX_CSTRING(".")) + HX_CSTRING("."))) : ::String(HX_CSTRING("")) )) + tp->__Field(HX_CSTRING("name"),true)) + ((  (((tp->__Field(HX_CSTRING("sub"),true) != null()))) ? ::String((HX_CSTRING(".") + tp->__Field(HX_CSTRING("sub"),true))) : ::String(HX_CSTRING("")) ))) + ((  (((tp->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("length"),true) > (int)0))) ? ::String(((HX_CSTRING("<") + tp->__Field(HX_CSTRING("params"),true)->__Field(HX_CSTRING("map"),true)(this->printTypeParam_dyn()).StaticCast< Array< ::String > >()->__Field(HX_CSTRING("join"),true)(HX_CSTRING(", "))) + HX_CSTRING(">"))) : ::String(HX_CSTRING("")) )));
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printTypePath,return )

::String Printer_obj::printTypeParam( ::haxe::macro::TypeParam param){
	HX_STACK_PUSH("Printer::printTypeParam","haxe/macro/Printer.hx",82);
	HX_STACK_THIS(this);
	HX_STACK_ARG(param,"param");
	HX_STACK_LINE(82)
	switch( (int)(param->__Index())){
		case (int)0: {
			HX_STACK_LINE(82)
			::haxe::macro::ComplexType ct = (::haxe::macro::TypeParam(param))->__Param(0);		HX_STACK_VAR(ct,"ct");
			HX_STACK_LINE(83)
			return this->printComplexType(ct);
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(82)
			Dynamic e = (::haxe::macro::TypeParam(param))->__Param(0);		HX_STACK_VAR(e,"e");
			HX_STACK_LINE(84)
			return this->printExpr(e);
		}
		;break;
	}
	HX_STACK_LINE(82)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printTypeParam,return )

::String Printer_obj::printConstant( ::haxe::macro::Constant c){
	HX_STACK_PUSH("Printer::printConstant","haxe/macro/Printer.hx",73);
	HX_STACK_THIS(this);
	HX_STACK_ARG(c,"c");
	HX_STACK_LINE(73)
	switch( (int)(c->__Index())){
		case (int)2: {
			HX_STACK_LINE(73)
			::String s = (::haxe::macro::Constant(c))->__Param(0);		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(74)
			return ((HX_CSTRING("\"") + s) + HX_CSTRING("\""));
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(73)
			::String s = (::haxe::macro::Constant(c))->__Param(0);		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(78)
			return s;
		}
		;break;
		case (int)0: {
			HX_STACK_LINE(73)
			::String s = (::haxe::macro::Constant(c))->__Param(0);		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(78)
			return s;
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(73)
			::String s = (::haxe::macro::Constant(c))->__Param(0);		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(78)
			return s;
		}
		;break;
		case (int)4: {
			HX_STACK_LINE(73)
			::String opt = (::haxe::macro::Constant(c))->__Param(1);		HX_STACK_VAR(opt,"opt");
			HX_STACK_LINE(73)
			::String s = (::haxe::macro::Constant(c))->__Param(0);		HX_STACK_VAR(s,"s");
			HX_STACK_LINE(79)
			return (((HX_CSTRING("~/") + s) + HX_CSTRING("/")) + opt);
		}
		;break;
	}
	HX_STACK_LINE(73)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printConstant,return )

::String Printer_obj::printBinop( ::haxe::macro::Binop op){
	HX_STACK_PUSH("Printer::printBinop","haxe/macro/Printer.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_ARG(op,"op");
	HX_STACK_LINE(45)
	switch( (int)(op->__Index())){
		case (int)0: {
			HX_STACK_LINE(46)
			return HX_CSTRING("+");
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(47)
			return HX_CSTRING("*");
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(48)
			return HX_CSTRING("/");
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(49)
			return HX_CSTRING("-");
		}
		;break;
		case (int)4: {
			HX_STACK_LINE(50)
			return HX_CSTRING("=");
		}
		;break;
		case (int)5: {
			HX_STACK_LINE(51)
			return HX_CSTRING("==");
		}
		;break;
		case (int)6: {
			HX_STACK_LINE(52)
			return HX_CSTRING("!=");
		}
		;break;
		case (int)7: {
			HX_STACK_LINE(53)
			return HX_CSTRING(">");
		}
		;break;
		case (int)8: {
			HX_STACK_LINE(54)
			return HX_CSTRING(">=");
		}
		;break;
		case (int)9: {
			HX_STACK_LINE(55)
			return HX_CSTRING("<");
		}
		;break;
		case (int)10: {
			HX_STACK_LINE(56)
			return HX_CSTRING("<=");
		}
		;break;
		case (int)11: {
			HX_STACK_LINE(57)
			return HX_CSTRING("&");
		}
		;break;
		case (int)12: {
			HX_STACK_LINE(58)
			return HX_CSTRING("|");
		}
		;break;
		case (int)13: {
			HX_STACK_LINE(59)
			return HX_CSTRING("^");
		}
		;break;
		case (int)14: {
			HX_STACK_LINE(60)
			return HX_CSTRING("&&");
		}
		;break;
		case (int)15: {
			HX_STACK_LINE(61)
			return HX_CSTRING("||");
		}
		;break;
		case (int)16: {
			HX_STACK_LINE(62)
			return HX_CSTRING("<<");
		}
		;break;
		case (int)17: {
			HX_STACK_LINE(63)
			return HX_CSTRING(">>");
		}
		;break;
		case (int)18: {
			HX_STACK_LINE(64)
			return HX_CSTRING(">>>");
		}
		;break;
		case (int)19: {
			HX_STACK_LINE(65)
			return HX_CSTRING("%");
		}
		;break;
		case (int)21: {
			HX_STACK_LINE(66)
			return HX_CSTRING("...");
		}
		;break;
		case (int)22: {
			HX_STACK_LINE(67)
			return HX_CSTRING("=>");
		}
		;break;
		case (int)20: {
			HX_STACK_LINE(45)
			::haxe::macro::Binop op1 = (::haxe::macro::Binop(op))->__Param(0);		HX_STACK_VAR(op1,"op1");
			HX_STACK_LINE(69)
			return (this->printBinop(op1) + HX_CSTRING("="));
		}
		;break;
	}
	HX_STACK_LINE(45)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printBinop,return )

::String Printer_obj::printUnop( ::haxe::macro::Unop op){
	HX_STACK_PUSH("Printer::printUnop","haxe/macro/Printer.hx",37);
	HX_STACK_THIS(this);
	HX_STACK_ARG(op,"op");
	HX_STACK_LINE(37)
	switch( (int)(op->__Index())){
		case (int)0: {
			HX_STACK_LINE(38)
			return HX_CSTRING("++");
		}
		;break;
		case (int)1: {
			HX_STACK_LINE(39)
			return HX_CSTRING("--");
		}
		;break;
		case (int)2: {
			HX_STACK_LINE(40)
			return HX_CSTRING("!");
		}
		;break;
		case (int)3: {
			HX_STACK_LINE(41)
			return HX_CSTRING("-");
		}
		;break;
		case (int)4: {
			HX_STACK_LINE(42)
			return HX_CSTRING("~");
		}
		;break;
	}
	HX_STACK_LINE(37)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Printer_obj,printUnop,return )


Printer_obj::Printer_obj()
{
}

void Printer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Printer);
	HX_MARK_MEMBER_NAME(tabString,"tabString");
	HX_MARK_MEMBER_NAME(tabs,"tabs");
	HX_MARK_END_CLASS();
}

void Printer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(tabString,"tabString");
	HX_VISIT_MEMBER_NAME(tabs,"tabs");
}

Dynamic Printer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"opt") ) { return opt_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"tabs") ) { return tabs; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"printVar") ) { return printVar_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"printExpr") ) { return printExpr_dyn(); }
		if (HX_FIELD_EQ(inName,"printUnop") ) { return printUnop_dyn(); }
		if (HX_FIELD_EQ(inName,"tabString") ) { return tabString; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"printExprs") ) { return printExprs_dyn(); }
		if (HX_FIELD_EQ(inName,"printField") ) { return printField_dyn(); }
		if (HX_FIELD_EQ(inName,"printBinop") ) { return printBinop_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"printAccess") ) { return printAccess_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"printFunction") ) { return printFunction_dyn(); }
		if (HX_FIELD_EQ(inName,"printMetadata") ) { return printMetadata_dyn(); }
		if (HX_FIELD_EQ(inName,"printTypePath") ) { return printTypePath_dyn(); }
		if (HX_FIELD_EQ(inName,"printConstant") ) { return printConstant_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"printTypeParam") ) { return printTypeParam_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"printFunctionArg") ) { return printFunctionArg_dyn(); }
		if (HX_FIELD_EQ(inName,"printComplexType") ) { return printComplexType_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"printTypeParamDecl") ) { return printTypeParamDecl_dyn(); }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"printTypeDefinition") ) { return printTypeDefinition_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Printer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"tabs") ) { tabs=inValue.Cast< ::String >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tabString") ) { tabString=inValue.Cast< ::String >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Printer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("tabString"));
	outFields->push(HX_CSTRING("tabs"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("opt"),
	HX_CSTRING("printTypeDefinition"),
	HX_CSTRING("printExprs"),
	HX_CSTRING("printExpr"),
	HX_CSTRING("printVar"),
	HX_CSTRING("printFunction"),
	HX_CSTRING("printFunctionArg"),
	HX_CSTRING("printTypeParamDecl"),
	HX_CSTRING("printField"),
	HX_CSTRING("printAccess"),
	HX_CSTRING("printMetadata"),
	HX_CSTRING("printComplexType"),
	HX_CSTRING("printTypePath"),
	HX_CSTRING("printTypeParam"),
	HX_CSTRING("printConstant"),
	HX_CSTRING("printBinop"),
	HX_CSTRING("printUnop"),
	HX_CSTRING("tabString"),
	HX_CSTRING("tabs"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Printer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Printer_obj::__mClass,"__mClass");
};

Class Printer_obj::__mClass;

void Printer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.macro.Printer"), hx::TCanCast< Printer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Printer_obj::__boot()
{
}

} // end namespace haxe
} // end namespace macro
