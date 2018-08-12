#include <stdio.h>
#include <stdlib.h>


void simplex(float mat[][7])
{
	
	int i, j, coluna_entra, linha_sai;
	float var_entra = 0, pivo = 0, var_sai = 0;
	
	do{
		
	
		//_______________Variavel que entra e coluna Entra___________
		i = 0;
		for(j = 0; j < 7; j++)
		{
			if(var_entra > mat[i][j])
			{
				var_entra = mat[i][j];	
				coluna_entra = j;	
			}
		}
		printf("\nColuna Entra: %i\nVariavel Entra: %f\n\n", coluna_entra, var_entra);
		
	
		//__________Caculo do pivô______________problema___________
	
		j = 6;//Ultima coluna da matriz
		int quant = 1;
		for(i = 1; i < 4; i++)
		{
			
			if(mat[i][coluna_entra] > 0) // ->  caso o Numero seja Negativo, quant passa a ser 2 
			{							// Ou seja, para poder
			
				if(i == quant)   
				{
					var_sai = mat[i][j]/mat[i][coluna_entra];
					linha_sai = i;
				}
				else if(var_sai >= mat[i][j] / mat[i][coluna_entra])
				{
					var_sai = mat[i][j]/mat[i][coluna_entra];
					linha_sai = i;
				}
			
			} else 
				quant += 1;	
		}
	
		
		printf("Variavel Sai: %f\nLinha_sai: %i\n", var_sai, linha_sai, mat[linha_sai][coluna_entra]);
		
	
	
		//_______________________________Calculo do Pivo e da linha Pivo______________________________
		//Atribuição ao pivo
		if(mat[linha_sai][coluna_entra] > 0)
		{
			pivo = mat[linha_sai][coluna_entra];
			//Calculo da linha Pivo
			printf("\nPivo: %.2f\n", pivo);
			printf("Linha Pivo: ");
				
			for(j = 0; j < 7; j++)
			{
				mat[linha_sai][j] /= pivo;
				printf("%.3f ", mat[linha_sai][j]);
			}	
				
		} 
	
		printf("\n\n\n");
		//_____________________________Calculo das Novas Linhas_______________________________
		for(i = 0; i < 4; i++) // a partir do Z
		{
			pivo = (mat[i][coluna_entra] * -1);
			for(j = 0; j < 7; j++)
			{
				if(i != linha_sai)
					mat[i][j] += mat[linha_sai][j] * pivo; //+ simplex[linhaSai][j] -> Linha Pivô
				printf("\t%0.0f |", mat[i][j]);
			}
			printf("\n");
		}
		
	
	
	/// ------------------------------- somente para o do-while-------------
	
		i = 0;
		var_entra = 0;
		for(j = 0; j < 7; j++)
		{
			if(var_entra > mat[i][j])
			{
				var_entra = mat[i][j];	
				coluna_entra = j;	
			}
		} 
	
	
	}while(var_entra < 0);

	
}

int main()
{
	/*float mat[4][7] = { {1, 0,-2,0,0,3,120}, 
						{0, 0, 1,1,0,-2,20},
						{0, 0, 1,0,1,-1,40},
						{0, 1, 0,0,0,1,40} }; */
						
	/*float mat[4][7] = {{1,-3,-2, 0, 0, 0, 0}, 
						   {0, 2, 1, 1, 0, 0, 100}, // corrrigir erro -2
						   {0, 1, 1, 0, 1, 0,80},
						   {0, 1, 0, 0, 0, 1, 40}}; */
						   
	/*float mat[4][7] =      {{1,-50,-40, 0,0,0,0}, 
						   	{0, 30, 20, 1,0,0,360},
						   	{0, 5,  10, 0,1,0,120},
						   	{0, 1,  0,  0,0,1,20}};*/
	/*float mat[4][7] =      {{1, 0,-2, 0, 0, 3, 120}, 
						   	{0, 0, 1, 1, 0, -2,20},
						   	{0, 0, 1, 0, 1, -1,40},
						   	{0, 1, 0, 0, 0, 1, 40}};*/
	simplex(mat);

	return 0;
}
