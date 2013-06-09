all: build-tests build run
check:
	cppcheck src/ --enable=all -I /usr/include/llvm-3.4/
build-tests:
	clang++ -emit-llvm -O4 -o tests/hello.bc -c tests/hello.cpp
	clang++ -emit-llvm -O4 -S -o tests/hello.ll -c tests/hello.cpp
build:
	clang++ -emit-llvm -O4 -I /usr/include/llvm-3.4/ `llvm-config-3.4 --cxxflags` -o run.bc -c src/Haxinator.cpp
run:
	lli-3.4 run.bc tests/hello.bc tests/Hello.hx