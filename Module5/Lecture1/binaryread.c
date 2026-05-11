#include <stdio.h>

struct person {
    char name[16];
    int age;
};

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "rb");

    struct person mochi = {};

    fread(&mochi, sizeof(struct person), 1, file);

    fclose(file);

    return 0;
}