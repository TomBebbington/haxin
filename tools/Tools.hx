import sys.FileSystem;
class Tools {
	public static var args = new Args(Sys.args());
	public static var os:OS;
	static function main() {
		os = switch(Sys.systemName()) {
			case "Windows": OS.Windows;
			case "BSD": OS.BSD;
			case "Mac": OS.Mac;
			case "Linux":
				var dist = if(FileSystem.exists("/etc/debian_version")) OS.Distro.Debian;
				else if(FileSystem.exists("/etc/redhat-release")) OS.Distro.RedHat;
				else OS.Distro.Other("???");
				OS.Linux(dist);
			default: null;
		};
		switch(args.args) {
			case ["setup"]: switch(os) {
				case Linux(Debian):
					var sources = sys.io.File.getContent("/etc/apt/sources.list");
					if(sources.indexOf("llvm.org/apt/wheezy/") == -1) {
						sources += "\ndeb http://llvm.org/apt/wheezy/ lvm-toolchain-wheezy main\ndeb-src http://llvm.org/apt/wheezy/ llvm-toolchain-wheezy main";
						try sys.io.File.saveContent("/etc/apt/sources.list", sources) catch(e:Dynamic) error("Couldn't open sources.list - did you forget to run this as sudo?");
						if(Sys.command("sudo apt-get update") != 0)
							error("Could not update repositories!");
					}
					Sys.println("Installing dependencies...");
					switch(Sys.command("sudo apt-get install llvm-3.4 clang-3.4 clang++-3.4")) {
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
}