#include<stdio.h>
#include"graph.h"

int main() {
	Graph g;
	init_graph(&g, "data.txt");
	print(g);
	return 0;
}

