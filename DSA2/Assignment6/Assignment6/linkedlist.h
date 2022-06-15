typedef struct ll{
    int vertex;
    int weight;
    struct ll *next;
} ll;

void initll(ll** node);
void insertll(ll** node,int v,int w);

