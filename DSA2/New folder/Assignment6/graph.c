#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include "graph.h"
#include "queue.h"
#include "heap.h"


#define min(a,b) (a)<(b)?(a):(b)

void initgraph(graph* g,char* filename){
    FILE *fp = fopen(filename, "r");
    if (!fp){
        printf("An error occurred\n");
        return;
    }
    int n = 0;
    fscanf(fp, "%d", &n);
    g->vertex = n;
    g->graph=(ll**)malloc(sizeof(ll*)*g->vertex);
    for(int i=0;i<g->vertex;i++)
       initll(&g->graph[0]);
    for(int i=0;i<g->vertex;i++){
        for(int j=0;j<g->vertex;j++){
            fscanf(fp,"%d",&n);
            if(n!=0)
               insertll(&g->graph[i],j,n); 
        }
    }
    fclose(fp);
}


void printgraph(graph* g){
    int v=g->vertex;
    for(int i=0;i<v;i++){
        int arr[v];
        for(int j=0;j<v;j++)
           arr[j]=0;
        ll* temp=g->graph[i];
        while(temp){
           arr[temp->vertex]=temp->weight;
           temp=temp->next;
        }
        for(int j=0;j<v;j++){
            printf("%d ",arr[j]);
        }   
        printf("\n");
    }
}




void BFS(graph *g,int s){
    int v=g->vertex;
    int vis[v];
    for(int i=0;i<v;i++)
        vis[i]=0;
    queue q;
    init_q(&q,v);
    enqueue(&q,s);
    vis[s]=1;
    while(!is_empty(q)){
        int temp=dequeue(&q);
        printf("%d ",temp);
        ll* node=g->graph[temp];
        while(node){
            if(!vis[node->vertex]){
               enqueue(&q,node->vertex);
               vis[node->vertex]=1;
            }
            node=node->next;
        }
    }
    printf("\n");
}

void callfordfs(graph* g,int s,int* vis){
     printf("%d ",s);
     vis[s]=1;
     ll* node=g->graph[s];
     while(node){
         if(!vis[node->vertex])
            callfordfs(g,node->vertex,vis);
         node=node->next;
     }
}
void DFS(graph *g,int s){
    int v=g->vertex;
    int vis[v];
    for(int i=0;i<v;i++)
        vis[i]=0;
    callfordfs(g,s,vis);
    printf("\n");
}



int isdirected(graph* g){
    int v=g->vertex;
    int arr[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            arr[i][j]=0;
        }
    }
    int index=0;
    while(index<v){
        ll* temp=g->graph[index];
        while(temp){
            arr[index][temp->vertex]=1;
            temp=temp->next;
        }
        index++;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(arr[i][j]!=arr[j][i])
            return 1;
        }
    }
    return 0;
}


void Degree(graph* g){
    int isdirected=0;
    int v=g->vertex;
    int arr[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            arr[i][j]=0;
        }
    }
    int index=0;
    while(index<v){
        ll* temp=g->graph[index];
        while(temp){
            arr[index][temp->vertex]=1;
            temp=temp->next;
        }
        index++;
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(arr[i][j]!=arr[j][i])
               isdirected=1;
        }
    }

    if(isdirected){
        for(int i=0;i<v;i++){
            int indeg=0,outdeg=0;
            for(int j=0;j<v;j++){
                if(arr[i][j]) outdeg++;
                if(arr[j][i]) indeg++;
            }
            printf("For Vertex %d Indeg=%d Outdeg=%d\n",i,indeg,outdeg);
        }
    }
    else{
        for(int i=0;i<v;i++){
            int deg=0;
            for(int j=0;j<v;j++){
                if(arr[i][j]) deg++;
            }
            printf("For Vertex %d Degree is %d\n",i,deg);
        }
    }
}

int findparent(int num,int* unionarr){
    return unionarr[num];
}
void makeparentsame(int i,int j,int* unionarr,int v){
    for(int k=0;k<v;k++){
        if(unionarr[k]==i) unionarr[k]=j;
    }
}

edge* Kruskal(graph* g){
    int v=g->vertex;
    edge* edges=(edge*)malloc(sizeof(edge)*(v-1));
    heap h;
    edge e;
    int count=0;
    init_heap(&h,100);
    for(int i=0;i<v;i++){
        ll* temp=g->graph[i];
        while(temp){
            e.s=i;
            e.d=temp->vertex;
            e.w=temp->weight;
            insert_heap(&h,e);
            temp=temp->next;
        }
    }
    int unionarr[v];
    for(int i=0;i<v;i++){
       unionarr[i]=i;
    }
    while(!isempty(&h) && count<v-1){
        edge heaptop=h.arr[0];
        delete_heap(&h);
        int start=heaptop.s;
        int end=heaptop.d;
        int weight=heaptop.w;
        int parent1=findparent(start,unionarr);
        int parent2=findparent(end,unionarr);
        if(parent1==parent2)
           continue;
        edges[count++]=heaptop;
        makeparentsame(parent1,parent2,unionarr,v);    
    }
    return edges;
}

int findmin(int* cost,int* vis,int v){
    int miniindex;
    int minval=INT_MAX;
    for(int i=0;i<v;i++){
        if(minval>cost[i] && !vis[i]){
            minval=cost[i];
            miniindex=i;
        }
    }
    return miniindex;
}

int Dijkstras(graph*g,int s,int e){
    int v=g->vertex;
    int cost[v],vis[v];
    for(int i=0;i<v;i++){
       cost[i]=INT_MAX;
       vis[i]=0;
    }
    cost[s]=0;
    for(int i=0;i<v;i++){
        int index=findmin(cost,vis,v);
        if(index==e) return cost[e];
        vis[index]=1;
        ll* temp=g->graph[index];
        while(temp){
            int ver=temp->vertex;
            cost[ver]=min(cost[ver],cost[index]+temp->weight);
            temp=temp->next;
        }
    }
    return INT_MAX;
}
