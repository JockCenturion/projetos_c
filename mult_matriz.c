#include <stdio.h>
#define M 3
#define N 3

/*Criar uma TAD dessa Matriz*/
int main() {
	
	int mat1[M][N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int mat2[M][N] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	int mat3[M][N] = {};
	
	printf("Matriz1\n\n");
	
	for (char i = 0; i < M; i++) {
		for (char j = 0; j < N; j++) 
			printf("%3d", mat1[i][j]);
		printf("\n");
	}
	
	printf("\nMatriz2\n\n");
	
	for (char i = 0; i < M; i++) {
		for (char j = 0; j < N; j++) 
			printf("%3d", mat2[i][j]);
		printf("\n");
	}
	

	
	//Multiplicaçao de Matrizes
	for (char i = 0; i < M; i++) {
		for (char k = 0; k < N; k++) {
			for (char j = 0; j < N; j++)
				mat3[i][k] += mat1[i][j] * mat2[j][k];
		}
		
	}
	
	printf("\nMatriz3\n\n");
	
	for (char i = 0; i < M; i++) {
		for (char j = 0; j < N; j++) 
			printf("%3d", mat3[i][j]);
		printf("\n");
	}
	
	
	
	return 0;
}
