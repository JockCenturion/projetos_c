/**
 *
 * Informe o primo que você quer que o algoritmo te dará
 * Ex: 1 primo é 2, 2 primo é 3, ....
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
	//Funçoes
	setlocale(LC_ALL, "portuguese");
	
	//Variáveis
	int num, i, eh_primo, seq_primo = 0, x;

	printf("Informe um Número inteiro  maior ou igual a 1: ");
	scanf("%i", &x);

    for(num = 1; num < 12; num++) {
        eh_primo = 0;
		for(i = 1; i <= num; i++)
		{
			if(num % i == 0)
				eh_primo += 1;
		}
		if(eh_primo == 2) {
            seq_primo += 1;
		}
		if(seq_primo == x) {
            printf("\nNumero: %i", num);
            break;
		}

    }

	return 0;
}
