#include <stdio.h>

void calculateWaitingTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    wt[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];

    // Calculate turnaround time
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void calculateAverageTime(int n, int at[], int bt[]) {
    int wt[n], tat[n];

    calculateWaitingTurnaroundTime(n, bt, wt, tat);

    float total_wt = 0, total_tat = 0;

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Print average waiting time and average turnaround time
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

int main() {
    int n;

    // Get the number of processes from the user
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int arrivalTime[n], burstTime[n];

    // Get arrival times and burst times for each process from the user
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);

        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    // Calculate and display average waiting time and average turnaround time
    calculateAverageTime(n, arrivalTime, burstTime);

    return 0;
}
