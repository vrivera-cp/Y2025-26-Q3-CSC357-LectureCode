#include <stdio.h>

#include "add.h"

extern int my_global;

int main() {
    int sum = add(my_global, 2);

    printf("%d\n", sum);

    return 0;
}
