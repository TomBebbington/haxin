class PointerS<T> {
	public var v:T;
	public function new(d:T) {
		v = d;
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
	@:to inline function to():T {
		return this.v;
	}
	public inline function free():Void {
		this.v = null;
	}
}