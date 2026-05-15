#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define BUFFER_SIZE 8

int main(void) {
    int fd[2];

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int pid = fork();


    if (pid == 0) {
        close(fd[1]);

        ssize_t bytes;
        char buffer[BUFFER_SIZE];

        while((bytes = read(fd[0], buffer, BUFFER_SIZE)) != 0) {

            if (bytes == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            fwrite(buffer, 1, bytes, stdout);
        }

        close(fd[0]);

        return 0;
    } else {
        close(fd[0]);

        char *line = NULL;
        size_t n = 0;

        while (getline(&line, &n, stdin) != -1) {
            if (write(fd[1], line, strlen(line)) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        free(line);

        // close(fd[1]);
        wait(NULL);

        return 0;
    }
    return 0;
}