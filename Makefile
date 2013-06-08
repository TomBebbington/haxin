all: build run
build:
	cppcheck src/ --enable=all -I /usr/include/llvm
	clang++ -emit-llvm -O4 `llvm-config --cxxflags` -o run.bc -c src/Haxinator.cpp
	clang++ -emit-llvm -O4 -o tests/hello.bc -c tests/hello.cpp
	clang++ -emit-llvm -O4 -S -o tests/hello.ir -c tests/hello.cpp
	lli tests/hello.bc
	lli run.bc tests/hello.bc
run: