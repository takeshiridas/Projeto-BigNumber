#include <stdio.h>
#include <stdlib.h>

#include "node.h"

Node node(int data){
    Node p = malloc(sizeof(Node)); //Aloca o novo nó
    p->data = data; //Define o valor do novo nó
    p->next = NULL; //Não tem "próximo" nó então o próximo é vazio
    p->prev = NULL; //Mesma coisa do próximo, mas com o anterior

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