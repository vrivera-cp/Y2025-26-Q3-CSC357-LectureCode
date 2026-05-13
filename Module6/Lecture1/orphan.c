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
        printf("I am the parent (%d)\n", getpid());
        sleep(1);
    } else if (pid == 0) {
        printf("I am the sleepy child (%d) with parent (%d)\n", getpid(), getppid());
        sleep(10);
        printf("The child awakens! I have parent (%d)\n", getppid());
    }

    return 0;
}