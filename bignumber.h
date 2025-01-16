#ifndef BIGNUMBER_H
#define BIGNUMBER_H

typedef struct _bignumber* BigNumber;

BigNumber bignumber(void);//Construtor de BigNumber

void bignumber_push_back(BigNumber b, int data);//Inserir número no final ou direita(Digito menos significativo)

void bignumber_push_front(BigNumber b, int data);//Inserir no início ou esquerda(Digito Mais Significativo)

void read_bignumber(BigNumber b); //Leitor do BigNumber

void print_bignumber(BigNumber b); //Impressor de BigNumber

int compare_bignumber(BigNumber a, BigNumber b); //Compara "a" e "b"

BigNumber sum_bignumber(Bignumber a, BigNumber b);//Soma

BigNumber minus_bignumber(BigNumber a, BigNumber b);//Subtração

BigNumber multiplication_bignumber(BigNumber a, BigNumber b);//Multiplicação

BigNumber divide_bignumber(Bignumber a, BigNumber b);//Divisão

BigNumber power_bignumber(Bignumber a, BigNumber b);//Potenciação

BigNumber remainder_bignumber(Bignumber a, BigNumber b);//Resto de Divisão

void free_bignumber(BigNumber b);

#endif
