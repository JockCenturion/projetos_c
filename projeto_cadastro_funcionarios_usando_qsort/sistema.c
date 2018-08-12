/*
 * Author: jock
 * Algorithm: algorithm ordenations
 * Date: 11/22/2017
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario {
	char nome[81];
	float salario;
}Funcionario;

/* Implementaçoes do quickSort */
//quickSort Ordem Crescente de Salario
void quickSortCrescente(Funcionario *arr, int left, int right) {
	int start 		  = left;
	int end   		  = right;
	Funcionario pivot = arr[(start + end) / 2];
	
	while (start <= end) {
		while (arr[start].salario < pivot.salario) {
			start++;
		}
		
		while (arr[end].salario > pivot.salario) {
			end--;
		}
		
		if (start <= end) {
			Funcionario aux = arr[start];
			arr[start] 		= arr[end];
			arr[end] 		= aux;
			start++;
			end--;
		}
	}
	
	if (start < right) {
		quickSortCrescente(arr, start, right);
	}
	
	if (end > left) {
		quickSortCrescente(arr, left, end);
	}
}

//quickSort Ordem Decrescente
void quickSortDecrescente(Funcionario *arr, int left, int right) {
	int start 			= left;
	int end   			= right;
	Funcionario pivot 	= arr[(start + end) / 2];
	
	while (start <= end) {
		while (arr[start].salario > pivot.salario) {
			start++;
		}
		
		while (arr[end].salario < pivot.salario) {
			end--;
		}
		
		if (start <= end) {
			Funcionario aux = arr[start];
			arr[start]		= arr[end];
			arr[end]		= aux;
			start++;
			end--;
		}
	}
	
	if (start < right) {
		quickSortDecrescente(arr, start, right);
	}
	
	if (end > left) {
		quickSortDecrescente(arr, left, end);
	}
}

//quickSort Ordem Alfabetica
void quickSortAlfabetica(Funcionario *arr, int left, int right) {
	int start 			= left;
	int end 			= right;	
	Funcionario pivot 	= arr[(start + end) / 2];

	while (start <= end) {
		while (stricmp(arr[start].nome, pivot.nome) < 0) {
			start++;
		} 
		
		while (stricmp(arr[end].nome, pivot.nome) > 0) {
			end--;
		}
		
		if (start <= end) {
			Funcionario aux = arr[start];
			arr[start]		= arr[end];
			arr[end]		= aux;
			start++;
			end--;
		}
	}
	
	if (start < right) {
		quickSortAlfabetica(arr, start, right);
	}
	
	if (end > left) {
		quickSortAlfabetica(arr, left, end);
	}
}

/* Funções do Sistema */
void cadastroDeFuncionarios(Funcionario *array) {
	for (int count = 0; count < MAX; count++) {
		printf("\t ______%dº Funcionario______ \n\n", count + 1);
		setbuf(stdin, NULL);
		printf("\t Nome: ");
		scanf("%81[^\n]", &array[count].nome);
		printf("\t Salário: ");
		scanf("%f", &array[count].salario);
		printf("\n\n");
	}
}

void mostraFuncionarios(Funcionario *array) {
	for (int count = 0; count < MAX; count++) {
		printf("\t ______%dº Funcionario______ \n\n", count + 1);
		printf("\t Nome: %s\n", array[count].nome);
		printf("\t Salário: R$ %.2f\n", array[count].salario);
		setbuf(stdin, NULL);
		getchar();	
	}
}



