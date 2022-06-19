#include<stdio.h>
#include<limits.h>
#include"graph.h"
#include"queue.h"
#include"stack.h"
#include"edges.h"

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
	int* visited = calloc(g.n, sizeof(int));
	Stack stack;
	init_stack(&stack, g.n * g.n);

	push(&stack, start);
	visited[start] = 1;

	printf("\n");
	while(!isEmptyStack(&stack)) {
		int ele = pop(&stack);
		printf("%d ", ele);
		for(int i=0; i<g.n; i++) {
			if(g.matrix[ele][i] && !visited[i]) {
				push(&stack, i);
				visited[i] = 1;
			}
		}
	}	
}

void breath_first_search(Graph g, int start) {
	int* visited = calloc(g.n, sizeof(int));
	Queue queue;
	init_queue(&queue, g.n * g.n);

	enqueue(&queue, start);
	visited[start] = 1;

	printf("\n%d ", start);
	while(!isEmptyQueue(&queue)) {
		int ele = dequeue(&queue);
		for(int i=0; i<g.n; i++) {
			if(g.matrix[ele][i] && !visited[i]) {
				enqueue(&queue, i);
				visited[i] = 1;
				printf("%d ", i);
			}
		}
	}
}

void _DFS(Graph g, int* visited, int start) {
	Stack stack;
	init_stack(&stack, g.n * g.n);
	push(&stack, start);
	visited[start] = 1;
	while(!isEmptyStack(&stack)) {
		int ele = pop(&stack);
		printf("%d ", ele);
		for(int i = 0; i < g.n; i++) {
			if(g.matrix[ele][i] && !visited[i]) {
				push(&stack, i);
				visited[i] = 1;
			}
		}
	}
	printf("\n");
}

void get_components_of_graph(Graph g) {
	int* visited = calloc(g.n, sizeof(int));
	int components = 0;
	for(int i = 0; i < g.n; i++) {
		if(!visited[i]) {
			_DFS(g, visited, i);
			components++;
		}
	}
	printf("Components Of Graph is : %d \n", components);
}

void prims(Graph g) {
	int* visited = calloc(g.n, sizeof(int));
	int mv = INT_MAX, me = INT_MAX;

	visited[0] = 1;
	printf(" %d", 0);

	for(int k = 0; k < g.n - 1; k++) {
		mv = INT_MAX, me = INT_MAX;
		for(int i = 0; i < g.n - 1; i++) {
			int mv_for_node = INT_MAX, me_for_node = INT_MAX;
			if(visited[i]) {
				for(int j = 0; j < g.n; j++) {
					if(me_for_node > g.matrix[i][j] && g.matrix[i][j] != 0 && !visited[j]) {
						me_for_node = g.matrix[i][j];
						mv_for_node = j;
					}
				}
				if(me > me_for_node) {
					me = me_for_node;
					mv = mv_for_node;
				}
			}
		}
		visited[mv] = 1;
		printf(" %d", mv);
	}
}

int findParent(int* parent_set, int node) {
	if(parent_set[node] == node)
		return node;
	return findParent(parent_set, parent_set[node]);
}

// Works For Undirected Graph
void krushkals(Graph graph) {
	Edges* edges = malloc(graph.n * sizeof(Edges));
	int c = 0;
	for(int i = 0; i < graph.n; i++) {
		for(int j = 0; j < graph.n; j++) {
			if(i < j && graph.matrix[i][j] != 0) {
				Edges* edge = malloc(sizeof(Edges));
				edge->src = i;
				edge->dest = j;
				edge->weight = graph.matrix[i][j];
				
				edges[c] = *edge;
				
				c++;
			}
		}
	}
	for(int i = 0; i < c; i++) {		
		for(int j = i + 1; j < c; j++) {
			if(edges[i].weight > edges[j].weight) {
				Edges tmp = edges[i];
				edges[i] = edges[j];
				edges[j] = tmp;
			}
		}
	}
	

	// Initialize the set to its own value
	int* parent_set = malloc(sizeof(int) * graph.n);
	for(int i = 0; i < graph.n; i++) {		
		parent_set[i] = i;
	}	
	
	int count = 0;
	int i = 0;
	while(count != graph.n - 1) {
		Edges edge = edges[i];
		
		int srcParent = findParent(parent_set, edge.src);
		int destParent = findParent(parent_set, edge.dest);
		
		if(srcParent != destParent) {
			printf("\n\nSRC : %d, DEST : %d, WEIGHT : %d,", edges[i].src, edges[i].dest, edges[i].weight);
			parent_set[destParent] = srcParent;
			count++;
		}
		i++;
	}
}

int minDistance(Graph graph, int dist[], int sptSet[]) {
	int min = INT_MAX, min_index;

	for (int v = 0; v < graph.n; v++)
		if (sptSet[v] == 0 && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}

	return min_index;
}
 
void printSolution(Graph graph, int dist[]) {
	printf("Vertex \t\t Distance from Source\n");
	for (int i = 0; i < graph.n; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}
 
void dijkstra(Graph graph, int src) {
	int distance[graph.n];
	int sptSet[graph.n];

	for (int i = 0; i < graph.n; i++) {
		distance[i] = INT_MAX;
		sptSet[i] = 0;
	}
	distance[src] = 0;

	for (int count = 0; count < graph.n - 1; count++) {
		int u = minDistance(graph, dist, sptSet);

		sptSet[u] = 1;
		for (int v = 0; v < graph.n; v++)
			if (!sptSet[v] && graph.matrix[u][v] && distance[u] != INT_MAX && distance[u] + graph.matrix[u][v] < distance[v])
				distance[v] = distance[u] + graph.matrix[u][v];
	}
	printSolution(graph, distance);
}

