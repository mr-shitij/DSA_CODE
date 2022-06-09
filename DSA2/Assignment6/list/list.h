typedef struct Node {
	int weight;
	int node_id;
    struct Node *next;
} Node;
typedef Node *List;

void insertAtFirst(List *list, int node_id, int weight);
void traverse(List list);
int get_size_list(List list);
