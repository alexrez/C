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
    int x = 1;

/* предполагаем корректную запись вещественного числа */
    while ((*str!='E') && (*str!='e') && (*str!='\0') ){
        if (*str >= '0' && *str <= '9'){
            z = z*10 + (*str - '0');
            i *= 0.1;
        }
        else if (*str == '.')
            i = 1.0;
        else if (*str == '-')
            x = -1;
        else if (*str == 'f' || *str == 'F' )
            z = (float)z;
        ++str;
    }
    z *= x;
    if (i!=0)
        z *= i;
    i = 10.0;
    x = 0;
    while (*str!='\0'){
        if (*str == '-')
            i = 0.1;
        else if (*str >= '0' && *str <= '9')
            x = x*10 + (*str - '0');
        else if (*str == 'f' || *str == 'F' )
            z = (float)z;
        ++str;
    }
    if (x!=0)
        for ( ; x!=0; --x)
            z *= i;
    return z;
}