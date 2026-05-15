#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        printf("I am the parent (%d)\n", getpid());
        printf("I am waiting for my child (%d)\n", pid);
        int wstatus;
        wait(&wstatus);
        if (WIFEXITED(wstatus)) {
            printf("I successfully retrieved my child!\n");
        } else {
            printf("Oh, no! Where's my child!?\n");
        }
        printf("I am the sleepy parent (%d)...\n", getpid());
        sleep(10);
    } else if (pid == 0) {
        printf("I am the sleepy child (%d)\n", getpid());
        sleep(10);
        printf("The child awakens!\n");
    }

    return 0;
}