#include <stdio.h>

void findWaitingTurnaroundTime(int n, int bt[], int wt[], int tat[]) {
    wt[0] = 0;

    // Calculate waiting time
    for (int i = 1; i < n; i++)
        wt[i] = bt[i - 1] + wt[i - 1];

    // Calculate turnaround time
    for (int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
}

void findAverageTime(int n, int bt[]) {
    int wt[n], tat[n];

    findWaitingTurnaroundTime(n, bt, wt, tat);

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

void ljfScheduling(int n, int bt[], int at[]) {
    // Sort processes based on arrival time and burst time in descending order (LJF)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] <= at[j + 1] && bt[j] < bt[j + 1]) {
                // Swap arrival times
                int temp_at = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp_at;

                // Swap burst times
                int temp_bt = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp_bt;
            }
        }
    }

    // Calculate waiting time and turnaround time
    int wt[n], tat[n];
    findWaitingTurnaroundTime(n, bt, wt, tat);

    // Print the table chart
    printf("\n| Process | Arrival Time | Burst Time | Waiting Time | Turnaround Time |\n");
    printf("|---------|--------------|------------|--------------|------------------|\n");

    for (int i = 0; i < n; i++) {
        printf("|   P%d\t|      %d\t\t|     %d\t  |      %d\t\t|         %d        |\n",
               i + 1, at[i], bt[i], wt[i], tat[i]);
    }

    printf("-------------------------------------------------------------------------\n");

    // Calculate and print average waiting time and average turnaround time
    findAverageTime(n, bt);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int burstTime[n], arrivalTime[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time for process P%d: ", i + 1);
        scanf("%d", &arrivalTime[i]);

        printf("Enter burst time for process P%d: ", i + 1);
        scanf("%d", &burstTime[i]);
    }

    // Perform LJF scheduling, print the table, and display results
    ljfScheduling(n, burstTime, arrivalTime);

    return 0;
}
