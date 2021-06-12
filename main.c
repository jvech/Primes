#include<stdlib.h>
#include<stdio.h>
#include"main.h"

void print_usage(void);

int main(int argc, char **argv){
    list prime_numbers;
    list_init(&prime_numbers);

    int prime, count, n;
    prime = 2;
    count = 0;

    if(argc != 2){
        print_usage();
        return EXIT_FAILURE;
    }

    n = atoi(argv[1]);
    if(n <= 0){
        print_usage();
        return EXIT_FAILURE;
    }
    do{
        if(check_prime(prime_numbers, prime)){
            count++;
            list_append(&prime_numbers, prime);
        }
        prime++;
    }while(count<n);
    printf("%d\n",prime - 1);

    list_free(&prime_numbers);
    return EXIT_SUCCESS;
}

void print_usage(){
    fprintf(stderr, "Usage: prime <integer>\n");
    fprintf(stderr, "Shows the n-th prime value\n");
}

int check_prime(list prime_numbers, int prime){
    node *p;

    p = prime_numbers.head;
    while(p!=NULL){
        if(prime % p->value == 0)
            return 0;
        p = p->next;
    }
    return 1;
}

/* Create a node item to the list*/
node* node_create(int item){
    node* x = (node *)malloc(sizeof(node));
    x->value = item;
    x->next = NULL;
    return x;
}


/* Free the node item in memory */
void node_free(node* x){
    free(x);
}


/* Initialize the list head */
void list_init(list *x){
    x->head = NULL;
}


/* Append an item to the final of the list */
void list_append(list *x, int item){
    node *p, *q;
    p = node_create(item);

    if(x->head == NULL){
        x->head = p;
        return;
    }

    for(q=x->head; q->next!=NULL; q=q->next);
    q->next = p;
}


/* Show the list in the standart output */
void list_print(list x){
    node *p;
    printf("[");
    for(p=x.head; p!=NULL; p=p->next)
        printf("%4d", p->value);
    printf("]\n");
}

/* Deallocate all the nodes of the list */
void list_free(list *x){
    node *p;
    while(x->head!=NULL){
        p = x->head;
        x->head = p->next;
        node_free(p);
    }
}
