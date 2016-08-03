/*
 * producaohamburguer.c
 *
 *  Created on: 20 de jul de 2016
 *      Author: joaopaulodelgadopreti
 *
 *  Uma produção de hamburguer estilo Mac Donalds, Burguer King, ...
 *  Cada funcionario é responsável pela montagem de uma parte do produto,
 *  ou seja, cada funcionário tem sua própria lista de elementos para produzir
 *  (um que recebe os hamburguers crus para colocar na chapa, outro que deve montar, outro que deve entregar, ...
 *  Cada tipo de hamburguer tem sua propria fila de produção.
 *  A ideia é que existam diversas filas e que os produtos possam estar em mais de uma fila possivelmente.
 *
 * One example which comes to my mind is a hamburger processing line in e.g. McDonalds.
 * There are several kinds of different burguers, each may be produced by several different workers and each has its own queue. From there, after a while the ready burgers are taken, in FIFO order, by one of the cashiers who ordered that kind of a burger.
 * So there are multiple producers and consumers, and each queue is bounded.
 *
 * 1. Pedido
 * Assim que o caixa registra o pedido, outro funcionário, chamado de "apoio", passa o recado para a cozinha, e a tostadeira, a estação de condimentos e a chapa entram em ação simultânea. O apoio também é encarregado da porção de fritas.
 *
 * 2. Tostadeira
 * A máquina funciona como uma torradeira gigante, que avisa quando o pão está no ponto.
 *
 * 3. Condimentos
 * Aqui, o pão quentinho recebe picles, cebola, molho, queijo etc.
 *
 * 4. Carnes
 * Enquanto o pão é tostado e preparado, as chapas já estão quentes. São uma para hambúrgueres normais e outra para os grandes.
 *
 * 5. Montagem
 * A bordo de uma bandeja móvel, os pães chegam à estação da chapa. O sanduíche é montado e vai para a embalagem.
 *
 * 6. Finalização
 * O funcionário que atende por "produção final" checa o sanduíche antes de ele ir para a estufa. Lanches "descaracterizados" (muita alface, queijo na ordem errada) vão para o lixo.
 *
 */


