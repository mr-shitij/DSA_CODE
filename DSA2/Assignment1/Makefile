CC=gcc
TARGET=main 

all: run main.o Stack.o BST.o
	$(CC)  main.c BST.c Stack.c -o $(TARGET)

clean:
	rm -rvf *.o $(TARGET)

run:
	./main
