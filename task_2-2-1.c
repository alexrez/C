#include <stdio.h>

int main() {
    double x, a, y;
    y = 0;
    scanf("%lf", &x);
    while (scanf("%lf", &a) != EOF)
        y = a + y*x;
    printf("%lf\n", y);
    return 0;
}