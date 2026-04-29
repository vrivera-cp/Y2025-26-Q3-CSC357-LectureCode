#include <stdio.h>

struct point {
    int x;
    int y;
};

int main(void) {
    struct point p1 = {1, 2};

    struct point p2 = {};

    struct point p3 = {};

    struct point p4;

    printf("%d %d\n", p1.x, p1.y);
    printf("%d %d\n", p2.x, p2.y);
    printf("%d %d\n", p3.x, p3.y);
    printf("%d %d\n", p4.x, p4.y);

    p4.x = 100;
    p4.y = -100;

    printf("%d %d\n", p4.x, p4.y);

    return 0;
}