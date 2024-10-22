#ifndef PROCESS_H
#define PROCESS_H

typedef struct {
    int id;             // ID do processo
    int burst_time;     // Tempo de execução (Burst Time)
    int arrival_time;   // Tempo de chegada
    int priority;       // Prioridade do processo (para algoritmos com prioridade)
    int waiting_time;   // Tempo de espera (será calculado)
    int turnaround_time;// Tempo de turnaround (será calculado)
} Process;

// Função para criar um novo processo
Process create_process(int id, int burst_time, int arrival_time, int priority);

// Função para imprimir informações de um processo
void print_process(Process p);

#endif
