#include <stdio.h>

#define MAX_PROCESSES 10

typedef struct {
    int id;
    int priority;
    int burst_time;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int completed;
} Process;

int find_highest_priority(Process processes[], int n) {
    int highest_priority = -1;
    int highest_priority_idx = -1;
    for (int i = 0; i < n; i++) {
        if (!processes[i].completed && processes[i].priority > highest_priority) {
            highest_priority = processes[i].priority;
            highest_priority_idx = i;
        }
    }
    return highest_priority_idx;
}

void calculate_times(Process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        int idx = find_highest_priority(processes, n);
        if (idx == -1) {
            current_time++;
            continue;
        }

        if (processes[idx].remaining_time == processes[idx].burst_time) {
            processes[idx].waiting_time = current_time;
        }

        processes[idx].remaining_time--;
        current_time++;

        if (processes[idx].remaining_time == 0) {
            processes[idx].turnaround_time = current_time;
            processes[idx].completed = 1;
            completed_processes++;
        }
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
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completed = 0;
    }

    calculate_times(processes, n);

    printf("\nProcess ID\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].priority,
               processes[i].burst_time, processes[i].waiting_time, processes[i].turnaround_time);
    }

    return 0;
}

