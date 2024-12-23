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
	Node p = node(data); //Ponteiro para o nó sendo inserido no final

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
	Node p = node(data); //Ponteiro para o nó sendo inserido no início

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
	while(scanf("%c", &c) == 1 && c != '\n'){ //Enquanto o scanf não der problemas e o usuário não der uma quebra de linha
        	bignumber_push_back(b, c - '0'); //Vai inserindo o número na ordem digitada
    	}
}

void print_bignumber(BigNumber b){
	Node current = b->first; //Nó para o primeiro dígito

	for(int i = 0; i < b->n_elements && current != NULL; i++){ //Executa até chegar no último dígito ouu até dar algum nó com problema
        	printf("%d", current->data); //Imprime o primeiro dígito
        	current = current->next; //Atualiza para o dígito da direita
    	}
}

BigNumber sum_bignumber(Bignumber a, BigNumber b){
	BigNumber result = bignumber();

    Node _a = a->last; // ponteiros para o último elemento; tail 
    Node _b = b->last;

    Node current = result->last;
	result->n_elements = (a->n_elements >= b->n_elements) ? a->n_elements + 1 : b->n_elements + 1; //Definindo o tamanho de result dependendo de qual número é maior

	for(int i = 0; i < result->n_elements; i++){ //Definindo todos os algarismos de result como 0
		current->data = _a->data + _b->data;
		if(_a->data + _b->data >= 10){
			current->data -= 10;
		}
		current = current->next;
		_a = _a->next;
		_b = _b->next;
	}

	return result;
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
