#define SIZE 10
typedef struct Graph{
	int matrix[SIZE][SIZE];
	int n;
}Graph;

void init_graph(Graph *g, char* fileName);
void print(Graph g);
int graph_in_degree(Graph g, int v);
int graph_out_degree(Graph g, int v);
int isDirected(Graph g);// not symmetric = directed
void depth_first_search(Graph g, int start);
void breath_first_search(Graph g, int start);
void get_components_of_graph(Graph g);
void prims(Graph g);
void krushkals(Graph graph);

