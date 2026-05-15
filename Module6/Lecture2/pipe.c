#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 8

int main(void) {
    int fd[2];

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    char *line = NULL;
    size_t n = 0;

    while (getline(&line, &n, stdin) != -1) {
        if (write(fd[1], line, strlen(line)) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        char buffer[BUFFER_SIZE];

        ssize_t bytes = read(fd[0], buffer, BUFFER_SIZE);

        if (bytes == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }

        fwrite(buffer, 1, bytes, stdout);
    }

    free(line);

    close(fd[0]);
    close(fd[1]);

    return 0;
}