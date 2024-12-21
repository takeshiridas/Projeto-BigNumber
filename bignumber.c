#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "bignumber.h"

struct _bignumber{
    Node first; //Ponteiro para o primeiro nó
    Node last; //Ponteiro para o útlimo nó
    int n_elements; //Contador de elementos do número
};

BigNumber bignumber(void){
	BigNumber b = malloc(sizeof(BigNumber));

    b->first = NULL;
    b->last = NULL;
    b->n_elements = 0;

    return b;
}

void bignumber_push_back(BigNumber b, int data){
    Node p = node(data);

    if(b->last == NULL){ //Caso o último nó esteja vazio
        b->first = p; //Atualiza o ponteiro do primeiro nó
        b->last = p; //Atualiza o ponteiro do último nó
    } else{
        p->prev = b->last; //O anterior do novo nó é o último nó(à direita)
        b->last->next = p; //O próximo do último nó é o novo nó(à esquerda)
        b->last = p; //O último nó agora é o novo nó
    }

    b->n_elements += 1; //Aumenta o número de elementos
}

void bignumber_push_front(BigNumber b, int data){
    Node p = node(data);

    if(b->first == NULL){ 
        b->first = p; 
        b->last = p;
    } else{
        p->next = b->first; //O próximo do novo nó é o primeiro nó(à esquerda)
        b->first->prev = p; //O anterior do primeiro nó é o novo nó(à direita)
        b->first = p; //O primeiro nó agora é o novo nó
    }

    b->n_elements += 1;
}

void print_bignumber(BigNumber bignumber){
	
}

BigNumber sum_bignumber(Bignumber a, BigNumber b{

}

BigNumber minus_bignumber(BigNumber a, BigNumber b){

}

BigNumber multiplication_bignumber(BigNumber a, BigNumber b){

}

BigNumber divide_bignumber(Bignumber a, BigNumber b){

}

BigNumber power_bignumber(Bignumber a, BigNumber b){

}

BigNumber remainder_bignumber(Bignumber a, BigNumber b){

}
