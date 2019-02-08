#include <stdio.h>

#define MAXLINE 1000
double str2double(char str[]);

int main() {
    char inp_str[MAXLINE];
    while (scanf("%s", inp_str)!=EOF)
        printf("%.10g\n", str2double(inp_str));
    return 0;
}
double str2double(char str[]){
    double z = 0.0;
    double i = 0.0;
    double e_pow = 10;
    int pow = 0;
    int sign_z = 1;
    int state = 0;

/* предполагаем корректную запись вещественного числа */
    while (*str!='\0'){
        if (*str >= '0' && *str <= '9'){
            if (state == 0) {
                z = z * 10 + (*str - '0');
                i *= 0.1;
            }
            else pow = pow*10 + (*str - '0');
        }
        else if (*str == '.')
            i = 1.0;
        else if (*str == '-') {
            if (state == 0)
                sign_z = -1;
            else e_pow = 0.1;
            }
        else if (*str == 'e' || *str == 'E' )
            state = 1;
        else if (*str == 'f' || *str == 'F' )
            z = (float)z;
        ++str;
    }
    z *= sign_z;
    if (i!=0)
        z *= i;
    if (pow!=0)
        for ( ; pow!=0; --pow)
            z *= e_pow;
    return z;
}