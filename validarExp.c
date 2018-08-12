#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

typedef struct {
	int topo;
	char vet[MAX];
}Pilha;

void criar(Pilha *p) {
	p->topo = -1;
}

void inserir(Pilha *p, char value) {
	if (p->topo == MAX -1) 
		exit(1);
	else 
		p->vet[++(p->topo)] = value;
}

short ehVazia(Pilha *p) {
	return (p->topo == -1);
}

short remover(Pilha *p) {
	if (ehVazia(p))	
		exit(1);
	else
		return (p->vet[(p->topo)--]);
}

void imprimir(Pilha *p) {
	for (char i = 0; i <= p->topo; i++)
		printf("%2d", p->vet[i]);
}

int main() {
	
	//declara√ßoes
	Pilha p;
	char expressao[20] = {};

	//Criando a pilha
	criar(&p);

	//input
	printf("Expressao: ");
	scanf("%[^\n]", expressao);

	//avaliando
	for (int i = 0; i < strlen(expressao); i++) {
		if (expressao[i] == '(' || expressao[i] == '[' || expressao[i] == '{') 
			inserir(&p, expressao[i]);
		else if (expressao[i] == ')' || expressao[i] == ']' || expressao[i] == '}') 
			remover(&p);
	}

	//Se for Vazia est√° correta.
	if (ehVazia(&p))
		printf("Expressao Correta!\n");
	else 
		printf("Expressao Incorreta!\n");
	
	return 0;
}




/********************************************Outra*Forma**************************************************/

//Esse cÛdigo È funcional
/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

//TAD de Pilha
typedef struct {
	char *vet, topo;
}Pilha;

void criar(Pilha *p) {
	if ( !(p->vet = (char*) malloc(MAX * sizeof(char))) ) {
		printf("Error!\n");
		exit(1);
	} else {
		p->topo = -1;
	}
}

void inserir(Pilha *p, char caracter) {
	if (p->topo == MAX - 1) printf("Error!\n");
	else p->vet[++(p->topo)] = caracter;
}

char vazia(Pilha *p) {
	return (p->topo == -1);
}

char remover(Pilha *p) {
	if (vazia(p)) 
		printf("Pilha Vazia!\n");
	else 
		return p->vet[(p->topo)--];	
}

void imprimir(Pilha *p) {
	for (char i = p->topo; i >= 0; i--)
		printf("%2c", p->vet[i]);
}

int main() {
	
	Pilha p;
	criar(&p);
	char *exp = "((})"; //expressa errada
	char flag = 1;
	 
	 
	//V·lida a Expressao
	for (char i = 0; i < strlen(exp); i++) {
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{') 
			inserir(&p, exp[i]);
		else if ( (exp[i] == ')' || exp[i] == ']' || exp[i] == '}' ) && vazia(&p))
			flag = 0;
		else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
			remover(&p);	
	} 
	
	//VerificaÁao final
	if (!flag || !vazia(&p))
		printf("Invalido!\n");
	else 
		printf("Valida!\n");
	
	return 0;
}

*/
