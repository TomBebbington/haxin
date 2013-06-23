class Hello {
	static var heap:Map<Int, Dynamic> = [0 => null];
	static inline var _str:String = String;
	static function _main(): Int {
		
		var str:Int = new haxin.Pointer(_str);
		var call:Int = printf(str);
		return 1;
	}
	public static function main() {
		_main();
	}
	
}
