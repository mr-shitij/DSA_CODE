CC=gcc
TARGET=main 

all: try run
try: main.o BST.o
	$(CC) main.o BST.o -o $(TARGET)
main.o: main.c BST.h
	$(CC) -c main.c
BST.o: BST.c
	$(CC) -c BST.c
run: $(TARGET)
	./main
clean:
	rm -rvf *.o $(TARGET)

