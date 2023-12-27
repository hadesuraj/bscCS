#include <stdio.h>
void calculateWaitingTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}
void calculateAverageTime(int n, int at[], int bt[]) {
    int wt[n], tat[n];
    calculateWaitingTurnaroundTime(n, bt, wt, tat);
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}
int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int arrivalTime[n], burstTime[n];
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }
    calculateAverageTime(n, arrivalTime, burstTime);
    return 0;
}
