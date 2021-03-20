#ifndef __MAIN__
#define __MAIN__
typedef struct node{
    int value;
    struct node *next;
}node;

typedef struct list{
    node *head;
}list;

node* node_create(int);
void node_free(node *);
void list_init(list *);
void list_append(list *, int);
void list_print(list);
void list_free(list *);

int check_prime(list, int);
#endif
