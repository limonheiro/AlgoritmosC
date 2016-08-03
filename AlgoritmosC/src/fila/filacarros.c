/*
 * filacarros.c
 *
 *  Created on: 20 de jul de 2016
 *      Author: joaopaulodelgadopreti
 *
 *  Faça um programa que simule o tráfego de veículos por um semáforo. Considere o seguinte:
 *  a) O semáforo controla duas pistas que se cruzam, e cada uma possui direção única.
 *  b) O semáforo possui apenas as luzes verde e vermelha, levando 15 segundos para cada mudança de luz.
 *  c) A pista por onde o carro vai (1 ou 2) será escolhida aleatoriamente.
 *  d) Cada carro chegará ao semáforo num intervalo (aleatório) de 1 a 30 segundos após outro.
 *  e) Quando o semáforo  estiver  verde,  cada  carro  da  fila  leva  um  tempo  de  3  segundos  após  a  saída  do  carro  da frente para dar partida.
 *  Faça outras considerações que achar necessário.
 *  O programa deve apresentar como saída o movimento no cruzamento a cada instante, mostrando tanto as filas dos carros parados no semáforo, como também os carros que ainda irão chegar ao cruzamento.
 *  Sugestões:
 *  - Inicialmente, gere todos os possíveis carros que irão chegar ao semáforo, colocando-os em 2 filas: uma para a pista 1 e outra para a pista 2.
 *  - Os carros podem ser identificados pelo seu tempo previsto de chegada ao cruzamento.
 *  - Use filas também para os carros que estão parados no semáforo.
 *  - Apresente na tela o máximo de controles possíveis (contadores, flags, etc) que você estiver usando, para facilitar o acompanhamento da simulação.
 */


