package haxin;
import haxe.macro.*;
import haxe.macro.Expr;
import haxe.macro.Type;
using haxe.macro.ExprTools;
using haxe.macro.TypeTools;
using haxe.macro.ComplexTypeTools;
import llvm.ir.*;
import llvm.support.*;
import llvm.*;
import llvm.support.MemoryBuffer;
using StringTools;
class HaxeGen {
	var ctx:Context;
	public var fields:Array<Field>;
	public var name:String;
	public var path:String;
	public var pos:Position;
	public function new(path:String) {
		this.path = path;
		pos = {min: 0, max: 0, file: path};
		name = toHaxeName(path);
		fields = [];
		fields.push({
			name: "main",
			kind: FFun({
				ret: macro:Void,
				params: [],
				args: [],
				expr: macro trace("Hello, world!")
			}),
			pos: pos,
			access: [APublic, AStatic]
		});
		ctx = new Context();
		trace(ctx);
		if(!sys.FileSystem.exists(path))
			Haxin.error('"$path" does not exist');
		var i = sys.io.File.read(path);
		i.bigEndian = true;
		if(i.readInt32() != 0x4243c0de)
			throw "Invalid magic number";
		i.close();
		Sys.println('Parsing bitcode file at "$path"');
		var m = Module.parseBitcodeFile(path, ctx);
		Sys.println('Parsed module: ${m.toString()}');
	}
	public function toHaxeType(t:llvm.ir.Type):ComplexType {
		t.dump();
		return macro:Dynamic;
	}
	public function toString():String {
        var td:TypeDefinition = {
            pos: pos,
            params: [],
            pack: [],
            name: name,
            meta: [],
            kind: TypeDefKind.TDClass(),
            isExtern: false,
            fields: fields
        };
        return new Printer().printTypeDefinition(td);
	}
	static function haxeFilter(n:String, camel:Bool=true) {
		var notAllowed = "./+_-";
		for(i in 0...notAllowed.length) {
			var c = notAllowed.charAt(i);
			var found = 0;
			var count = 0;
			while((found = n.indexOf(c)) != -1 && count++ < 500) {
				if(camel)
					n = n.substr(0, found) + n.substr(found+1, 1) + n.substr(c.length+1);
				else
					n = n.substr(0, found) + "_" + n.substr(c.length);
			}
		}
		if(n == "main")
			n = '_$n';
		return n;
	}
	static function toHaxeName(n:String) {
		if(n.endsWith(".bc")) n = n.substr(0, n.length-3);
		n = n.substr(n.indexOf(".") + 1);
		n = n.substr(n.lastIndexOf("/") + 1);
		n = haxeFilter(n, true);
		var parts:Array<String> = n.split("::");
		var last = parts[parts.length -1];
		parts[parts.length - 1] = last.charAt(0).toUpperCase() + last.substr(1);
		n = parts.join(".");
		return n;
	}
}