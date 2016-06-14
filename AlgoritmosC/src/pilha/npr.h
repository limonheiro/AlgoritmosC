/***************************************************************************
 * Biblioteca de Notação Polonesa Reversa                                  *
 *                                                                         *
 * Biblioteca com operações para construção e avaliação da Notação Polonesa*
 * Data: 30/05/2016			                                               *
 * Autor: João Paulo D. Preti                                              *
 ***************************************************************************/

#ifndef NPR_H_
#define NPR_H_

#include "dStack.h"
#include <string.h>
#include <stdlib.h>

char* infixa_posfixa (char infixa[]);
double avalia(char *sentence);

/*
 * Varrer a expressão da esquerda para a direita e, para cada símbolo:
 * a) Se for operando, copiá-lo para a expressão posfixa (saída);
 * b) Se for operador:
 *       1. enquanto a pilha não estiver vazia e houver no seu topo
 *          um operador com prioridade maior ou igual ao encontrado, desempilhe o
 *          operador e copie-o na saída;
 *       2. Empilhe o operador encontrado;
 * c) Ao encontrar um parêntese de abertura, empilhe-o;
 * d) Se for parêntese de fechamento, remova um símbolo da pilha e copie-o na
 *    saída, até que seja desempilhado o parêntese de abertura correspondente.
 * e) Ao final da varredura, esvazie a pilha, movendo os símbolos para a saída
 */

char* infixa_posfixa (char infixa[]){

}

/*
 * Varrer a expressão e para cada elemento encontrado:
 * a) Se for operando, empilhe seu valor;
 * b) Se for operador, desempilhar os dois últimos valores, efetuar a operação
 *    com eles e empilhar de volta o resultado obtido;
 * c) No final do processo o resultado estará no topo da pilha.
 */

double avalia(char *sentence) {


}

#endif /* NPR_H_ */



