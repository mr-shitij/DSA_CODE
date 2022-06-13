#include<stdio.h>
#include "graph.h"

int main(int argc,char* argv[]){
    graph g;
    initgraph(&g,argv[1]);
    printf("printing graph\n");
    printgraph(&g);
    printf("\n");
    printf("Call for dfs\n");
    DFS(&g,2);
    printf("\n");
    printf("Call for bfs\n");
    BFS(&g,2);
    printf("\n");
    Degree(&g);
    edge* edges=Kruskal(&g);
    printf("\nMinimum Spanning Tree is\n");
    for(int i=0;i<g.vertex-1;i++)
        printf("%d-->%d = %d\n",edges[i].s,edges[i].d,edges[i].w);
    int path=Dijkstras(&g,3,0);
    printf("\n%d ",path);

    return 0;
}