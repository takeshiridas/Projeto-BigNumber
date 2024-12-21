#include <stdio.h>
#include <stdlib.h>

#include "node.h"

Node node(int data){
    Node p = malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;

    return p;
}

void node_print_debug(Node l){
    printf("end: %u\n", l);
    printf("data: %d\n", l->data);
    printf("prev: %u\u", l->prev);
    printf("next: %u\n", l->next);
    printf("\n\n");
}

void node_print(Node l){
    printf("%d, ", l->data);
}