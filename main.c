#include <stdio.h>
#include "process.h"
#include "scheduler.h"

int main() {
    int n;

    printf("Digite o número de processos: ");
    scanf("%d", &n);
    
    Process processes[n];

    for (int i = 0; i < n; i++) {
        int id, burst_time, arrival_time, priority;
        printf("Digite os dados do processo %d (ID, Tempo de Burst, Tempo de Chegada, Prioridade): ", i + 1);
        scanf("%d %d %d %d", &id, &burst_time, &arrival_time, &priority);
        processes[i] = create_process(id, burst_time, arrival_time, priority);
    }

    // Executando os escalonamentos
    fcfs_scheduling(processes, n);
    sjn_scheduling(processes, n);
    round_robin_scheduling(processes, n, 2);

    return 0;
}
