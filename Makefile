.phony:
	all

all: 
	make bin
	make build
	make HelloWorld

bin:
	mkdir -p bin

build:
	echo "Building ..."

HelloWorld: src/HelloWorld/Main.cpp
	g++ -o bin/HelloWorld src/HelloWorld/Main.cpp
