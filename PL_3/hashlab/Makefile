all: hash
	mkdir -p build
	mkdir -p build/objects
	mkdir -p build/bin
	mv *.o build/objects
	mv hashlab build/bin
	
hash: main.o hash_set.o linked_list.o
	g++ -g main.o hash_set.o linked_list.o -o hashlab

main.o: src/main.cpp
	g++ -c -g -Wall -I lib src/main.cpp 

hash_set.o: lib/hash_set.cpp
	g++ -c -g -Wall -I lib lib/hash_set.cpp 

linked_list.o: lib/linked_list.cpp
	g++ -c -g -Wall -I lib lib/linked_list.cpp 

clean:
	rm -r build