#include<stdio.h>
#include"graph.h"
#include"queue.h"

void init_graph(Graph *g, char* fileName) {
	FILE *fp;
	fp = fopen(fileName, "r");
	if(fp == NULL) {
		printf("\n unable to open file ..!!");
		return;
	}
	
	fscanf(fp, "%d\n", &(g->n));
	for(int i=0; i<g->n; i++) {
		for(int j=0; j<g->n; j++) {
			fscanf(fp, "%d", &(g->matrix[i][j]));
		}
	}
	return;
}

void print(Graph g) {
	for(int i=0; i<g.n; i++) {
		for(int j=0; j<g.n; j++) {
			printf("%d ", g.matrix[i][j]);
		}
		printf("\n");
	}	
}

int graph_in_degree(Graph g, int v) {
	int degree = 0;
	for(int i=0; i<g.n; i++) {
		if(g.matrix[i][v])
			degree++;
	}
	return degree;
}

int graph_out_degree(Graph g, int v) {
	int degree = 0;
	for(int i=0; i<g.n; i++) {
		if(g.matrix[v][i])
			degree++;
	}
	return degree;
}

int isDirected(Graph g) {
	for(int i=0; i<g.n; i++) {
		for(int j=0; j<g.n; j++) {
			if(g.matrix[i][j] != g.matrix[j][i]) {
				return 1;
			}
		}
	}
	return 0;
}

void depth_first_search(Graph g, int start) {
	
}

void breath_first_search(Graph g, int start) {
	int* visited = calloc(g.n, sizeof(int));
	Queue queue;
	init_queue(&queue, g.n);
	enqueue(&queue, start);
	
	visited[start] = 1;
	printf("\n%d ", start);
	while(!isEmpty(&queue)) {
		int ele = dequeue(&queue);
		for(int i=0; i<g.n; i++) {
			if(g.matrix[ele][i] && !visited[i]) {
				printf("%d ", i);
				visited[i] = 1;
				enqueue(&queue, i);
			}
		}
	}
}
