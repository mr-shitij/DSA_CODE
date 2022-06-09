#include <stdio.h>
#include "graph.h"


int main() {
	Graph h;
	init_graph(&h, "data.txt");
	print(h);
	
	printf("\nOut Degree :  %d", get_outdegree(h, 4));
	printf("\IN Degree :  %d", get_indegree(h, 4));

	BFS(h, 4);

	return 0;
}

