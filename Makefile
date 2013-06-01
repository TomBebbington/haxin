all: build run
build:
	clang++ -emit-llvm -O4 `llvm-config --cxxflags` -o run.bc -c src/Haxinator.cpp
	clang++ -emit-llvm -O4 -o tests/hello.bc -c tests/hello.cpp
	lli run.bc run.bc Haxinator.hx
	lli run.bc tests/hello.bc Hello.hx
run: