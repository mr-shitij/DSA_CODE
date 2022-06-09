#include "list.h"

typedef struct GraphNode {
	int data;
	struct List *list;
	struct GraphNode *next;
} GraphNode;
typedef GraphNode *Graph;

void init_graph(Graph *g, char* fileName);
void print(Graph g);

int get_indegree(Graph g, int node);
int get_outdegree(Graph g, int node);
void BFS(Graph g, int node);

