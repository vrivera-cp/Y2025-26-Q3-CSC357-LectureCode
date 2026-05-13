#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

int main(void) {
    pid_t pid = fork();
    if (pid == 0) {
        printf("I am the child (%d) with parent (%d)!\n", getpid(), getppid());
    } else if (pid > 0) {
        printf("I am the parent (%d)!\n", getpid());
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    return 0;
}