#include <string.h>

int main()
{
    char *greeting = "Hello";
    char welcome[] = "Hello";
    char salutation[32] = "Hello";
    char *hi = strdup(salutation);

    welcome[0] = 'J';

    greeting[0] = 'J';

    return 0;
}