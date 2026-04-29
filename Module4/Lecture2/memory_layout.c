#include <stdint.h>

struct person {
    uint64_t birth_year;
    char first_initial;
    uint64_t age;
};

int main(void) {
    struct person p = {2007, 'a', 'b', 18};

    return 0;
}