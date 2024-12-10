#ifndef BIGNUMBER_H
#define BIGNUMBER_H

struct bignumber{ int* valor; int capacity; int quantity; };

typedef struct bignumber BigNumber;

BigNumber bignumber(void);//Construtor de BigNumber

void print_bignumber(BigNumber bignumber); //Impressor de BigNumber

BigNumber sum_bignumber(Bignumber a, BigNumber b);//Soma

BigNumber minus_bignumber(BigNumber a, BigNumber b);//Subtração

BigNumber multiplication_bignumber(BigNumber a, BigNumber b);//Multiplicação

BigNumber divide_bignumber(Bignumber a, BigNumber b);//Divisão

BigNumber power_bignumber(Bignumber a, BigNumber b);//Potenciação

BigNumber remainder_bignumber(Bignumber a, BigNumber b);//Resto de Divisão

#endif
