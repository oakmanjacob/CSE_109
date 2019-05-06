all: networking
	mkdir build
	mkdir build/objects
	mkdir build/bin
	mv networking build/bin
	
networking:
	g++ -g -I include src/main.cpp -o networking

clean:
	rm -r build