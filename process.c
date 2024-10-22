#include <stdio.h>
#include "process.h"

// Função para criar um novo processo
Process create_process(int id, int burst_time, int arrival_time, int priority) {
    Process p;
    p.id = id;
    p.burst_time = burst_time;
    p.arrival_time = arrival_time;
    p.priority = priority;
    p.waiting_time = 0;
    p.turnaround_time = 0;
    return p;
}

// Função para imprimir informações de um processo
void print_process(Process p) {
    printf("Process ID: %d | Burst Time: %d | Arrival Time: %d | Priority: %d\n", 
           p.id, p.burst_time, p.arrival_time, p.priority);
}
