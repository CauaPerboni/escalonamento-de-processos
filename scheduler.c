#include <stdio.h>
#include "scheduler.h"

// Função para trocar dois processos
void swap(Process *a, Process *b) {
    Process temp = *a;
    *a = *b;
    *b = temp;
}

// Função de escalonamento FCFS
void fcfs_scheduling(Process processes[], int n) {
    int current_time = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;

    printf("\nEscalonamento FCFS:\n");
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = current_time - processes[i].arrival_time;

        if (processes[i].waiting_time < 0) {
            processes[i].waiting_time = 0;
        }

        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        printf("Processo %d: Tempo de Espera = %d, Turnaround = %d\n",
               processes[i].id, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nTempo médio de espera: %.2f\n", total_waiting_time / n);
    printf("Tempo médio de turnaround: %.2f\n", total_turnaround_time / n);
}

// Função de escalonamento SJN
void sjn_scheduling(Process processes[], int n) {
    int current_time = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;

    // Ordena os processos pelo tempo de burst (Shortest Job First)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[j].burst_time < processes[i].burst_time) {
                swap(&processes[j], &processes[i]);
            }
        }
    }

    printf("\nEscalonamento SJN:\n");
    for (int i = 0; i < n; i++) {
        processes[i].waiting_time = current_time - processes[i].arrival_time;

        if (processes[i].waiting_time < 0) {
            processes[i].waiting_time = 0;
        }

        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
        current_time += processes[i].burst_time;
        total_waiting_time += processes[i].waiting_time;
        total_turnaround_time += processes[i].turnaround_time;

        printf("Processo %d: Tempo de Espera = %d, Turnaround = %d\n",
               processes[i].id, processes[i].waiting_time, processes[i].turnaround_time);
    }

    printf("\nTempo medio de espera: %.2f\n", total_waiting_time / n);
    printf("Tempo medio de turnaround: %.2f\n", total_turnaround_time / n);
}

// Função de escalonamento Round Robin
void round_robin_scheduling(Process processes[], int n, int quantum) {
    int current_time = 0;
    float total_waiting_time = 0, total_turnaround_time = 0;
    int remaining_time[n];

    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].burst_time; // Inicializa o tempo restante
    }

    printf("\nEscalonamento Round Robin (Quantum = %d):\n", quantum);
    int done = 0;

    while (done < n) {
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                if (remaining_time[i] > quantum) {
                    current_time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    current_time += remaining_time[i];
                    processes[i].waiting_time = current_time - processes[i].arrival_time - processes[i].burst_time;
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    total_waiting_time += processes[i].waiting_time;
                    total_turnaround_time += processes[i].turnaround_time;
                    remaining_time[i] = 0;
                    done++;
                    printf("Processo %d: Tempo de Espera = %d, Turnaround = %d\n",
                           processes[i].id, processes[i].waiting_time, processes[i].turnaround_time);
                }
            }
        }
    }

    printf("\nTempo médio de espera: %.2f\n", total_waiting_time / n);
    printf("Tempo médio de turnaround: %.2f\n", total_turnaround_time / n);
}
