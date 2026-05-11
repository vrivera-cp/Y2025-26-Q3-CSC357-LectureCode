#include <fcntl.h>

int main(void) {
    int x = open("a.out", O_RDONLY);

    return 0;
}