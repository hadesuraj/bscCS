#include <stdio.h>

void findWaitingTime(int processes[], int n, int bt[], int wt[], int priority[]) {
    wt[0] = 0;

    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
}

void findTurnaroundTime(int processes[], int n, int bt[], int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int processes[], int n, int bt[], int priority[]) {
    int wt[n], tat[n];

    findWaitingTime(processes, n, bt, wt, priority);
    findTurnaroundTime(processes, n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;

    printf("\n| Process | Arrival Time | Burst Time | Priority | Waiting Time | Turnaround Time |\n");
    printf("|---------|--------------|------------|----------|--------------|------------------|\n");

    for (int i = 0; i < n; i++) {
        printf("|   P%d\t|      %d\t\t|     %d\t  |    %d\t |      %d\t\t|         %d        |\n",
               processes[i], processes[i], bt[i], priority[i], wt[i], tat[i]);

        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("-----------------------------------------------------------------------------\n");

    printf("Average Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

void priorityScheduling(int processes[], int n, int bt[], int priority[], int at[]) {
    // Sort processes based on arrival time and priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1] || (at[j] == at[j + 1] && priority[j] > priority[j + 1])) {
                // Swap arrival times
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap priority values
                temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                // Swap process IDs
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;

                // Swap burst times
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    // Calculate and print average waiting time and turnaround time
    findAverageTime(processes, n, bt, priority);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burstTime[n], priority[n], arrivalTime[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &arrivalTime[i]);

        printf("Enter priority for process P%d: ", i + 1);
        scanf("%d", &priority[i]);

        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &burstTime[i]);

        processes[i] = i + 1; // Process IDs are 1, 2, 3, ..., n
    }

    // Calculate and print the table chart
    priorityScheduling(processes, n, burstTime, priority, arrivalTime);

    return 0;
}
