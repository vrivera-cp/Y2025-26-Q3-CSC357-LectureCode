#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

int main(void) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        printf("I am the sleepy parent (%d)\n", getpid());
        sleep(10);
        printf("The parent awakens!\n");
    } else if (pid == 0) {
        printf("I am the child (%d)\n", getpid());
    }

    return 0;
}