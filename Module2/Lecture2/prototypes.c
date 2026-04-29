#include <stdio.h>

// int f2(char c); // Prototype

int my_global_value = 100;

void f1() {
    printf("%d\n", f2('A'));
}

int f2(char c) {
    return (int) c;
}

int main(void) {
    f1();

    return 0;
}
