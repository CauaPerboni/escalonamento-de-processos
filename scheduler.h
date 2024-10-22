#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "process.h"

// Função para escalonamento FCFS
void fcfs_scheduling(Process processes[], int n);

// Função para escalonamento SJN
void sjn_scheduling(Process processes[], int n);

// Função para escalonamento Round Robin
void round_robin_scheduling(Process processes[], int n, int quantum);

#endif
