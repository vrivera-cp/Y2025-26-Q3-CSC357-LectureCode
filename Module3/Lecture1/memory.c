#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>

int global_variable = 10;
int uninitialized_global;

int function(int x)
{
    int y = x + 1;
    return y;
}

int main(int argc, char **argv)
{
    char *name = "Mochi";
    char *duplicated = strdup(name); // MEMORY LEAK!

    int x = function(10);

    printf("%s %s %d\n", name, duplicated, x);

    return 0;
}