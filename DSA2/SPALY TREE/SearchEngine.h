#include <stdbool.h>
typedef struct node{
    char key[200];
    char search[200];
    int freq;
    int count;
    struct node *left;
    struct node *right;
    struct node *parent;
}node;

typedef node *root;

void initSplay(root *t);
char* create_key();
// node* newNode(int key);
void insert(root *t, char key[], char search[], int frq);
void leftrotate(root *t, node *r);   
void rightrotate(root *t, node *r);   
void splay(root *t, node *n);
void inorder(root t);
void preorder(root t);
void display(root t);
void search(root t, char sub[]);
void frequency(root t, int ch);
void destroy(root *t);
void get_Search(char str[]);
root load_From_File();
void re_Write(root t);
void store_History();
void display_History();
void recent(root t);
void print_suggestion(root t, char str[]);