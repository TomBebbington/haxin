all: build run
build:
	clang++ -emit-llvm -O4 `llvm-config --cxxflags` -o run.bc -c src/Haxinator.cpp
	clang++ -emit-llvm -O4 -o tests/hello.bc -c tests/hello.cpp
	clang++ -emit-llvm -O4 -S -o tests/hello.ir -c tests/hello.cpp
	lli run.bc tests/hello.bc tests/Hello.hx
	lli run.bc run.bc Haxinator.hx
run: