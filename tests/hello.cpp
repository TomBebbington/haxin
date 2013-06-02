#include <iostream>
#include <algorithm>
#include <sstream>

int main() {
	int anum = 6;
	for(int i=0;i<anum;i++) {
		std::string s;
		switch(i) {
			case 0: s = "Hey!"; break;
			case 1: s = "Hey, listen!"; break;
			case 2: s = "Hey, look!"; break;
			default: s = "Heywut!"; break;
		}
		std::cout << s;
	}
	return 0;
}