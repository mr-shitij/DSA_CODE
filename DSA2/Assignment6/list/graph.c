#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"
#include "stack.h"

GraphNode* insertNodeInGraph(Graph *g, int connection);
void addConnectionToNode(GraphNode* insertedNode, int node_id, int weight);

GraphNode* getNewGraphNode() {
	GraphNode* graphNode = malloc(sizeof(GraphNode*));
	if(graphNode == NULL) {
		printf("\n ERROR IN MEMORY ALLOCATION ..!!");
		return NULL;
	}
	graphNode->list = NULL;
	graphNode->next = NULL;
	return graphNode;
}

void init_graph(Graph *g, char* fileName) {
	(*g)->next = NULL; 
	(*g)->list = NULL;

	FILE *fp;
	fp = fopen(fileName, "r");
	if(fp == NULL) {
		printf("\n unable to open file ..!!");
		return;
	}
	
	int n;	
	fscanf(fp, "%d\n", &n);
	for(int i=0; i < n; i++) {
		GraphNode* insertedNode = insertNodeInGraph(g, i);
		for(int j=0; j < n; j++) {
			int weight = 0;
			fscanf(fp, "%d", &weight);
			if(weight != 0) {
				addConnectionToNode(insertedNode, j, weight);
			}
		}
	}
	return;
}

void addConnectionToNode(GraphNode* insertedNode, int node_id, int weight) {
	insertAtFirst(&(insertedNode->list), node_id, weight);
}

GraphNode* insertNodeInGraph(Graph *g, int data) {
	GraphNode* newNode = getNewGraphNode();
	newNode->data = data;
	if(g == NULL) {
		*g = newNode;
		return NULL;
	}
	
	GraphNode* start = *g;
	while(start->next != NULL) {
		start = start->next;
	}
	start->next = newNode;
	return newNode;
}

void print(Graph g) {
	GraphNode* start = g;
	while(start != NULL) {
		List list = start->list;
		traverse(list);
		start = start->next;
		printf("\n");
	}
}

int get_indegree(Graph g, int node) {
	int in = 0;
	GraphNode* start = g;
	while(start != NULL) {
		if(is_contains(start->list, node)) {
			in++;
		}
		start = start->next;
	}
	return in;
}

int get_outdegree(Graph g, int node) {
	int out = 0;
	GraphNode* start = g;
	while(start != NULL) {
		if(start->data == node) {
			break;
		}
		start = start->next;
	}
	return get_size_list(start->list);
}

int get_number_of_nodes(Graph g) {
	int nodes = 0;
	GraphNode* start = g;
	while(start != NULL) {
		nodes++;
		start = start->next;
	}
	return nodes;
}

void BFS(Graph g, int node) {
	int i = 0;
	int nodes_number = get_number_of_nodes(g);
	int* visited = calloc(sizeof(int), nodes_number);
	QueueList queue;
	
	initQueue(&queue);	
	enqueue(&queue, g->data);

	while(!isEmptyQueue(queue)) {
		int data = queue->data;
		

		if(!visited[data]) {
			visited[data] = 1;
			printf("%d\n", data);
			dequeue(&queue);
		}

		// add all the adjecent vertices..
		int temp = data;
		GraphNode* start = g;
		while(temp != 0) {
			start = start->next;
			temp--;
		}
		
		printf("\n NODE : %d", start->data);
		List *list = start->list;
		while(*list != NULL) {
			enqueue(&queue, (*list)->node_id);
			*list = (*list)->next;
		}
	}	
	return;
}

void DFS() {
	
	return;
}


