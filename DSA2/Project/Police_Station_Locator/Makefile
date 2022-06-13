CC=gcc
TARGET=main 

all: try
try: main.o KD.o randomGenrator.o
	$(CC) main.o KD.o randomGenrator.o -o $(TARGET)
main.o: main.c KD.h randomGenrator.h
	$(CC) -c main.c
KD.o: KD.c
	$(CC) -c KD.c
randomGenrator.o: randomGenrator.c
	$(CC) -c randomGenrator.c
run: $(TARGET)
	./main
clean:
	rm -rvf *.o $(TARGET)

