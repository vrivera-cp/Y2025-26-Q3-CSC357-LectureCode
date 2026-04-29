#include <stdio.h>

#define MAX_VALUE 999

int main(void) {
    int x = 100;

    int y = 200;

    x = y = MAX_VALUE;

    printf("%d %d\n", x, y);

    return 0;
}
