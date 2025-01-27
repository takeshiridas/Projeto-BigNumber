#include <stdio.h>
#include <stdlib.h>

#include "node.h"

Node node(int data){
    Node p = malloc(sizeof(struct _node)); //Aloca o novo nó
    p->data = data; //Define o valor do novo nó
    p->next = NULL; //Não tem "próximo" nó então o próximo é vazio
    p->prev = NULL; //Mesma coisa do próximo, mas com o anterior

    return p;
}
