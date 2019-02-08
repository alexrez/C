#include <stdio.h>

double absol(double Xi, double Xi1) {
    return Xi>Xi1?(Xi-Xi1):(Xi1-Xi);
}

double sqroot (double x, double eps) {
    double x0, x1;
    x0=1;
    x1 = 0.5*(x0 + x/x0);
    while (absol(x0, x1) >= eps) {
        x0 = x1;
        x1 = 0.5*(x0 + x/x0);
    }
    return x1;
}

int main() {
    double x, eps;

    printf("enter Epsilon: \n");
    scanf("%lf", &eps);

    printf("enter x: \n");
    while (scanf("%lf", &x) != EOF) {
        if (x>0)
            printf("sqrt = %.10g\n", sqroot(x, eps));
        else printf("Choose another x.\n");
    }

    return 0;
}