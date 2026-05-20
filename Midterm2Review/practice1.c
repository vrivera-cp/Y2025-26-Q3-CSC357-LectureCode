#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("0\n");
    fork();
    printf("1\n");
    fork();
    printf("2\n");
    fork();
    return 0;
}