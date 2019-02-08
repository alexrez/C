#include <stdio.h>
#include <math.h>

int main() {

    unsigned short US;
    unsigned int UI;
    unsigned long UL;


    printf("Size of  unsigned short: %lu\n", sizeof(US));
    printf("Size of  unsigned int: %lu\n", sizeof(UI));
    printf("Size of  unsigned long: %lu\n", sizeof(UL));

    US = 127;
    printf("\nFor short X = %d\n", US);
    printf("To convert X into short (N == M): %d\n", US = US);
    printf("To convert X into integer or long (N > M): %u, %ld\n", UI = US, UL = US);

    UI = 7840;
    printf("\nFor integer X = %u\n", UI);
    printf("To convert X into short (N < M): %d\n", US = UI);
    printf("To convert X into integer (N == M): %u\n", UI = UI);
    printf("To convert X into long (N > M): %ld\n", UL = UI);

    UI = 65540;
    printf("\nFor integer X = %u\n", UI);
    printf("To convert X into short (N < M): %d\n", US = UI);
    printf("To convert X into integer (N == M): %u\n", UI = UI);
    printf("To convert X into long (N > M): %ld\n", UL = UI);

    UL = 4294967297;
    printf("\nFor long X = %lu\n", UL);
    printf("To convert X into short or integer (N < M): %d, %u\n", US = UL, UI = UL);
    printf("To convert X into long (N == M): %lu\n", UL = UL);

    return 0;
}