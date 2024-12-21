#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "bignumber.h"

struct _bignumber{
    Node first;
    Node last;
    int n_elements;
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

    if(l->last == NULL){
        l->first = p;
        l->last = p;
    } else{
        l->last->next = p;
        l->last = p;
    }

    l->n_elements += 1;
}

void bignumber_push_front(BigNumber b, int data){
    Node p = node(data);

    if(l->first == NULL){
        l->first = p;
        l->last = p;
    } else{
        p->next = l->first;
        l->first = p;
    }

    l->n_elements += 1;
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
