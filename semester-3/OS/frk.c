#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pid = fork();
    
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process executing same program, same code.\n");
    } else {
        // Parent process
        wait(NULL);
        printf("Parent process waiting...\n");
    }

    return 0;
}

