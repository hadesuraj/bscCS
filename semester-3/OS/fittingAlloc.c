#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int size;
} Process;

void firstFit(int memory[], int memSize, Process processes[], int procCount) {
    for (int i = 0; i < procCount; i++) {
        int j;
        for (j = 0; j < memSize; j++) {
            if (memory[j] >= processes[i].size) {
                memory[j] -= processes[i].size;
                printf("Process %d allocated at block %d\n", processes[i].id, j);
                break;
            }
        }
        if (j == memSize) {
            printf("Process %d cannot be allocated\n", processes[i].id);
        }
    }
}

void bestFit(int memory[], int memSize, Process processes[], int procCount) {
    for (int i = 0; i < procCount; i++) {
        int bestIdx = -1;
        for (int j = 0; j < memSize; j++) {
            if (memory[j] >= processes[i].size && (bestIdx == -1 || memory[j] < memory[bestIdx])) {
                bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            memory[bestIdx] -= processes[i].size;
            printf("Process %d allocated at block %d\n", processes[i].id, bestIdx);
        } else {
            printf("Process %d cannot be allocated\n", processes[i].id);
        }
    }
}

void worstFit(int memory[], int memSize, Process processes[], int procCount) {
    for (int i = 0; i < procCount; i++) {
        int worstIdx = -1;
        for (int j = 0; j < memSize; j++) {
            if (memory[j] >= processes[i].size && (worstIdx == -1 || memory[j] > memory[worstIdx])) {
                worstIdx = j;
            }
        }
        if (worstIdx != -1) {
            memory[worstIdx] -= processes[i].size;
            printf("Process %d allocated at block %d\n", processes[i].id, worstIdx);
        } else {
            printf("Process %d cannot be allocated\n", processes[i].id);
        }
    }
}

int main() {
    int MEMORY_SIZE, PROCESS_COUNT;

    printf("Enter the number of memory blocks: ");
    scanf("%d", &MEMORY_SIZE);

    int memory[MEMORY_SIZE];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < MEMORY_SIZE; i++) {
        scanf("%d", &memory[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &PROCESS_COUNT);

    Process processes[PROCESS_COUNT];
    printf("Enter process ID and size for each process:\n");
    for (int i = 0; i < PROCESS_COUNT; i++) {
        scanf("%d %d", &processes[i].id, &processes[i].size);
    }

    printf("First Fit:\n");
    firstFit(memory, MEMORY_SIZE, processes, PROCESS_COUNT);

    printf("\nBest Fit:\n");
    bestFit(memory, MEMORY_SIZE, processes, PROCESS_COUNT);

    printf("\nWorst Fit:\n");
    worstFit(memory, MEMORY_SIZE, processes, PROCESS_COUNT);

    return 0;
}

