typedef struct snode{    //stack structure
    node *b;
    struct snode *next;
}snode;

typedef snode* stack;

void init(stack *top);
void push(stack *top, node *t);
node* pop(stack *top);
node* peek(stack top);
int isEmpty(stack top);