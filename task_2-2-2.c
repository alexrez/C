#include <stdio.h>

int main() {
    double x, a, y;
    double f;
    y = 0;
    f = 0;

    scanf("%lf", &x);
    while (scanf("%lf", &a) != EOF) {
        f = f*x + y;
        y = a + y*x;
    }
    printf("%lf\n", y);
    printf("%lf\n", f);
    return 0;
}