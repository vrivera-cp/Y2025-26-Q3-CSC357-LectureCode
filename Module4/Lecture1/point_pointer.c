#include <stdio.h>

struct point {
    int x;
    int y;
};

int main(void) {
    struct point p = {10, 20}; 
    
    struct point *pp; 
    pp = &p;

    (*pp).x = 20; 
    pp->y = 40; 
    printf("(%d, %d)\n", pp->x, pp->y);

    return 0;
}