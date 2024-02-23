#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_NUMBERS 100

int numbers[MAX_NUMBERS];
int sum = 0;

void *calculateSum(void *arg) {
    int n = *((int *)arg);
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    return NULL;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_NUMBERS) {
        printf("Invalid input. Exiting...\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    pthread_t thread;
    pthread_create(&thread, NULL, calculateSum, &n);
    pthread_join(thread, NULL);

    printf("Sum of %d numbers is %d\n", n, sum);

    return 0;
}

