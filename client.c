#include <stdio.h>
#include "bignumber.h"

int main() {
    char c;
    while (1) {
        BigNumber a = bignumber();
        BigNumber b = bignumber();

        // Lê os dois números
        read_bignumber(a);
        read_bignumber(b);

        // Lê o operador (ignora espaços ou quebras de linha antes)
        if (scanf(" %c", &c) != 1) { 
            free_bignumber(a);
            free_bignumber(b);
            break; // Sai do loop se atingir EOF
        }

		BigNumber result = NULL;

        if (c == '+') {
            result = sum_bignumber(a, b);
        } else if (c == '-') {
            result = minus_bignumber(a, b);
        }

        if (result != NULL) {
            print_bignumber(result);
            free_bignumber(result);
        }

        // Ignora possíveis novas linhas ou espaços extras após o operador
        while ((c = getchar()) != EOF && c != '\n') {
            // Consumir caracteres extra até a próxima linha
        }

        free_bignumber(a);
        free_bignumber(b);
    }
    return 0;
}
