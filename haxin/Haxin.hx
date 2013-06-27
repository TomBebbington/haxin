package haxin;
import sys.FileSystem;
import sys.io.*;
class Haxin {
	public static var args = new Args(Sys.args());
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
				else OS.Distro.Other("???");
				OS.Linux(dist);
			default: null;
		};
		switch(args.args) {
			case ["setup"]: switch(os) {
				case Linux(Debian(is_ubuntu)):
					setupLinuxShortcut();
				case all: 
					Sys.println('Sorry, it looks like your $all system cannot be automatically set up');
			}
			case ["build", s]: sys.io.File.saveContent(args.vals.exists("o") ? args.vals.get("o") : StringTools.replace(s, ".bc", ".hx"), new HaxeGen(s).toString());
			case ["help"]:
				Sys.println("Haxin LLVM-to-Haxe compiler");
		}
	}
	static inline function error(msg:String) {
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