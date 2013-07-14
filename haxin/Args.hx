package haxin;
using Lambda;
class Args {
	static var REGEX_ARGS(default, null) = ~/-([a-zA-Z0-9-]*) ([^- ][^ ]*)/;
	static var REGEX_FLAGS(default, null) = ~/-([a-zA-Z0-9-]*)/;
	public var vals(default, null):Map<String, String>;
	public var flags(default, null):Array<String>;
	public var args(default, null):Array<String>;
	public function new(ovals:Array<String>) {
		if(sys.FileSystem.exists(ovals[ovals.length-1]) && sys.FileSystem.isDirectory(ovals[ovals.length-1]))
			Sys.setCwd(ovals.pop());
		var avals = ovals.join(" ");
		vals = new Map<String, String>();
		for(arg in matches(avals, REGEX_ARGS, 2))
			vals.set(arg[0], arg[1]);
		while(REGEX_ARGS.match(avals))
			avals = REGEX_ARGS.replace(avals, "");
		flags = [for(m in matches(avals, REGEX_FLAGS, 1)) m[0]];
		while(REGEX_FLAGS.match(avals))
			avals = REGEX_FLAGS.replace(avals, "");
		args = [for(v in avals.split(" ")) if(v.length > 0) v];
	}
	static function matches(s:String, r:EReg, ms:Int):Array<Array<String>> {
		var a = [];
		var pos = 0;
		while(r.matchSub(s, pos)) {
			var cpos = r.matchedPos();
			var ma = [];
			for(i in 0...ms+1)
				ma[i] = r.matched(i);
			ma = ma.slice(1);
			a.push(ma);
			pos = cpos.pos + cpos.len;
		}
		return a;
	}
	public function toString() {
		var a = args == null ? [] : args.copy();
		if(flags != null)
			a = a.concat([for(f in flags) '-$f']);
		if(vals != null)
			a = a.concat([for(v in vals.keys()) '-$v ${vals.get(v)}']);
		return a.join(" ");
	}
	public inline function has(id:String):Bool {
		return flags.indexOf(id) != -1;
	}
	public inline function get(id:String, ?def:String):String {
		return vals.exists(id) ? vals.get(id) : def;
	}
}