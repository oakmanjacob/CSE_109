CC=g++
CFLAGS=-c -Wall -I include
BUILD_PATH=./build
BUILD_BIN_PATH=$(BUILD_PATH)/bin
BUILD_OBJ_PATH=$(BUILD_PATH)/objects

all: directories hello

directories:
	mkdir $(BUILD_PATH)
	mkdir $(BUILD_BIN_PATH)
	mkdir $(BUILD_OBJ_PATH)

hello: main.o factorial.o hello.o
	$(CC) $(BUILD_OBJ_PATH)/main.o $(BUILD_OBJ_PATH)/factorial.o $(BUILD_OBJ_PATH)/hello.o -o $(BUILD_BIN_PATH)/hello

main.o: src/main.cpp
	$(CC) $(CFLAGS) src/main.cpp -o $(BUILD_OBJ_PATH)/main.o

factorial.o: src/factorial.cpp
	$(CC) $(CFLAGS) src/factorial.cpp -o $(BUILD_OBJ_PATH)/factorial.o

hello.o: src/hello.cpp
	$(CC) $(CFLAGS) src/hello.cpp -o $(BUILD_OBJ_PATH)/hello.o

clean:
	rm -r build