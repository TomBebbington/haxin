package haxin;
enum OS {
	Linux(d:Distro);
	Windows;
	Mac;
	BSD;
}

enum Distro {
	Debian(is_ubuntu:Bool);
	RedHat;
	Arch;
	Other(name:String);
}