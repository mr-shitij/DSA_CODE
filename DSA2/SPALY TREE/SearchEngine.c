#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "SearchEngine.h"
#include "stack.h"

bool search_sub(char ar1[], char ar2[]);
int minfreq(root t, int m);
int maxfreq(root t, int m);
int max_Using_Stack(root t, int m);
int min_Using_Stack(root t, int m);
void printMax(root t, int m);
void printMin(root t, int m);

void initSplay(root *t){
    *t = NULL;
    return;
}

root load_From_File(){
    char str[200];
    char key[200];
    int freq;
    root t;
    initSplay(&t);
    FILE *fp1 = fopen("backup.txt", "r");
    FILE *fp2 = fopen("backup_key.txt", "r");
    FILE *fp3 = fopen("backup_freq.txt", "r");
    if(!fp1 || !fp2 || !fp3){
        return t;
    }
    while(fgets(str, sizeof(str), fp1)){
        fscanf(fp2, "%s", &key);
        fscanf(fp3, "%d", &freq);
        // printf("%s\n", str);
        // printf("%s\n", key);
        // printf("%d\n", freq);
        insert(&t, key, str, freq);
        //display(t);
        // printf("h\n");
    }
    //display(t);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    return t;
}

void re_Write(root t){
    FILE *fp1 = fopen("backup.txt", "w");
    FILE *fp2 = fopen("backup_key.txt", "w");
    FILE *fp3 = fopen("backup_freq.txt", "w");
    if(!fp1 || !fp2 || !fp3){
        return;
    }
    stack s;
    init(&s);
    node *p = t, *q = NULL;

    while(1){
        if(p != NULL){
            push(&s, p);
            p = p->left;
        }
        else{
            if(!isEmpty(s)){
                p = peek(s);
                if(!p->right || p->right==q){
                    fprintf(fp1, "%s", p->search);
                    fprintf(fp2, "%s\n", p->key);
                    fprintf(fp3, "%d\n", p->freq);
                    //printf("%d ", p->data);
                    pop(&s);
                    q = p;  //q will point to previously printed node.
                    p = NULL;
                }
                else{
                    p = p->right;
                }
            }
            else{
                break;
            }
        }
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
}

char* create_key(){
    time_t now = time(0);
    char *dt = ctime(&now);
    char *key = (char*)malloc(8);
    int i, j;
    for(i=11, j=0; i<19; i++, j++)
	    key[j] = dt[i];
	key[j] = '\0';
	//printf("%s", key);
	return key;
}

void rightrotate(root *t, node *r){
    node *p = r->left;
    r->left = p->right;
    if(p->right != NULL){
        p->right->parent = r;
    }
    p->parent = r->parent;
    if(r->parent == NULL){  //r is a root
        *t = p;
    }
    else if(r == r->parent->right){ //r is left child
        r->parent->right = p;
    }
    else{   // r is right child
        r->parent->left = p;
    }
    p->right = r;
    r->parent = p;
}

void leftrotate(root *t, node *r){
    node *p = r->right;
    r->right = p->left;
    if(p->left != NULL){
        p->left->parent = r;
    }
    p->parent = r->parent;
    if(r->parent == NULL){  //r is a root
        *t = p;
    }
    else if(r == r->parent->left){ //r is left child
        r->parent->left = p;
    }
    else{   // r is right child
        r->parent->right = p;
    }
    p->left = r;
    r->parent = p;
}

void splay(root *t, node *n){
    node *r = *t;
    while(n->parent != NULL){   //node is not root
        if(n->parent == r){ //node is a child of root, one rotation
            if(n == n->parent->left){
                rightrotate(t, n->parent);
            }
            else{
                leftrotate(t, n->parent);
            }
        }
        else{
            node *p = n->parent;
            node *q = p->parent;    //grandparent
            if(n->parent->left == n && p->parent->left == p){   //both are left children
                rightrotate(t, q);
                rightrotate(t, p);
            }
            else if(n->parent->right == n && p->parent->right == p) { //both are right children
                leftrotate(t, q);
                leftrotate(t, p);
            }
            else if(n->parent->right == n && p->parent->left == p) {
                leftrotate(t, p);
                rightrotate(t, q);
            }
            else if(n->parent->left == n && p->parent->right == p) {
                rightrotate(t, p);
                leftrotate(t, q);
            }
        } 
    }   
}

void get_Search(char str[]){
    //printf("%s", str);
    char key[200];
    char *k = create_key();
    strcpy(key, k);
    root t;
    initSplay(&t);
    insert(&t, key, str, 0);
    FILE *fp1 = fopen("backup.txt", "a");
    FILE *fp2 = fopen("backup_key.txt", "a");
    FILE *fp3 = fopen("backup_freq.txt", "a");
    if(!fp1 || !fp2 || !fp3){
        return;
    }
    fprintf(fp1, "%s\n", str);
    fprintf(fp2, "%s\n", k);
    int fre = 0;
    fprintf(fp3, "%d\n", fre);
    //display(t);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    destroy(&t);
    t = NULL;
    return;
}

void insert(root *t, char key[], char search[], int frq){
    //node *nn = newNode(key);
    node *nn = (node*)malloc(sizeof(node));
    if(!nn){
        return;
    }
    // nn->key = key;
    strcpy(nn->key, key);
    //nn->search = search;
    strcpy(nn->search, search);
    // printf("\nentered: %s\n", nn->search);
    nn->left = nn->right = NULL;
    nn->parent = NULL;
    nn->freq = frq;
    nn->count = 0;

    if(*t == NULL){
        *t = nn;
        return;
    }

    //q is parent pointer
    node *p, *q = NULL;
    p = *t;
    while(p){
        q = p;
        if(strcmp(key, p->key) < 0){
            p = p->left;    //advance p
        }
        else{
            p = p->right;
        }
    }
    
    if(strcmp(key, q->key) < 0){
        q->left = nn;
    }
    else{
        q->right = nn;
    }
    nn->parent = q;
    splay(t, nn);
    return;
}

void inorder(root t){
    if(!t){
        return;
    }
    inorder(t->left);
    printf("%s >> %s", t->key, t->search);
    if(t->parent)
        printf(" - %s\n", t->parent->key);
    else
        printf(" --- \n");
    inorder(t->right);
    return;
}

void preorder(root t){
    if(!t){
        return;
    }
    printf("\t%s >> %s", t->key, t->search);
    // if(t->parent)
    //     printf(" - %s\n", t->parent->key);
    // else
    //     printf(" --- \n");
    preorder(t->left);
    preorder(t->right);
    return;
}

void display(root t){
    time_t now = time(0);
    char *dt = ctime(&now);
    printf("\n\n\t\t*** Search History ***\n");
    for(int i = 0; i < 11; i++){
        printf("%c", dt[i]);
    }
    printf("\n\n");
    preorder(t);
}

void search(root t, char sub[]){
    if(!t){
        return;
    }
    else{
        if(t->count != 1){
            if(search_sub(sub, t->search)){
                t->freq++;
                //t->search[strcspn(t->search, "\n")] = 0;
                printf("\n\t%s \t:: %s", t->search, t->key);
                //flag_s = 0;
                t->count = 1;
            }
        }
        search(t->left, sub);
        search(t->right, sub);
        t->count = 0;
    }
}

bool search_sub(char ar1[], char ar2[]){
    //int flag_sub = 0;
    int len = strlen(ar1);
    int i = 0;
    while(i < len){
        if(ar1[i] == ar2[i]){
            i++;
        }
        else{
            break;
        }
    }
    if(i == len){
        return true;
    }
    else{
        return false;
    }
}

// int maxfreq(root t, int m){
//     //display(t);
//     if(t){
//         if(m <= t->freq){
//             m = t->freq;
//         }
//         return maxfreq(t->left, m);
//         return maxfreq(t->right, m);
//     }
//     return m;
// }

// int minfreq(root t, int m){
//     if(t){
//         if(m >= t->freq){
//             m = t->freq;
//         }
//         return minfreq(t->left, m);
//         return minfreq(t->right, m);
//     }
//     return m;
// }

void printMax(root t, int m){
    if(!t){
        return;
    }
    if(m == t->freq){      
        //t->search[strcspn(t->search, "\n")] = 0;
        printf("\n\t%s \t>> %s searched %d times\n", t->search, t->key, t->freq);
    }
    printMax(t->left, m);
    printMax(t->right, m);
}

void printMin(root t, int m){
    if(!t){
        return;
    }
    if(m == t->freq){ 
        //t->search[strcspn(t->search, "\n")] = 0;     
        printf("\n\t%s \t>> %s searched %d times\n", t->search, t->key, t->freq);
    }
    printMin(t->left, m);
    printMin(t->right, m);
}

void frequency(root t, int ch){
    int max, min;
    max = min = t->freq;
    root h = load_From_File();
    //printf("\n%d\n", max);
    if(!t){
        return;
    }
    max = max_Using_Stack(h, max);
    min = min_Using_Stack(h, min);
    if(ch == 1){
        printf("\n\t*** Most frequently browsed searches ***\n");
        printMax(h, max);
    }
    else if(ch == 0){
        printf("\n\t*** Least frequently browsed searches ***\n");
        printMin(h, min);
    }
    else{
        printf("\n\t*** Most frequently browsed searches ***\n");
        printMax(h, max);
        printf("\n\t*** Least frequently browsed searches ***\n");
        printMin(h, min);
    }
    destroy(&h);
    h = NULL;
    return;
}

void destroy(root *t){
    if(*t == NULL){
        return;
    }
    destroy(&(*t)->left);
    destroy(&(*t)->right);
    free((*t));
}

int max_Using_Stack(root t, int m){
    if(!t){
        return -1;
    }
    stack s;
    init(&s);
    node *p = t;

    while(1){
        if(p != NULL){
            if(m <= p->freq){
                m = p->freq;
            }  
            push(&s, p);
            p = p->left;
        }
        else{
            if(!isEmpty(s)){
                p = pop(&s);
                p = p->right;
            }
            else{
                break;
            }
        }
    }
    return m;
}

int min_Using_Stack(root t, int m){
    if(!t){
        return -1;
    }
    stack s;
    init(&s);
    node *p = t;

    while(1){
        if(p != NULL){
            if(m >= p->freq){
                m = p->freq;
            }  
            push(&s, p);
            p = p->left;
        }
        else{
            if(!isEmpty(s)){
                p = pop(&s);
                p = p->right;
            }
            else{
                break;
            }
        }
    }
    return m;
}

void store_History(){
    time_t now = time(0);
    char *dt = ctime(&now);
    // printf("\n\n\t\t*** Search History ***\n");
    FILE *f = fopen("History.txt", "a");
    if(!f){
        return;
    }
    fprintf(f, "\n");
    fprintf(f, "%s", dt);
    fprintf(f, "\n");
    root t = load_From_File();

    if(!t){
        return;
    }
    stack s;
    init(&s);
    node *p = t;

    while(1){
        if(p != NULL){
            fprintf(f, "\t%s", p->search);
            fprintf(f, "\t\t>>%s", p->key);
            fprintf(f, "\tfrequency: %d\n", p->freq);
            push(&s, p);
            p = p->left;
        }
        else{
            if(!isEmpty(s)){
                p = pop(&s);
                p = p->right;
            }
            else{
                break;
            }
        }
    }
    destroy(&t);
    t = NULL;
    fclose(f);
    return;
}

void display_History(){
    printf("\n\t**** History ****\n\n");
    FILE *f = fopen("History.txt", "r");
    char c;
    if(!f){
        return;
    }
    c = fgetc(f);
    while(c != EOF){
        printf("%c", c);
        c = fgetc(f);
    }
    fclose(f);
    return;
}

void recent(root t){
    printf("\n\t*** Recently Searched Data ***\n\n");
    //t->search[strcspn(t->search, "\n")] = 0;     
    printf("\n\t\t%s \t\t>> %s \n", t->search, t->key);
    return;
}

void print_suggestion(root t, char str[]){
    if(!t){
        return;
    }
    stack s;
    init(&s);
    node *p = t;
    printf("\n");

    while(1){
        if(p != NULL){
            char *j = strstr(p->search, str);
            if(j){
                printf("\t%s", p->search);
            }
            push(&s, p);
            p = p->left;
        }
        else{
            if(!isEmpty(s)){
                p = pop(&s);
                p = p->right;
            }
            else{
                break;
            }
        }
    }
}
