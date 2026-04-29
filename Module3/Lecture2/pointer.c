#include <stdlib.h>

void mutation(int *pointer)
{
    *pointer = *pointer + 1;
}

int main(void)
{
    int x = 1;

    int *address_of_x = NULL;

    x = 2;

    *address_of_x = 3;

    mutation(&x);
    mutation(address_of_x);

    return 0;
}