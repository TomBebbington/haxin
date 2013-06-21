enum OS {
	Linux(d:Distro);
	Windows;
	Mac;
	BSD;
}

enum Distro {
	Debian;
	RedHat;
	Other(name:String);
}