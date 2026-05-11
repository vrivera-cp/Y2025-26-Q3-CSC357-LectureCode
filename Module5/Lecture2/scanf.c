#include <stdio.h>

int main(void) {
    int x;
    char c;
    char text[32] = {};

    printf("%d\n", scanf("%d %c %s", &x, &c, text));

    printf("%d %c %s\n", x, c, text);

    return 0;
}