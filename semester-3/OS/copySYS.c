#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int source_fd = open(argv[1], O_RDONLY);
    if (source_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char buf[BUF_SIZE];
    ssize_t bytes_read, bytes_written;
    while ((bytes_read = read(source_fd, buf, BUF_SIZE)) > 0) {
        bytes_written = write(dest_fd, buf, bytes_read);
        if (bytes_written != bytes_read) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    if (close(source_fd) == -1 || close(dest_fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}

