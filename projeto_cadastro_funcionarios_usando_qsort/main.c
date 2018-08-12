
/*
 * Author: Jock
 * Algorithm: ordenations
 * Date: 11/22/2017
 */
 
 
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 5
#include "sistema.c"


void menuOpcoes() {
	setlocale(LC_ALL, "portuguese");
	int opcao;
	Funcionario funcionario[MAX];
	
	while (1) {
		printf("\t###############################\n"
			   "\t#     Menu de Opçoes          #\n"
			   "\t###############################\n");
		
		printf("\n\tSelecione uma Opcao: 		  \n\n"
		       "\t 1 - Cadastrar Funcionarios.	  	\n"
			   "\t 2 - Mostrar funcionarios.		\n"		       
			   "\t 3 - Ordenar em Ordem Crescente.	\n"
			   "\t 4 - Ordenar em Ordem Decrescente.\n"
			   "\t 5 - Ordenar em Ordem Alfabetica.	\n" 
			   "\t 6 - Sair.\n");
	
		scanf("%d", &opcao);
		system("cls");
		
		switch(opcao) {
			case 1: 
				cadastroDeFuncionarios(funcionario); 							
				break; 
			case 2: 
				mostraFuncionarios(funcionario); 	 							
				break;
			case 3: 
				printf("\t Ordenando Em Ordem Crescente...\n"); 
				quickSortCrescente(funcionario, 0, MAX-1); 
				setbuf(stdin, NULL);
				getchar();	
				break;
			case 4: 
				printf("\t Ordenando Em Ordem Decrescente...\n"); 
				quickSortDecrescente(funcionario, 0, MAX-1);
				setbuf(stdin, NULL);
				getchar();	
				break;
			case 5: 
				printf("\t Ordenando Em Ordem Alfabetica...\n"); 
				quickSortAlfabetica(funcionario, 0, MAX-1);
				setbuf(stdin, NULL);
				getchar();	
				break;
			case 6: 
				printf("\t Saindo...\n"); 
				exit(0); 
				break;
		} 
		
		system("cls");
	}
}

int main() {
	menuOpcoes();
	return 0;
} 
