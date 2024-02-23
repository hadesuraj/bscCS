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
        execl("/bin/ls", "ls", "-l", NULL); // Example command
        perror("exec");
        exit(EXIT_FAILURE);
    } else {
        // Parent process
        wait(NULL);
        printf("Parent process waiting...\n");
    }

    return 0;
}

