package haxin;
import haxe.io.Bytes;
abstract Pointer<T>(Int) from Int to Int {
	public static inline var LEAP = Bytes.alloc(256);
	public static var heap = Bytes.alloc(LEAP);
	public inline function new(v:T) {
		this = 0;
		heap.set(this, v);
	}
	public inline function set(v:T) {
		this.v = v;
	}
	@:from static inline function from(v:T):Pointer<T> {
		return cast new PointerS(v);
	}
	@:to public inline function addr():Int {
		return this.v;
	}
	public inline function free():Void {
	}
}