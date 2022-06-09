#include<stdio.h>
#include <stdlib.h>

void insert(int* array, int data, int position, int size, int last) {
	if(position > size - 1) {
		return;
	}
	
	if(last == -1) {
		array[0] = data;;
		return;
	}

	for(int i = last; i > position; i--) {
		array[i+1] = array[i];
	}
	array[position] = data;
}

void traverse(int* array, int size) {
	int i;
	for(i=0; i<size; i++) {
		printf("\n %d", array[i]);
	}
}

int main() {
	int s = 10;
	int* array = malloc(sizeof(int) * s);

	insert(array, 10, 0, s, -1);
	insert(array, 20, 1, s, 0);
	insert(array, 30, 2, s, 1);
	insert(array, 40, 0, s, 2);

	traverse(array, s);
	
	return 0;
}

