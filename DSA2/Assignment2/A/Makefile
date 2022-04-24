CC=gcc
TARGET=main 

all: main.o BST.o run
	$(CC) main.c BST.c -o $(TARGET)

clean:
	rm -rvf *.o $(TARGET)

run: main
	./main
