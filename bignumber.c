#include <stdio.h>
#include <stdlib.h>

#include "node.h"
#include "bignumber.h"

struct _bignumber{
    Node first; //Ponteiro para o primeiro nó
    Node last; //Ponteiro para o útlimo nó
    int n_elements; //Contador de algarismos do número
    char signal; //Positivo ou Negativo
};

BigNumber bignumber(void){
	BigNumber b = malloc(sizeof(struct _bignumber));

    b->first = NULL;
    b->last = NULL;
    b->n_elements = 0;
    b->signal = '+';

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

static BigNumber zero = NULL;

static void initialize_zero(void) __attribute((constructor));
static void initialize_zero(void){
	if(zero == NULL){
		zero = bignumber();
		bignumber_push_back(zero,0);
		zero->signal = '+';
	}
}

//static void free_zero(void) __attribute__((destructor));
/*static void free_zero(void){
	if(zero != NULL){
		bignumber_free(zero);
		zero = NULL;
	}
}*/

void read_bignumber(BigNumber b) {
    char c;
    int is_first = 1; // Flag para verificar se é o primeiro caractere lido

    while (scanf("%c", &c) == 1 && c != '\n') {
        if (is_first) {
            // Verifica se o primeiro caractere é um sinal
            if (c == '-') {
                b->signal = '-';
            } else if (c == '+') {
                b->signal = '+'; // Explicitamente positivo
            } else if (c >= '0' && c <= '9') {
                // Se o primeiro caractere for um dígito, assume-se positivo
                b->signal = '+';
                bignumber_push_back(b, c - '0'); // Adiciona o primeiro dígito
            }
            is_first = 0; // Sinaliza que o primeiro caractere já foi processado
        } else {
            // Para os caracteres subsequentes, apenas dígitos são aceitos
		bignumber_push_back(b, c - '0');
        }
    }
}



void print_bignumber(BigNumber b){
    Node current = b->first;
    printf("%c", b->signal);
    for(int i = 0; i < b->n_elements && current != NULL; i++){
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

int compare_bignumber(BigNumber a, BigNumber b){
	Node _a = a->first;
	Node _b = b->first;
	
	if(a->signal == '+' && b->signal == '+'){
		//Se os 2 são positivos
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
	} else if(a->signal != b->signal){
		//Se um é negativo e o outro positivo
		if(a->signal == '-')
			return -1;
		else
			return 1;
	} else if(a->signal == '-' && b->signal == '-'){
		//Como aqui os 2 são negativos, tudo que for maior em caso de números positivos vai ser menor
		if(a->n_elements > b->n_elements){
			return -1;
		} else if(a->n_elements < b->n_elements){
			return 1; 
		}
		
		for(int i = a->n_elements; i > 0; i--){
			if(_a->data > _b->data){
				return -1;
			} else if(_a->data < _b->data){
				return 1;
			}
			_a = _a->next;
			_b = _b->next;
		}
	}
	
	return 0; //Se "a" é IGUAL a "b"
}

BigNumber inverte(BigNumber b){
	BigNumber temp = bignumber();
	temp->first = b->first;
	temp->last = b->last;
	temp->n_elements = b->n_elements;
	
	if(b->signal == '+')
		temp->signal = '-';
	else
		temp->signal = '+';
		
	return temp;
}

BigNumber sum_bignumber(BigNumber a, BigNumber b){
	initialize_zero();
	BigNumber result = bignumber();

	Node _a = a->last; // ponteiros para o último elemento; tail 
	Node _b = b->last;

	int carry = 0;

	if(a->signal == b->signal){
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
	    	
	    	result->signal = a->signal;
	} else{
		//Se um número é negativo e o outro positivo, faça a subtração
		if(a->signal == '-'){
			BigNumber temp_a = inverte(a);
			result = minus_bignumber(b, temp_a);// b - a
		} else{
			BigNumber temp_b = inverte(b);
			result = minus_bignumber(a, temp_b);// a - b
		}
	}

	return result;
}

BigNumber minus_bignumber(BigNumber a, BigNumber b){
	initialize_zero();
	BigNumber result = bignumber();
	
	Node _a = a->last;
	Node _b = b->last;

	if(a->signal == b->signal){
		if(a->signal == '+'){
			if(compare_bignumber(a, b) >= 0){
				int borrow = 0; //Váriavel para gerenciar o empréstimo	
				while(_a != NULL || _b != NULL){
					int digit_a = (_a != NULL) ? _a->data : 0;
					int digit_b = (_b != NULL) ? _b->data : 0;
					
					int minus = digit_a - digit_b - borrow;
					
					if(minus < 0){
						minus += 10;
						borrow = 1;
					} else{
						borrow = 0;
					}
					
					
					bignumber_push_front(result, minus);
					
					if(_a != NULL)
						_a = _a->prev;
					if(_b != NULL)
						_b = _b->prev;
				}
				
				result->signal = a->signal;
			} else{
				result = minus_bignumber(b, a);
			}
		} else{
			BigNumber temp_a = inverte(a);
			BigNumber temp_b = inverte(b);
			result = minus_bignumber(temp_b, temp_a);
			result->signal = '-';
		}
	} else{
		if(a->signal == '-'){
			BigNumber temp_a = inverte(a);
			result = sum_bignumber(b, temp_a);
		} else{
			BigNumber temp_b = inverte(b);
			result = sum_bignumber(a, temp_b);
		}
		
	}
	//Remover zeros à esquerda se tiver
	while(result->first != NULL && result->first->data == 0){
		Node temp = result->first;
		result->first = result->first->next;
		if(result->first != NULL)
			result->first->prev = NULL;
		free(temp);
		result->n_elements--;
	}
	//Caso o resultado seja 0(por exemplo, 100 - 100)
	if(result->n_elements == 0){
		result = zero;
	}
	
	return result;
}
