#include <stdio.h>
#include <setjmp.h>

jmp_buf begin;

char curlex;

void getlex(void);

int expr(void);

int add(void);

int calc_pow(void);

int mult(void);

void error();


main(){
    int result;
    setjmp(begin);
    printf("==>");
    getlex();
    result=expr();
    if (curlex != '\n'){
        error();
    }
    printf("\n%d\n",result);
    return 0;
}

void getlex(){
    while ( (curlex = getchar()) == ' ' );
}

void error(void){
    printf("\nERROR!\n");
    while(getchar()!='\n'){};
    longjmp(begin,1);
}

int expr(){
    int e = add();
    while (curlex == '+' || curlex == '-'){
        if (curlex == '+'){
            getlex();
            e += add();
        } else {
            getlex();
            e -= add();
        }
    }
    return e;
}

int add(){
    int a = calc_pow();
    while (curlex == '*' || curlex == '/'){
        if (curlex == '*'){
            getlex();
            a *= calc_pow();
        } else {
            getlex();
            int temp = calc_pow();
            if (temp == 0){
                error();
            } else a /= temp;
        }
    }
    return a;
}

int calc_pow(){
    int res = mult();
    if (curlex == '^') {
        getlex();
        int pow = calc_pow();
        if (pow > 0) {
            int a = res;
            for (; --pow != 0;) {
                res *= a;
            }
        } else if (pow < 0) {
            error();
        } else res = 1;
    }
    return res;
}

int mult(){
    int m;
    switch(curlex){
        case '0': case '1': case '2': case '3': case '4': case '5':
        case '6': case '7': case '8': case '9': m = curlex-'0';break;
        case '(':
            getlex();
            m = expr();
            if (curlex == ')') break;
        default : error();
    }
    getlex();
    return m;
}