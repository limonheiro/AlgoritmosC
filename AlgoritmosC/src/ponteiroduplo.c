/**************************************************************************
 * Programa ponteiroduplo.c                                               *
 *                                                                        *
 * Demonstracão do uso de ponteiro duplo na manipulacão de matriz 		  *
 * Data: 20/10/2014			                                              *
 * Autor: João Paulo D. Preti                                             *
 **************************************************************************/
/*
#include <stdio.h>
#include <stdlib.h>

#define CTE 2
int i;
int **matriz;

int main() {
	matriz = (int **) malloc(sizeof(int *) * CTE);
	if (matriz == NULL) {
		printf("Erro ao alocar memória");
		free(matriz);
	}

	for (i = 0; i < CTE; i++) {
		*(matriz+i) = (int *) malloc(CTE * sizeof(int));
		if (*(matriz+i) == NULL) { //mesma coisa que matri[i]==NULL
			printf("Erro ao alocar memoria");
			free(matriz);
		}
	}
	//matriz[0][0] = 1;
	*(*(matriz+0)+0) = 1;
	//matriz[0][1] = 2;
	*(*(matriz+0)+1) = 2;
	//matriz[1][0] = 3;
	*(*(matriz+1)+0) = 3;
	//matriz[1][1] = 4;
	*(*(matriz+1)+1) = 4;

	printf("%d %d\n", matriz[0][0], matriz[0][1]);
	printf("%d %d\n", matriz[1][0], matriz[1][1]);

	free(matriz);

	return 0;
}
*/
