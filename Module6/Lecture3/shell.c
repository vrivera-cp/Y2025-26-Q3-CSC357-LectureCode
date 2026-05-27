#define _GNU_SOURCE
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main(void) {
    char *line = NULL;
    size_t n = 0;
    while (getline(&line, &n, stdin) != -1) {

        pid_t pid = fork();
        if (pid > 0) {
            wait(NULL);
        } else if (pid == 0) {
            line[strlen(line) - 1] = '\0';
            
            char *args[2] = {NULL, NULL};

            args[0] = line;

            execvp(line, args);
        }
    }

    return 0;
}