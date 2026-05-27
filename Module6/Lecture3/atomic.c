#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define N_CHILDREN 16
#define N_WRITES 256

char *uint32_to_str(uint32_t i, int *length) {
   *length = snprintf(NULL, 0, "%lu", (unsigned long) i); // pretend to print to a string to get length

   char* str = malloc(sizeof(char) * ((*length) + 1)); // allocate space for the actual string

   snprintf(str, ((*length) + 1), "%lu", (unsigned long)i); // print to string

   return str;
}

int main(void) {
    int children[N_CHILDREN];
    bool parent = true;
    for (int i = 0; i < N_CHILDREN; i++) {
        children[i] = fork();
        if (children[i] == 0) {
            parent = false;
            break;
        }
    }

    if (!parent) {
        //int fd = open("file.txt", O_WRONLY | O_CREAT, S_IRWXU);
        int fd = open("file.txt", O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);

        for (int i = 0; i < N_WRITES; i++) {
            int length;
            char *text = uint32_to_str(i, &length);
            text[length] = '\n';

            // lseek(fd, 0, SEEK_END);
            write(fd, text, sizeof(char) * (length + 1));

            free(text);
        }

        close(fd);
    } else {
        for (int i = 0; i < N_CHILDREN; i++) {
            waitpid(children[i], NULL, 0);
        }
    }

    return 0;
}