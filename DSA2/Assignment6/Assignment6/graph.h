#ifndef __graph__
#define __graph__

#include "linkedlist.h"

typedef struct graph{
  ll** graph;
  int vertex;
} graph;

typedef struct edge{
  int s,d,w;
}edge;

void initgraph(graph* g,char* filename);
void printgraph(graph* g);

void DFS(graph *g,int s);
void BFS(graph *g,int s);
void Degree(graph* g);
edge* Kruskal(graph* g);
int Dijkstras(graph*g,int s,int e);

#endif

