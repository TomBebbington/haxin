@:ident("tests/hello.bc")
class Hello {
	static var heap = new Map<Int, Dynamic>();
	static inline var _str:Null<String> = String;
	static function puts(a0:Null<Int>): Int { // extern
	}
	static function _main(): Int {
		var cast210:Null<Int> = _str.a.a;
		puts(cast210)
		return 0;
	}
	public static function main() {
		
	}
	
}
