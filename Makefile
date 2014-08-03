.phony:
	all

all: 
	make dirs
	make build

clean:
	rm -rf bin
	rm -rf build

dirs:
	mkdir -p bin
	mkdir -p build
	mkdir -p lib

build:
	echo "Building ..."
	cd build
	cmake ../
	make
	cd ..

test:
	echo "This is test ..."
