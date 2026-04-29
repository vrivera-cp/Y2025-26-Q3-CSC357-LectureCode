#include <stdlib.h>
#include <stdio.h>

struct course { 
    char *department; 
    int number; 
    char *name; 
};

void display(struct course *course) {
    printf(
        "%s%d - %s\n",
        course->department,
        course->number,
        course->name
    );
}

int main(void) {
    struct course *courses = malloc(sizeof(struct course) * 3);

    return 0;
}