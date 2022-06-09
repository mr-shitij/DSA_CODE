CC=gcc
TARGET=main 

all: try run
try: main.o graph.o
	$(CC) main.o queue.o graph.o -o $(TARGET)
main.o: main.c graph.h
	$(CC) -c main.c
graph.o: graph.h graph.c
	$(CC) -c graph.c 
queue.o: queue.h queue.c
	$(CC) -c queue.c 
run: $(TARGET)
	./$(TARGET) data
clean:
	rm -rvf *.o $(TARGET)

