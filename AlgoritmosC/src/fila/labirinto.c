/*
 * labirinto.c
 *
 *  Created on: 11 de jul de 2016
 *      Author: joaopaulodelgadopreti
 *  Apresentar um caminho para escapar do labirinto.
 */
/*
#include "xyQueue.h"

#define TAMANHO 10

void exibirTrilha(int labirinto[TAMANHO][TAMANHO]) {
	int i,j;
	for (i = 0; i < TAMANHO; i++) {
		for (j = 0; j < TAMANHO; j++) {
			printf("%d\t",labirinto[i][j]);
		}
		printf("\n");
	}
}

int main() {
	//-1 = parede, não se pode avançar por esse caminho
	// 0 = caminho possível mas não explorado
	//>0 = caminho já explorado
	// 1 = ponto de partida
	// deseja-se chegar a posição [10][10] do labirinto.
	int labirinto[TAMANHO][TAMANHO] = {
		  	{ 1,-1, 0, 0, 0, 0, 0, 0, 0,-1},
			{ 0,-1,-1,-1,-1, 0,-1,-1, 0,-1},
			{ 0, 0, 0, 0,-1, 0,-1, 0, 0,-1},
			{ 0,-1,-1,-1,-1, 0, 0,-1, 0, 0},
			{ 0,-1,-1,-1,-1,-1, 0,-1,-1, 0},
			{ 0, 0,-1,-1, 0, 0, 0,-1, 0, 0},
			{-1, 0, 0, 0, 0,-1,-1,-1, 0,-1},
			{-1,-1,-1, 0,-1, 0, 0,-1, 0, 0},
			{ 0, 0,-1, 0,-1, 0, 0, 0,-1, 0},
			{ 0, 0,-1, 0,-1, 0, 0, 0,-1, 0}
	};

	xyQueue fila;
	init(&fila,1);
	enqueue(&fila,(coordXY){0,0});
	int achou=0;
	while (!isEmpty(&fila) && !achou) {
		coordXY pos = dequeue(&fila);
		int trilha = labirinto[pos.x][pos.y];

		if (pos.x==TAMANHO-1 && pos.y==TAMANHO-1) {
			achou = 1;
		} else {
			if (pos.x < TAMANHO-1 && labirinto[pos.x+1][pos.y]==0) { enqueue(&fila,(coordXY){pos.x+1,pos.y}); labirinto[pos.x+1][pos.y]=trilha+1;}
			if (pos.y < TAMANHO-1 && labirinto[pos.x][pos.y+1]==0) { enqueue(&fila,(coordXY){pos.x,pos.y+1}); labirinto[pos.x][pos.y+1]=trilha+1;}
			if (pos.y > 0 && labirinto[pos.x][pos.y-1]==0) { enqueue(&fila,(coordXY){pos.x,pos.y-1}); 		  labirinto[pos.x][pos.y-1]=trilha+1;}
			if (pos.x > 0 && labirinto[pos.x-1][pos.y]==0) { enqueue(&fila,(coordXY){pos.x-1,pos.y}); 		  labirinto[pos.x-1][pos.y]=trilha+1;}
		}
	}

	if (achou) {
		exibirTrilha(labirinto);
	} else {
		printf("Não existe caminho até o final do labirinto!");
	}

	return 0;
}
*/
