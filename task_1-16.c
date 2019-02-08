#include <stdio.h>
#include <math.h>

int main() {
    float X;
    double D;
    long double LD;

    signed short SS;
    signed int SI;
    signed long SL;

    double N_SS;
    double N_SI;
    double N_SL;

    printf("Size of  signed short: %lu\n", sizeof(SS));
    N_SS = pow(2.0, (double)((sizeof(SS)-1)*8));
    printf("2 powered by (N-1): %lf\n", N_SS);

    printf("Size of  signed int: %lu\n", sizeof(SI));
    N_SI = pow(2.0, (double)((sizeof(SI)-1)*8));
    printf("2 powered by (N-1): %lf\n", N_SI);

    printf("Size of  signed long: %lu\n", sizeof(SL));
    N_SL = pow(2.0, (double)((sizeof(SL)-1)*8));
    printf("2 powered by (N-1): %lf\n", N_SL);

    while (scanf("%Lf", &LD)!=EOF) {
        printf("For float X:\n");
        X = (float)LD;

        printf("To convert X into signed short integer, \n");
        if (fabs((double)X) < N_SS)
            printf("For |X| < 2**(N-1)\n");
        else printf("For |X| >= 2**(N-1)\n");
        printf("We've got %d\n", SS = X);

        printf("To convert X into signed integer\n");
        if (fabs((double)X) < N_SI)
            printf("For |X| < 2**(N-1)\n");
        else printf("For |X| >= 2**(N-1)\n");
        printf("We've got %d\n", SI = X);

        printf("To convert X into signed long integer\n");
        if (fabs((double)X) < N_SL)
            printf("For |X| < 2**(N-1)\n");
        else printf("For |X| >= 2**(N-1)\n");
        printf("We've got %ld\n", SL = X);

        printf("\nFor double X:\n");
        D = (double)LD;

        printf("To convert X into signed short integer, \n");
        if (fabs(D) < N_SS)
            printf("For |X| < 2**(N-1)\n");
        else printf("For |X| >= 2**(N-1)\n");
        printf("We've got %d\n", SS = D);

        printf("To convert X into signed integer\n");
        if (fabs(D) < N_SI)
            printf("For |X| < 2**(N-1)\n");
        else printf("For |X| >= 2**(N-1)\n");
        printf("We've got %d\n", SI = D);

        printf("To convert X into signed long integer\n");
        if (fabs(D) < N_SL)
            printf("For |X| < 2**(N-1)\n");
        else printf("For |X| >= 2**(N-1)\n");
        printf("We've got %ld\n", SL = D);

        printf("\nFor long double X:\n");

        printf("To convert X into signed short integer, \n");
        if (fabs(LD) < (long double)N_SS)
            printf("For |X| < 2**(N-1)\n");
        else printf("For |X| >= 2**(N-1)\n");
        printf("We've got %d\n", SS = LD);

        printf("To convert X into signed integer\n");
        if (fabs(LD) < (long double)N_SI)
            printf("For |X| < 2**(N-1)\n");
        else printf("For |X| >= 2**(N-1)\n");
        printf("We've got %d\n", SI = LD);

        printf("To convert X into signed long integer\n");
        if (fabs(LD) < (long double)N_SL)
            printf("For |X| < 2**(N-1)\n");
        else printf("For |X| >= 2**(N-1)\n");
        printf("We've got %ld\n", SL = LD);
    }
    return 0;
}