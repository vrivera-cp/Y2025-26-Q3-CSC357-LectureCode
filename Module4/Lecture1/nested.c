#include <stdio.h>


struct point {
    int x;
    int y;
};

struct rectangle { 
    struct point upper_left; 
    struct point lower_right; 
};

int main(void) {
    struct rectangle rect = {{0, 0}, {100, 100}}; 
    int width = rect.lower_right.x - rect.upper_left.x;

    printf("Width: %d\n", width);

    return 0;
}