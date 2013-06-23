llvm::raw_ostream & operator << (llvm::raw_ostream & out, HaxePath & a) {
    return out << a.toHaxe();
}
HaxePath::HaxePath(const string path) {
	const string fpath = toHaxeName(path);
	packs = new vector<string>();
	std::stringstream ss(fpath);
    std::string item;
    while (std::getline(ss, item, '.')) {
        packs -> push_back(item);
    }
	name = packs -> back();
	packs -> pop_back();
}
string HaxePath::toHaxe() {
	std::stringstream ss;
	vector<string>::iterator first = packs -> begin();
	for(vector<string>::iterator it = first; it != packs -> end(); it++)
		ss << *it << ".";
	ss << name;
	return ss.str();
}
string HaxePath::toPath() {
	std::stringstream ss;
	vector<string>::iterator first = packs -> begin();
	for(vector<string>::iterator it = first; it != packs -> end(); it++)
		ss << *it << "/";
	ss << name << ".hx";
	return ss.str();
}