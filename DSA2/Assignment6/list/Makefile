CC=gcc
TARGET=main

all: try run
try: main.o graph.o list.o stack.o queue.o
main.o: main.c graph.h list.h stack.h queue.h stack.h
	$(CC) -c main.c
graph.o: graph.h graph.c
	$(CC) -c graph.c 
list.o: list.h list.c
	$(CC) -c list.c 
stack.o: stack.h stack.c
	$(CC) -c stack.c
queue.o: queue.h queue.c
	$(CC) -c queue.c
run: $(TARGET)
	./$(TARGET)
clean:
	rm -rvf *.o $(TARGET)

