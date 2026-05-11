#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
    int fd = open("hello", O_WRONLY | O_CREAT, S_IRWXU);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (write(fd, "hello", sizeof(char) * 5) == -1) {
        perror("write");
        
        if (close(fd) == -1) {
            perror("close");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}