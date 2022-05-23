#include<stdio.h>
#include"BHE.h"
#include"GEN.h"

int main(int args, char* arg[]) {
	int choice, size, num;
	Heap heap;
	init_heap(&heap, MAX_RAND);

	if(args != 2) {
		printf("Specify The File Name To Continue ..!!");
		return 1;
	}

	generate_random_data(arg[1], MAX_RAND);
	print_data(arg[1]);
	
	build_heap(&heap, arg[1]);

	return 0;
}

/*
	while(1) {
		printf("1.Insert\n");
		printf("2.Delete\n");
		printf("3.Heap sort\n");
		printf("4.Inorder\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				printf("Enter size of the heap: ");
				scanf("%d", &size);
				init_heap(&heap, size);
				break;
			case 2:
				printf("Enter the number to insert: ");
				scanf("%d", &num);
				insert_heap(&heap, num);
				break;
			case 3:
				delete_heap(&heap);
			case 4:
				heap_sort(&heap);
			case 5:
				traverse(heap);
			case 6:
				exit(0);
		}
	}
*/

