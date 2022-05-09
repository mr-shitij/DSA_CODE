CC=gcc
TARGET=main 

all: try run
try: main.o BHE.o
	$(CC) main.o BHE.o -o $(TARGET)
main.o: main.c BHE.h
	$(CC) -c main.c
AVL.o: BHE.c BHE.h
	$(CC) -c BHE.c
run: $(TARGET)
	./$(TARGET)
clean:
	rm -rvf *.o $(TARGET)

