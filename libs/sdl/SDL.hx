import haxe.macro.*;
#if(!flash && !openfl)
	#error "OpenFL or Flash is required for SDL to work!"
#else
typedef Surface = #if js Dynamic #else flash.display.BitmapData #end;
class SDL {
	static inline var DEFAULT_ERROR = "No error";
	static var error:String = DEFAULT_ERROR;
	static var initTime:Float;
	public static var cur:Surface = null;
	public static macro function SDL_Init(flags:Int):Expr.ExprOf<Int> {
		var xml = Xml.createElement("project");
		var lib = Xml.createElement("haxelib");
		lib.set("name", "openfl");
		xml.addChild(lib);
		sys.io.File.saveContent("project.xml", xml.toString());
		initTime = haxe.Timer.stamp();
		return Context.makeExpr(0, Context.currentPos());
	}
	public static inline function SDL_InitSubSystem(flags:Int):Int {
		return 0;
	}
	public static inline function SDL_QuitSubSystem(flags:Int):Int {
		return 0;
	}
	public static inline function SDL_Quit():Void {
		#if sys
			Sys.exit(0);
		#end
	}
	public static inline function SDL_GetError() {
		return error;
	}
	public static inline function SDL_SetError(e:String) {
		error = e;
	}
	public static inline function SDL_ClearError() {
		error = DEFAULT_ERROR;
	}
	public static inline function SDL_WasInit(flags:Int):Int {
		return 0xFFFFFF;
	}
	public static macro function SDL_WM_SetCaption(title:String, icons:String):Expr {
		var xml = Xml.parse(sys.io.File.getContent("project.xml"));
		var meta = xml.elementsNamed("meta").next();
		if(meta == null)
			meta = Xml.createElement("meta");
		if(title != null && title.length > 0)
			meta.set("title", title);
		xml.firstElement().addChild(meta);
		var icon = xml.elementsNamed("icon").next();
		if(icon == null) {
			var icon = Xml.createElement("icon");
			xml.firstElement().addChild(icon);
		}
		if(icons != null && icons.length > 0)
			icon.set("name", icons);
		sys.io.File.saveContent("project.xml", xml.toString());
		return macro null;
	}
	public static macro function SDL_WM_GetCaption(title:Pointer<String>, icon:Pointer<String>):Void {
		var xml = Xml.parse(sys.io.File.getContent("project.xml"));
		var meta = xml.elementsNamed("meta").next();
		if(meta != null)
			title.set(meta.get("title"));
		if(meta != null)
			icon.set(meta.get("title"));
	}
	public static inline function SDL_WM_SetIcon(icon:Surface, mask:Int) {

	}
	public static inline function SDL_WM_IconifyWindow():Int {
		return 0;
	}
	#if !macro
	public static inline function SDL_WM_ToggleFullscreen(s:Surface) {
		var stage = flash.Lib.current.stage;
		stage.displayState = stage.displayState == flash.display.StageDisplayState.NORMAL ? flash.display.StageDisplayState.FULL_SCREEN : flash.display.StageDisplayState.NORMAL;
	}
	public static inline function SDL_VideoDriverName(namebuf:Pointer<String>, maxlen:Int) {
		var s = #if java "java" #elseif js "html5" #elseif sys "sys" #elseif flash "flash" #else "???" #end;
		if(s.length > maxlen)
			s = s.substr(0, maxlen);
		namebuf.set(s);
	}
	#end
	public static macro function SDL_SetVideoMode(width:Int, height:Int, bpp:Int, flags:Int):Expr.ExprOf<Surface> {
		var xml = Xml.parse(sys.io.File.getContent("project.xml"));
		if(!xml.elementsNamed("window").hasNext()) {
			var wind = Xml.createElement("window");
			wind.set("width", Std.string(width));
			wind.set("height", Std.string(height));
			xml.firstElement().addChild(wind);
			sys.io.File.saveContent("project.xml", xml.toString());
		}
		var ewidth = Context.makeExpr(width, Context.currentPos()), eheight = Context.makeExpr(height, Context.currentPos());
		return macro SDL.cur = new flash.display.BitmapData(${ewidth}, ${eheight}, true);
	}
	public static macro function SDL_LoadBMP(file:String):Expr {
		var filee = Context.makeExpr(file, Context.currentPos());
		var xml = Xml.parse(sys.io.File.getContent("project.xml"));
		var has = false;
		for(a in xml.elementsNamed("assets"))
			if(a.get("path") == file) {
				has = true;
				break;
			}
		if(!has) {
			var e = Xml.createElement("assets");
			e.set("path", file);
			e.set("type", "image");
			xml.firstElement().addChild(e);
			sys.io.File.saveContent("project.xml", xml.toString());
		}
		return macro openfl.Assets.getBitmapData($filee);
	}
	#if sys
	public static macro function SDL_SaveBMP(s:Expr.ExprOf<Surface>, f:Expr.ExprOf<String>):Expr.ExprOf<Int> {
		Compiler.define("lib", "format");
		var xml = Xml.parse(sys.io.File.getContent("project.xml"));
		var done = false;
		for(l in xml.elementsNamed("haxelib"))
			if(l.get("name") == "format") {
				done = true;
				break;
			}
		if(!done) {
			var lib = Xml.createElement("haxelib");
			lib.set("name", "format");
			xml.firstElement().addChild(lib);
		}
		sys.io.File.saveContent("project.xml", xml.toString());
		return macro {
			new format.bmp.Writer(sys.io.File.write($f, true)).write(format.bmp.Tools.fromBitmapData($s));
			1;
		};
	}
	#elseif js
	public static inline function SDL_SaveBMP(s:Surface, f:String):Int {
		js.Browser.window.open(untyped s._nmeTextureBuffer.toDataURL());
	}
	#end
	public static inline function SDL_Flip():Void {}
	public static inline function SDL_GetTicks():Int {
		return Std.int((haxe.Timer.stamp() - initTime) * 1000);
	}
	public static inline function SDL_Delay(ms:Int):Void {
		#if sys
			Sys.sleep(Std.int(ms / 1000));
		#end
	}
	public static inline function SDL_GetVideoInfo() {
		return {
			hw_available: true,
			wm_available: false,
			blit_hw: true,
			blit_hw_CC: true,
			blit_hw_A: true,
			blit_sw: true,
			blit_sw_CC: true,
			blit_sw_A: true,
			blit_fill: true,
			video_mem: 16384,
			vfmt: 0
		};
	}
	public static inline function SDL_GetVideoSurface():Pointer<Surface> {
		return cur;
	}
}
#end