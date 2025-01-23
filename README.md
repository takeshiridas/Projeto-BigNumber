# 11202231659

--- Organização do Código

O programa foi dividido em 6 códigos, 2 bibliotecas: bignumber.h e node.h. 2 implementações: bignumber.c e node.c. O client.c e o makefile para compilar tudo. 


--- Funcionalidades do Código

O leitor funciona corretamente, para números inteiros positivos e negativos. A impressão também funcionou em 100% dos testes, junto da soma e da subtração.

--- Funcionalidades extras no código
Uma variável global e estática para usar como zero, já que o programa não reconhecia o 0 como um bignumber para fins comparativos. Uma função para inverter os sinais dos números para executar a soma e a subtração em casos específicos. Uma função para liberar os bignumbers no final.

--- Interface pública do código

A interface está no bignumber.h e no node.h, as assinaturas estão abaixo:

#BigNumber.h - 

typedef struct _bignumber* BigNumber;

BigNumber bignumber(void);//Construtor de BigNumber

void bignumber_push_back(BigNumber b, int data);//Inserir número no final ou direita(Digito menos significativo)

void bignumber_push_front(BigNumber b, int data);//Inserir no início ou esquerda(Digito Mais Significativo)

void read_bignumber(BigNumber b); //Leitor do BigNumber

void print_bignumber(BigNumber b); //Impressor de BigNumber

int compare_bignumber(BigNumber a, BigNumber b); //Compara "a" e "b"

BigNumber inverte(BigNumber b); //Cria um bignumber temporário para fazer inversões de sinais sem trocar o sinal do número original

BigNumber sum_bignumber(BigNumber a, BigNumber b);//Soma

BigNumber minus_bignumber(BigNumber a, BigNumber b);//Subtração

void free_bignumber(BigNumber);//Libera Memória

#Node.h - 

typedef struct _node* Node;

struct _node{
    int data;
    struct _node* next; //Aponta para o nó à direita
    struct _node* prev; //Aponta para o nó à esquerda
};

Node node(int data);
void node_print(Node l);

--- Vitor Takeshi 11202231659

Fez o projeto.
