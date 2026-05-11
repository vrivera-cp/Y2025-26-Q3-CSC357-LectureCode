#include <stdio.h>

#define BUFFER_SIZE 3

int main(int argc, char *argv[]) {
    FILE *file = fopen(argv[1], "r");


    // Types from man:
    //   _IONBF unbuffered
    //   _IOLBF line buffered
    //   _IOFBF

    char buffer[BUFFER_SIZE] = {};
    setvbuf(stdout, buffer, _IONBF, BUFFER_SIZE);

    int character;
    while ((character = fgetc(file)) != EOF) {
        putchar(character);
    }

    fclose(file);

    return 0;
}