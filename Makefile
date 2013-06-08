all: build run
build:
	clang++ -emit-llvm -O4 `llvm-config-3.4 --cxxflags` -o run.bc -c src/Haxinator.cpp -I/usr/include/llvm-3.4/ -isystem /usr/include/llvm-3.4/
	clang++ -emit-llvm -O4 -o tests/hello.bc -c tests/hello.cpp
	clang++ -emit-llvm -O4 -S -o tests/hello.ir -c tests/hello.cpp
	lli run.bc tests/hello.bc tests/Hello.hx
run: