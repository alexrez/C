#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRLEN 1000

int getln(char *line, int max, FILE *f){
    int len;
    if (fgets(line, max, f) == NULL)
        return 0;
    else {
        len = strlen(line);
        if ((len > 1) && (line[len - 1] == '\n')){
            line[len - 1] = '\0';
            --len;
        }
        return len;
    }
}

int main(int argc, char *argv[]) {
    int counter = 0, word_len, str_len;
    char str[MAXSTRLEN];
    FILE *fd;

    if (argc > 2){
        word_len = strlen(argv[1]);
        char word[word_len+1];
        strcpy(word, *++argv);
        word[word_len] = '\0';
        while (argc-- >2) {
            if ((fd = fopen(*++argv, "r")) == NULL) {
                printf("can't open %s\n", *argv);
                exit(1);
            } else {
                while ((str_len = getln(str, MAXSTRLEN, fd))) {
                    if (strcmp(str, word) == 0) {
                        ++counter;
                    } else if (str_len > word_len) {
                        //учитываются только строки, в которых заданное слово обособлено от других слов пробелом
                        if ((str[str_len - word_len - 1] == ' ') &&
                            (strcmp(&str[str_len - word_len], word) == 0)) {
                            ++counter;
                        }
                    }
                }
            }
        }
        printf("%d\n", counter);
    } else{
        printf("use pattern: ./prog word_to_find file_to_search_1 [file_to_search_2 ...]\n");
    }
    return 0;
}