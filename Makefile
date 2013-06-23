all: build-tests build run
check:
	cppcheck src/ --enable=all -I /usr/include/llvm-3.4/
build-tests:
	clang++ -emit-llvm -O4 -S -c tests/hello.cpp -o tests/hello.ll
	llvm-as-3.4 tests/hello.ll -o tests/hello.bc
build:
	clang++ -emit-llvm -O4 -I /usr/include/llvm-3.4/ `llvm-config-3.4 --cxxflags` -o bin/run.bc -c src/Haxin.cpp
run:
	lli-3.4 bin/run.bc tests/hello.bc tests/haxe/Hello.hx