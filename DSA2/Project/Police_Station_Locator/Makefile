CC=gcc
TARGET=main 

all: try run
try: main.o KD.o
	$(CC) main.o KD.o -o $(TARGET)
main.o: main.c KD.h
	$(CC) -c main.c
KD.o: KD.c
	$(CC) -c KD.c
run: $(TARGET)
	./main
clean:
	rm -rvf *.o $(TARGET)

