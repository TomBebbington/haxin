package haxin;
using sys.FileSystem;
using StringTools;
using Lambda;
using sys.io.File;
import sys.io.*;
class Haxin {
	@:keep public static var args:Args = new Args(Sys.args());
	public static var opts:Int = 0;
	public static var os:OS;
	static function main() {
		os = switch(Sys.systemName()) {
			case "Windows": OS.Windows;
			case "BSD": OS.BSD;
			case "Mac": OS.Mac;
			case "Linux":
				var dist = if(FileSystem.exists("/etc/debian_version")) {
					var cont = File.getContent("/etc/lsb-release").toLowerCase();
					OS.Distro.Debian(cont.indexOf("ubuntu") != -1 || cont.indexOf("linux mint") != -1);
				}
				else if(FileSystem.exists("/etc/redhat-release")) OS.Distro.RedHat;
				else if(FileSystem.exists("/usr/bin/pacman")) OS.Distro.Arch;
				else OS.Distro.Other("???");
				OS.Linux(dist);
			default: null;
		};
		opts = if(args.flags.has("O1")) 1
		else if(args.flags.has("O2")) 2
		else if(args.flags.has("O3")) 3
		else if(args.flags.has("O4")) 4
		else 0;
		switch(args.args) {
			case ["setup"]: switch(os) {
				case Linux(_):
					setupLinuxShortcut();
				case all: 
					Sys.println('Sorry, it looks like your $all system cannot be automatically set up');
			}
			case ["build", s]:
				var file = args.vals.exists("o") ? args.vals.get("o") : s.replace(".bc", ".hx");
				file.saveContent(new HaxeGen(s).toString());
			case ["cc", s]:
				var file = s.replace(".cpp", ".bc").replace(".c", ".bc");
				clangTo(file, s.indexOf(".cpp") != -1);
				file.saveContent(new HaxeGen(file).toString());
			case ["help"] | _:
				Sys.println("Haxin, a LLVM bitcode to Haxe compiler");
		}
	}
	static function clangTo(p:String, cpp:Bool) {
		var cargs = args.args;
		cargs = cargs.slice(1);
		var cmd = cpp ? "clang++" : "clang";
		cmd += " -emit-llvm";
		cmd += ' -o $p';
		cmd += ' -O${opts}';
		cmd += " "+[for(a in cargs) '-c $a'].join(" ");
		Sys.println(cmd);
		Sys.command(cmd);
	}
	public static inline function error(msg:String) {
		Sys.stderr().writeString(msg + "\n");
		Sys.exit(9);
	}
	static inline function setupLinuxShortcut() {
		try {
			File.saveContent("/usr/bin/haxin", "#! /bin/bash\nhaxelib run haxin $@");
			Sys.command("sudo chmod 557 /usr/bin/haxin");
		} catch(e:Dynamic) error("Couldn't open /usr/bin/haxin - did you forget to run this as sudo?");
	}
}