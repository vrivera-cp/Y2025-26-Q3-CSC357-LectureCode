#include <stdlib.h>

int main() {
    int *x;

    x = malloc(sizeof(int));
    *x = 100;

    x = malloc(4 * sizeof(int));
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    x[3] = 4;

    x = realloc(x, sizeof(int) * 8);
    x[4] = 5;
    x[5] = 6;
    x[6] = 7;
    x[7] = 8;

    free(x);
    
    return 0;
}