#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int priority;
    int burst_time;
    int waiting_time;
    int turnaround_time;
    int completed;
} Process;

void sort_by_priority(Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].priority > processes[j + 1].priority) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

void calculate_times(Process processes[], int n) {
    processes[0].waiting_time = 0;
    processes[0].turnaround_time = processes[0].burst_time;

    for (int i = 1; i < n; i++) {
        processes[i].waiting_time = processes[i - 1].waiting_time + processes[i - 1].burst_time;
        processes[i].turnaround_time = processes[i].waiting_time + processes[i].burst_time;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_PROCESSES) {
        printf("Invalid input. Exiting...\n");
        return 1;
    }

    Process processes[MAX_PROCESSES];
    printf("Enter process ID, priority, and burst time for each process:\n");
    for (int i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].id, &processes[i].priority, &processes[i].burst_time);
        processes[i].completed = 0;
    }

    sort_by_priority(processes, n);
    calculate_times(processes, n);

    printf("\nProcess ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].priority,
               processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}

