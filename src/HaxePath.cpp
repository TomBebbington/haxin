raw_ostream & operator << (raw_ostream & out, HaxePath & a) {
    return out << a.toHaxe();
}
HaxePath::HaxePath(const string path) {
	const string fpath = toHaxeName(path);
	packs = new vector<string>();
	stringstream ss(fpath);
    string item;
    while (getline(ss, item, '.')) {
        packs -> push_back(item);
    }
	name = packs -> back();
	packs -> pop_back();
}
string HaxePath::toHaxe() {
	stringstream ss;
	vector<string>::iterator first = packs -> begin();
	for(vector<string>::iterator it = first; it != packs -> end(); it++)
		ss << *it << ".";
	ss << name;
	return ss.str();
}
string HaxePath::toPath() {
	stringstream ss;
	vector<string>::iterator first = packs -> begin();
	for(vector<string>::iterator it = first; it != packs -> end(); it++)
		ss << *it << "/";
	ss << name << ".hx";
	return ss.str();
}