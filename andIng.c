/**
 *
 * @Author: Jock
 * @Date: 1/5/2018
 * @Algorithm: AndIng Redes Computadores
 *
 */
 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contaBitsEmDecimal(int valorDecimal) {
	int count = 0;
	
	do {
		count++;
	} while ((valorDecimal /= 2) != 0);
	
	return count;
}


char* converteDecimalParaBinario(int valorDecimal) {
	int quociente = valorDecimal;
	int count = 0;
	char *binario = malloc(sizeof(char) * (contaBitsEmDecimal(valorDecimal) + 1));
	
	do {
		binario[count++] = 48 + (quociente % 2);
		quociente = valorDecimal / 2;
		valorDecimal = quociente;
	} while (quociente != 0); 
	
	binario[count] = '\0';
	strrev(binario);
	return binario;	
}


void preencheOcteto(char *octeto, int size, int max) {
	strrev(octeto);
	
	for (int count = size; count < max; count++) {
		octeto[count] = 48;
	}
	
	octeto[max] = '\0';
	strrev(octeto);
}

char* realizaANDing(int valorDecimal1, int valorDecimal2) {
	char *octeto1 = converteDecimalParaBinario(valorDecimal1);
	char *octeto2 = converteDecimalParaBinario(valorDecimal2);
	char *ANDing  = malloc(sizeof(char) * 9);
	
	preencheOcteto(octeto1, strlen(octeto1), 8);
	preencheOcteto(octeto2, strlen(octeto2), 8);

	for (int count = 0; count < 8; count++) {
		ANDing[count] = ((octeto1[count] - 48) * (octeto2[count] - 48)) + 48;
	}
	
	ANDing[8] = '\0';
	free(octeto1);
	free(octeto2);
	return ANDing;
}


int main() {

	
	int octeto1;
	int octeto2;
	char resp;
	
	do {
		
		printf("\t============================================\n");
		printf("\t=\t\t ANDing\t\t\t   =\n");
		printf("\t============================================\n");
		printf("\n\n\tOcteto1: ");
		scanf("%d", &octeto1);
		printf("\n\n\tOcteto2: ");
		scanf("%d", &octeto2);
		
		
		printf("\n\n\t%s", realizaANDing(octeto1, octeto2));
		setbuf(stdin, NULL);
		getchar();
		printf("\n\n\tPara Sair tecle space e enter...\n");
		scanf("%c", &resp);
		system("cls");
	} while (resp != 32);

	
	
	return 0;
}
