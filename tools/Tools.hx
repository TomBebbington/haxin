import sys.FileSystem;
import sys.io.*;
class Tools {
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
					var sources = File.getContent("/etc/apt/sources.list");
					var version = is_ubuntu ? "raring" : File.getContent("/etc/debian_version").split("/")[0];
					if(sources.indexOf('llvm.org/apt/$version/') == -1) {
						sources += '\ndeb http://llvm.org/apt/$version/ llvm-toolchain-$version main\ndeb-src http://llvm.org/apt/$version/ llvm-toolchain-$version main';
						try sys.io.File.saveContent("/etc/apt/sources.list", sources) catch(e:Dynamic) error("Couldn't open sources.list - did you forget to run this as sudo?");
						if(Sys.command("sudo apt-get update") != 0)
							error("Could not update repositories!");
					}
					Sys.println("Installing dependencies...");
					switch(Sys.command("sudo apt-get install llvm-3.4 clang-3.4 libclang-common-3.4-dev libclang-3.4-dev libclang1-3.4 libclang1-3.4-dbg libllvm-3.4-ocaml-dev libllvm3.4 libllvm3.4-dbg lldb-3.4 llvm-3.4 llvm-3.4-dev llvm-3.4-doc llvm-3.4-examples llvm-3.4-runtime cpp11-migrate-3.4 clang-format-3.4
")) {
						case 0: Sys.println("Dependencies installed.");
						default: error("Dependency installation failed!");
					}
				case all: 
					Sys.println('Sorry, it looks like your $all system cannot be automatically set up');
			}
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