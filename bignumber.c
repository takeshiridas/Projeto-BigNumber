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

static BigNumber zero = NULL;

static void initialize_zero(void) __attribute((constructor));
static void initialize_zero(void){
	if(zero == NULL){
		zero = bignumber();
		bignumber_push_back(zero,0);
	}
}

//static void free_zero(void) _attribute_((destructor));
/*static void free_zero(void){
	if(zero != NULL){
		bignumber_free(zero);
		zero = NULL;
	}
}*/

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
    printf("\n");
}

int compare_bignumber(BigNumber a, BigNumber b){
	Node _a = a->first;
	Node _b = b->first;
	
	if(a->n_elements > b->n_elements){
		return 1; //Se "a" é MAIOR que "b"
	} else if(a->n_elements < b->n_elements){
		return -1; //Se "a" é MENOR que "b"
	}
	
	for(int i = a->n_elements; i > 0; i--){
		if(_a->data > _b->data){
			return 1;
		} else if(_a->data < _b->data){
			return -1;
		}
		_a = _a->next;
		_b = _b->next;
	}
	
	return 0; //Se "a" é IGUAL a "b"
}

BigNumber sum_bignumber(BigNumber a, BigNumber b){
	initialize_zero();
	BigNumber result = bignumber();

	Node _a = a->last; // ponteiros para o último elemento tail 
	Node _b = b->last;

	int carry = 0;

	if(compare_bignumber(a, zero) == 1 && compare_bignumber(b, zero) == 1){
		while (_a != NULL || _b != NULL || carry > 0) {
			int digit_a = (_a != NULL) ? _a->data : 0; // Se _a for NULL, usa 0
			int digit_b = (_b != NULL) ? _b->data : 0; // Se _b for NULL, usa 0

			int sum = digit_a + digit_b + carry; // Soma os dígitos e o carry
			carry = sum / 10; // Atualiza o carry (1 se a soma for >= 10)
			int result_digit = sum % 10; // Extrai o dígito atual

			bignumber_push_front(result, result_digit); // Insere no início do resultado

			// Avança para os nós anteriores (se existirem)
			if (_a != NULL)
				_a = _a->prev;
			if (_b != NULL) 
				_b = _b->prev;
	    	}
	} /*else if(){
	
	}*/

	return result;
}

BigNumber minus_bignumber(BigNumber a, BigNumber b){
	BigNumber result = bignumber();

	Node _a = a->last;
	Node _b = b->last;

	int carry = 1;

	
}

BigNumber multiplication_bignumber(BigNumber a, BigNumber b){

}

BigNumber divide_bignumber(BigNumber a, BigNumber b){

}

BigNumber power_bignumber(BigNumber a, BigNumber b){

}

BigNumber remainder_bignumber(BigNumber a, BigNumber b){

}

void free_bignumber(BigNumber b){
    
}
