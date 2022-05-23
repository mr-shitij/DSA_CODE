CC=gcc
TARGET=main 

all: try run
try: main.o GEN.o BHE.o
	$(CC) main.o GEN.o BHE.o -o $(TARGET)
main.o: main.c BHE.h GEN.h
	$(CC) -c main.c
GEN.o: GEN.h GEN.c
	$(CC) -c GEN.c
BHE.o: BHE.h BHE.c
	$(CC) -c BHE.c
run: $(TARGET)
	./$(TARGET) data
clean:
	rm -rvf *.o $(TARGET)

