CC=gcc
TARGET=main

all: try run
try: main.o fileOperations.o
main.o: main.c fileOperations.h
	$(CC) -c main.c
fileOperations.o: fileOperations.h fileOperations.c
	$(CC) -c fileOperations.c 
run: $(TARGET)
	./$(TARGET)
clean:
	rm -rvf *.o $(TARGET)

