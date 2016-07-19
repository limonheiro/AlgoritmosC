/*
 * escalonadorprocessos.c
 *
 *  Created on: 11 de jul de 2016
 *      Author: joaopaulodelgadopreti
 *
 * Fonte: Wikipedia
 *
 * Os algoritmos preemptivos permitem que um processo seja interrompido durante sua
 * execução, quer seja por força de uma interrupção de entrada/saída, quer seja
 * em decorrência da politica de escalonamento adotada e aplicada por parte do
 * escalonador de processos ou simplesmente por força do término da execução do processo.
 * Após a interrupção deste processo, ocorre o que se chama de troca de contexto,
 * que consiste em salvar o conteúdo dos registradores e a memoria utilizada pelo
 * processo e conceder a outro processo o privilégio de executar na CPU, restaurando
 * assim o contexto deste ultimo processo.
 * Exemplos de Algoritmos:
 * FIFO (First in, first out) ou FCFS (First come, first served): Onde como seu próprio nome já diz, o primeiro que chega será o primeiro a ser executado;
 * SJF (Shortest Job First): Onde o menor processo ganhará a CPU e atrás do mesmo formar uma fila de processos por ordem crescente de tempo de execução;
 * SRT (Shortest Remaining Time): Neste algoritmo é escolhido o processo que possua o menor tempo restante, mesmo que esse processo chegue à metade de uma operação, se o processo novo for menor ele será executado primeiro;
 * Algoritmo Loteria: O Sistema Operacional distribui tokens (fichas), numerados entre os processos, para o escalonamento é sorteado um numero aleatório para que o processo ganhe a vez na CPU, processos com mais tokens têm mais chance de receber antes a CPU.
 * Escalonamento garantido: Este algoritmo busca cumprir promessas de alocação de CPU o mais preciso possível.
 * RR (Round-Robin): Nesse escalonamento o sistema operacional possui um timer, chamado de quantum, onde todos os processos ganham o mesmo valor de quantum para rodarem na CPU. Com exceção do algoritmo RR e escalonamento garantido, todos os outros sofrem do problema de Inanição (starvation).
 * Múltiplas Filas: São usadas várias filas de processos prontos para executar, cada processo e colocado em uma fila, e cada fila tem uma política de escalonamento própria e outra entre filas.
 *
 * Implemente um escalonador de processos do tipo RR. Considere apenas o tempo que o processo levará
 * para concluir seu processamento. Salvar os registradores neste caso implica em salvar
 * quanto tempo de processamento foi realizado para aquele processo.
 *
 */


