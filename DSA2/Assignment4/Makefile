CC=gcc
TARGET=main 

all: try run
try: main.o AVL.o
	$(CC) main.o AVL.o -o $(TARGET)
main.o: main.c AVL.h
	$(CC) -c main.c
AVL.o: AVL.c AVL.h
	$(CC) -c AVL.c
run: $(TARGET)
	./main
clean:
	rm -rvf *.o $(TARGET)

