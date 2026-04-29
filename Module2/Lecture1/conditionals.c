#include <stdio.h>

enum day {SUN = 0, MON, TUE, WED, THU, FRI, SAT};
enum day today = WED;

int main(void) {
    today = today + 7;
    if (today == SUN)
        printf("Happy new week!\n");
    else if (today == SAT)
        printf("Happy weekend!\n");
    else
        printf("Good morning!\n");

    printf("%d\n", today);

    return 0;
}
