@:ident("tests/hello.bc")
@:target("x86_64-pc-linux-gnu")
class Hello {
	static var _ZStL8__ioinit:std.IosBase.Init = [std.IosBase.Init] /*CDS*/;
	static var __dso_handle:Int = [Int] /*CDS*/;
	static var _ZSt4cout:std.BasicOstream = [std.BasicOstream] /*CDS*/;
	static inline var _str:String = [String] /*CDS*/;
	static var llvm_global_ctors:haxe.ds.Vector<{a: Int, b: Void -> Void}> = [haxe.ds.Vector<{a: Int, b: Void -> Void}>] /*CDS*/;
	static function _ZNSt8ios_base4InitC1Ev(a0:std.IosBase.Init): Void {
	}
	static function _ZNSt8ios_base4InitD1Ev(a0:std.IosBase.Init): Void {
	}
	static function __cxa_atexit(a0:Int -> Void, a1:Int, a2:Int): Int { // extern
	}
	static function _main(): Int {
		_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(_ZSt4cout, _str.a.a, 13)
		return 0;
	}
	static function _ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l(a0:std.BasicOstream, a1:Int, a2:Int): std.BasicOstream { // extern
	}
	static function _GLOBAL__I_a(): Void {
		_ZNSt8ios_base4InitC1Ev(_ZStL8__ioinit)
		__cxa_atexit(cast _ZNSt8ios_base4InitD1Ev, _ZStL8__ioinit.a.a, __dso_handle)
		return;
	}
	public static function main() {
		var inits = [haxe.ds.Vector<{a: Int, b: Void -> Void}>] /*CDS*/;
		for(i in inits)
			null;
	}
	
}
