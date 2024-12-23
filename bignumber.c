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
	BigNumber b = malloc(sizeof(struct _bignumber));

	b->first = NULL;
	b->last = NULL;
	b->n_elements = 0;

    return b;
}

void bignumber_push_back(BigNumber b, int data){
	Node p = node(data);

	if(b->last == NULL){ //Caso a lista esteja vazio
        	b->first = p; //Atualiza o ponteiro do primeiro nó
        	b->last = p; //Atualiza o ponteiro do último nó
    	} else{
        	p->prev = b->last; //O anterior do novo nó é o primeiro nó(à esquerda)
        	b->last->next = p; //O próximo do primeiro nó é o novo nó(à direita)
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
        	p->next = b->first; //O próximo do novo nó é o ultimo nó(à direita)
        	b->first->prev = p; //O anterior do primeiro nó é o novo nó(à esquerda)
        	b->first = p; //O primeiro nó agora é o novo nó
    	}

    	b->n_elements += 1;
}

void read_bignumber(BigNumber b){
	char c;
	while(scanf("%c", &c) == 1 && c != '\n'){
        	bignumber_push_back(b, c - '0');
    	}
}

void print_bignumber(BigNumber b){
	Node current = b->first;

	for(int i = 0; i < b->n_elements && current != NULL; i++){
        	printf("%d", current->data);
        	current = current->next;
    	}
}

BigNumber sum_bignumber(Bignumber a, BigNumber b){
	BigNumber result = bignumber();

    	Node* _a = a->last; // ponteiros para o último elemento; tail 
    	Node* _b = b->last;
    	int overflow = 0;

    	while (_a != NULL || _b!= NULL || overflow > 0) {
        	if (_a!=NULL)
        		digit_a = _a->data
        	else 
			digit_a = 0;

        	if (_b!=NULL)
        		digit_a = _a->data
        	else 
			digit_a = 0;
    	}
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

void free_bignumber(BigNumber b){
    
}
