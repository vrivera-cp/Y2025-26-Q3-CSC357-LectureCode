#include <stdio.h>

int add(int a, int b);

int main(void) {
    int result = add(5, 3);
    printf("%d\n", result);
    return 0;
}

int add(int a, int b) {
    return a + b;
}
