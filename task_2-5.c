#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node *list;
typedef char *elemtype;

typedef struct Node{
    elemtype elem;
    list next;
} Wlist;

void in_list(list *lp, elemtype data){
    list new = (list) malloc(sizeof(Wlist));
    new->elem = strcpy(malloc(sizeof(data)), data);
    new->next = NULL;
    if (*lp!=NULL){
        list cur = *lp;
        while (cur->next){
            cur = cur->next;
        }
        cur->next = new;
    }
    else *lp = new;
}

void out_from_list(list *lp, elemtype data){
    if(*lp) {
        while ((*lp)->next) {
            if (!strcmp((*lp)->elem, data)) {
                list temp = *lp;
                *lp = (*lp)->next;
                free(temp);
            } else lp = &(*lp)->next;
        }
    }
}

void lst_print(list lp){
    if (lp){
        printf("%s ", lp->elem);
        lst_print(lp->next);
    }
}

int main() {
    char inp_str[255];
    list lst = NULL;

    while (scanf("%s", inp_str)!=EOF){
        in_list(&lst, inp_str);
    }
    out_from_list(&lst, inp_str);
    lst_print(lst);
    printf("\n");
    return 0;
}