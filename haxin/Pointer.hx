package haxin;

class PointerS<T> implements haxe.rtti.Generic {
	public var addr:Int;
	public var v:T;
	public function new(d:T) {
		v = d;
		addr = 0;
	}
}
abstract Pointer<T>(PointerS<T>) {
	public inline function new() {
		this = new PointerS(null);
	}
	public inline function set(v:T) {
		this.v = v;
	}
	@:from static inline function from(v:T):Pointer<T> {
		return cast new PointerS(v);
	}
	@:to public inline function get():Int {
		return this.v;
	}
	@:to public inline function addr():T {
		return this.addr;
	}
	public inline function free():Void {
		this.v = null;
	}
}