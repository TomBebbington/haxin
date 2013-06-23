string genID(uint x) {
	if(x < 26)
		return string(1, char('a' + x));
	else if(x < 52)
		return string(1, char('A' + x - 26));
	else {
		const uint avail = 52;
		string s;
		while (x > 0) {
			s = genID(x % avail) + s;
			x /= avail;
		}
		return s;
	}
}
int getConstantInt(const ConstantInt* ci) {
	return ci -> getValue().getLimitedValue();
}
string getDir(string file) {
	uint found = file.find_last_of("/");
	if(found == -1)
		return "";
	else
		return file.substr(0, found+1);
}

bool endsWith (string const &fullString, string const &ending) {
	if (fullString.length() >= ending.length())
		return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
	else
		return false;
}
string toUpper(string s) {
	string ns = s;
	std::transform(ns.begin(), ns.end(), ns.begin(), ::toupper);
	return ns;
}

string haxeFilter(string n, bool camel) {
	const string notAllowed[] = {".", "/", "+", "_", "-"};
	const int num_notAllowed = 4;
	for(int i=0;i<num_notAllowed;i++) {
		const string c = notAllowed[i];
		int found = (int) n.find(c);
		uint count = 0;
		while(found != -1 && count++ < 500) {
			if(camel)
				n.replace(found, c.length()+1, toUpper(n.substr(found+1, 1)));
			else
				n.replace(found, c.length(), "_");
			found = (int) n.find(c);
		}
	}
	if(n == "main")
		n = "_main";
	return n;
}
string toHaxeName(string n) {
	//string o = n;
	const size_t found_dot = n.find(".");
	if(found_dot != -1)
		n = n.substr(found_dot + 1);
	const string slash = "/";
	const size_t found = n.find_last_of(slash);
	if(found != 0 && found < n.length() && found != string::npos)
		n = n.substr(found);
	n = haxeFilter(n, true);
	const string sep = "::";
	int last = -1;
	while(true) {
		int f = (int) n.find(sep);
		if(f == -1)
			break;
		else {
			n = n.replace(f, sep.length()+1, "." + toUpper(n.substr(f + sep.length(), 1)));
			last = f;
		}
	}
	if(last >= 0 && n.length() > last + 1)
		n.replace(last, 1, toUpper(n.substr(last, 1)));
	return n;
}
string replaceAll(string s, const string from, const string to) {
	size_t off = 0;
	while(off < s.length() && off != string::npos) {
		size_t first = s.find_first_of(from, off);
		if(first == string::npos)
			break;
		s.replace(first, from.length(), to);
		off = first + to.length();
	}
	return s;
}
const string encodeString(string s) {
	const string quote = "\"";
	s = replaceAll(s, "\"", "\\\"");
	s = replaceAll(s, "\n", "\\n");
	s = replaceAll(s, "\t", "\\t");
	s = replaceAll(s, "\r", "\\r");
	return quote + s + quote;
}

string getDefaultValue(const Type *t) {
	if(t -> isVoidTy())
		return "null";
	else if(const IntegerType *i = dyn_cast<const IntegerType>(t)) {
		uint w = i -> getBitWidth();
		if(w <= 32)
			return "0";
		else
			return "haxe.Int64.ofInt(0)";
	} else if(t -> isFloatingPointTy())
		return "0.0";
	else if(const FunctionType *f = dyn_cast<const FunctionType>(t)) {
		string s = "function(";
		for(int i=0;i<f -> getNumParams();i++) {
			if(i != 0)
				s += ", ";
			s += genID(i) + ":" + getDefaultValue(f -> getParamType(i));
		}
		s += ") return " + getDefaultValue(f -> getReturnType());
		return s;
	} else if(const ArrayType *a = dyn_cast<const ArrayType>(t)) {
		Type* t = a -> getElementType();
		if(t -> isIntegerTy(8))
			return "\"\"";
		else
			return "[]";
	} else if(t -> isStructTy() && t -> getStructNumElements() == 1)
		return getDefaultValue(t -> getStructElementType(0));
	else if(t -> isStructTy()) {
		return "null";
	} else
		return "null";
}