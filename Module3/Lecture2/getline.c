#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *line = NULL;
    size_t n;

    getline(&line, &n, stdin);

    printf("%s", line);

    free(line);
    line = NULL;
    
    printf("%s", line);

    return 0;
}