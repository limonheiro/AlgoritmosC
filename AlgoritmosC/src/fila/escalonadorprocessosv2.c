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
 * Considerar que existem N CPUs, cada uma possui fila própria onde os processos são alocados de acordo com o time-sharing mais otimizado para aquele processo.
 *
 */

#include "processoQueue.h"

#define CPUS 2

typedef struct cpu {
	int id;
	int tempoCompartilhamento;
	processo processo;
	processoQueue fila;
}cpu;

int algumProcessoExecutando(cpu cpus[]) {
	for (int i = 0; i < CPUS; i++) {
		if (!isEmpty(&(cpus[i].fila))) {
			return 1;
		}
	}

	for (int i = 0; i < CPUS; i++) {
		if (cpus[i].processo.tempoProcessado<cpus[i].processo.tempoDuracao)
			return 1;
	}
	return 0;
}

void alocarProcesso(cpu *cpu, processoQueue *fila, processoQueue *historico) {
	if (cpu->processo.tempoProcessado < cpu->processo.tempoDuracao) {
		enqueue(fila,cpu->processo);
	} else {
		if (cpu->processo.id>0) enqueue(historico,cpu->processo); // sem a condição a primeira chamada ao procedimento tenta jogar no historico o processo que esta na cpu, mas nao tem ninguem antes do primeiro processo alocado
		cpu->processo.id=0; //para garantir que ao final do programa as cpus sem processo em execução estejam com p.id=0
	}
	cpu->processo = dequeue(fila);
	cpu->processo.numAlocacoes++;
}

void inicializarCPUS(cpu cpus[]) {
	for (int i = 0; i < CPUS; i++) {
		init(&(cpus[i].fila),CPUS+1);
		cpus[i].id = i;
		cpus[i].tempoCompartilhamento = (i*10)+10;
	}
}

int cpuTempoEsperaFila(cpu *cpu) {
	return size(&(cpu->fila))*cpu->tempoCompartilhamento;
}

int cpuTempoProcessamento (cpu *cpu) {
	int acumuladorTempo = 0;
	if (!isEmpty(&(cpu->fila)))
		for (int i = 0; i < size(&(cpu->fila)); i++)
			acumuladorTempo+=get(&(cpu->fila),i).tempoDuracao-get(&(cpu->fila),i).tempoProcessado;
	return acumuladorTempo;
}

int cpuReceberProcesso(cpu cpus[CPUS]) {
	int cpuMenorTempo = 99999999;
	int cpu = 0;
	for (int i = 0; i < CPUS ; i++) {
		int cpuTempo = cpuTempoProcessamento(&cpus[i]);
		if (cpuTempo < cpuMenorTempo) {
			cpuMenorTempo = cpuTempo;
			cpu = i;
		}
	}
	return cpu;
}

int main() {
	processoQueue fila,historico; //a primeira fila representa os processos em estado de pronto para execução e a segunda os processos que foram finalizados
	init(&fila,1);
	init(&historico,2);

	enqueue(&fila,(processo){1,15,0,0});
	enqueue(&fila,(processo){2,20,0,0});
	enqueue(&fila,(processo){3,10,0,0});
	enqueue(&fila,(processo){4,30,0,0});
	enqueue(&fila,(processo){5,35,0,0});
	enqueue(&fila,(processo){6,25,0,0});
	enqueue(&fila,(processo){7,50,0,0});
	enqueue(&fila,(processo){8,05,0,0});
	enqueue(&fila,(processo){9,20,0,0});

	cpu cpus[CPUS];

	inicializarCPUS(cpus);

	int tempo=0;

	//dividindo a fila de processos
	while (!isEmpty(&fila)) {
		enqueue(&(cpus[cpuReceberProcesso(cpus)].fila),dequeue(&fila));
	}

	while (algumProcessoExecutando(cpus)) {

		for (int i = 0; i < CPUS; i++) {
			if ((tempo%cpus[i].tempoCompartilhamento)==0 && !isEmpty(&(cpus[i].fila))) {
				printf("CPU %d:\tPID: %d\t TIME: %d\n",i+1,peek(&fila).id,tempo);
				alocarProcesso(&cpus[i],&(cpus[i].fila),&historico);
			}

			cpus[i].processo.tempoProcessado++;
		}

		tempo++;
	}

	//serve para tirar o ultimo processo em execução no processador e guardar no historico
	for (int i = 0; i < CPUS; i++)
		if (cpus[i].processo.id>0)
			enqueue(&historico,cpus[i].processo);

	printf("Tempo total de processamento: %d\n",tempo);
	printf("\n\n");

	while (!isEmpty(&historico)) {
		processo p = dequeue(&historico);
		printf("PID: %d\tNum. Alocacoes: %d\tTempo gasto: %d\t\tTempo ocioso :%d\n",p.id,p.numAlocacoes,p.tempoProcessado, p.tempoProcessado-p.tempoDuracao);
	}

	return 0;
}

