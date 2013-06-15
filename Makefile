all: build-tests build run
check:
	cppcheck src/ --enable=all -I /usr/include/llvm-3.4/
build-tests:
	llvm-as-3.4 tests/hello.ll -o tests/hello.bc
build:
	clang++ -emit-llvm -O4 -I /usr/include/llvm-3.4/ `llvm-config-3.4 --cxxflags` -o run.bc -c src/Haxinator.cpp
run:
	lli-3.4 run.bc tests/hello.bc tests/Hello.hx