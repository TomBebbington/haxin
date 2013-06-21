all: build-tests build run
check:
	cppcheck src/ --enable=all -I /usr/include/llvm-3.4/
build-tests:
	clang++ -emit-llvm -O4 -c tests/hello.cpp -o tests/hello.bc
	clang++ -emit-llvm -O4 -S -c tests/hello.cpp -o tests/hello.ll
build:
	clang++ -emit-llvm -O4 -I /usr/include/llvm-3.4/ `llvm-config-3.4 --cxxflags` -o run.bc -c src/Haxin.cpp
run:
	rm tests/haxe/*.hx
	lli-3.4 run.bc tests/hello.bc tests/haxe/Hello.hx