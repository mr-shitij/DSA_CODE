#include<stdio.h>
#include"graph.h"

int main() {
	Graph g;
	init_graph(&g, "data.txt");
	print(g);
	breath_first_search(g, 0);
	depth_first_search(g, 0);
	get_components_of_graph(g);
	printf("Prims : \n");
	prims(g);
	printf("\n\nkrushkals : \n\n");
	krushkals(g);
	printf("\n\dijkstra : \n\n");
	dijkstra(g, 0);
	return 0;
}

