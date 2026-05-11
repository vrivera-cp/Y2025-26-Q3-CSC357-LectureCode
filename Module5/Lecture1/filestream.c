#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    FILE *file = fopen(argv[1], "r");

    char *line = NULL;
    size_t n;

    while (getline(&line, &n, file) != -1) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}