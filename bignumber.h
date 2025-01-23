#ifndef BIGNUMBER_H
#define BIGNUMBER_H

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

#endif
