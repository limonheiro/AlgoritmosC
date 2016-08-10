/*
 * calculodistancia.c
 *
 */
/*
 A ideia de fila aparece naturalmente no cálculo de distâncias em um grafo.
 Imagine N cidades numeradas de 0 a N-1 e interligadas por estradas de mão única.
 As ligações entre as cidades são representadas por uma matriz A da seguinte maneira:
 A[i][j]  vale  1  se existe estrada de i para j e vale 0 em caso contrário.
 Suponha que a matriz tem zeros na diagonal, embora isso seja irrelevante.
 Segue um exemplo em que N vale 6:

 	 	0 	1 	2 	3 	4 	5
 0  	0 	1 	0 	0 	0 	0
 1  	0 	0 	1 	0 	0 	0
 2  	0 	0 	0 	0 	1 	0
 3  	0 	0 	1 	0 	1 	0
 4  	1 	0 	0 	0 	0 	0
 5  	0 	1 	0 	0 	0 	0

 A distância de uma cidade c a uma cidade j é o menor número de estradas que preciso percorrer para ir de c a j.
 (A distância de c a j é, em geral, diferente da distância de j a c.)
 Nosso problema:  dada uma cidade c, determinar a distância de c a cada uma das demais cidades.
 As distâncias podem ser armazenadas em um vetor dist: a distância de c a j é dist[j].
 É preciso tomar uma decisão de projeto para cuidar do caso em que é impossível ir de c a j.
 Poderíamos dizer que dist[j] é infinito nesse caso;  mas é mais limpo e prático dizer que dist[j] vale N,
 pois nenhuma distância "real" pode ser maior que N-1.
 Se tomarmos c igual a 3 no exemplo acima, teremos

 i   		0 	1 	2 	3 	4 	5
 dist[i]  	2 	3 	1 	0 	1 	6
 */
/*
#include "iQueue.h"

#define CIDADES 6

int dist[CIDADES];

void distancias(int rotas[][CIDADES], int origem) {
	iQueue fila;
	int destino;

	for (destino = 0; destino < CIDADES; ++destino)
		dist[destino] = CIDADES;
	dist[origem] = 0;
	init(&fila,1);
	enqueue(&fila, origem);

	while (!isEmpty(&fila)) {
		origem = dequeue(&fila);
		for (destino = 0; destino < CIDADES; ++destino)
			if (rotas[origem][destino] == 1 && dist[destino] >= CIDADES) {
				dist[destino] = dist[origem] + 1;
				enqueue(&fila, destino);
			}
	}
}

int main() {
	int rotas[CIDADES][CIDADES] = {
		  	{0, 1, 0, 0, 0, 0},
		  	{0,	0, 1, 0, 0,	0},
		  	{0,	0, 0, 0, 1, 0},
		   	{0, 0, 1, 0, 1, 0},
		   	{1, 0, 0, 0, 0, 0},
		   	{0, 1, 0, 0, 0, 0}
	};
	int cidadeOrigem = 3;
	distancias(rotas,cidadeOrigem);
	printf("Distância da Cidade %i para:\n\n",cidadeOrigem);
	for (int cidadeDestino = 0; cidadeDestino < CIDADES; cidadeDestino++) {
		printf("Cidade %d -> %d Km\n", cidadeDestino, dist[cidadeDestino]);
	}
}
*/
