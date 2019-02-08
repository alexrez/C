#include <stdio.h>

long fib_iter(int i){
    long f0, f;
    if (i<=0)
        f = 0;
    else {
        f = 1;
        for (f0 = 0; i > 2; i--) {
            f0 = f - f0;
            f = f0 + f;
        }
    }
    return f;
}

long fib_rec(int i){
    long f;
    if (i<=0)
        f=0;
    else {
        f = 1;
        if (i > 2)
            f = fib_rec(i - 2) + fib_rec(i - 1);
    }
    return f;
}

int main() {
    int i;
    while (scanf("%d", &i)!=EOF){
        printf("%ld\n", fib_iter(i));
        printf("%ld\n", fib_rec(i));
    }
    return 0;
}