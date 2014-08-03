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

test:
	echo "This is test ..."
	
HelloWorld: src/HelloWorld/Main.cpp
	g++ -o bin/HelloWorld src/HelloWorld/Main.cpp
