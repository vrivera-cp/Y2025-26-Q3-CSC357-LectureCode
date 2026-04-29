#include <stdio.h>

enum day {SUN = 0, MON, TUE, WED, THU, FRI, SAT};
enum day today = FRI; // Variable Definition

int main(void) {
    
    switch (today) {
        case SUN: printf("Happy new week!\n"); break;
        case SAT: printf("Happy weekend!\n"); break;
        default: printf("Good morning!\n");
    }

    return 0;
}
