#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TreeNode *root;

typedef struct TreeNode{
    int key;
    root left;
    root right;
} Tnode;

int get_key(char *to_do, int *data){
    char inp_str[255];
    int i = 0;
    if (scanf("%s", inp_str) != EOF){
        *to_do = *inp_str;
        *data = atoi(&inp_str[++i]);
        return 1;
    } else return 0;
}

void in_tree(root *tr, int data){
    if (*tr!=NULL){
        if ((*tr)->key > data){
            in_tree(&(*tr)->left, data);
        } else if ((*tr)->key < data){
            in_tree(&(*tr)->right, data);
        } else if ((*tr)->key == data){}
    }
    else{
        root new = (root) malloc(sizeof(Tnode));
        new->key = data;
        new->left = new->right = NULL;
        *tr = new;
    }
}

void copy_root_to_del(root *to_change, root to_delete){
    root temp = to_delete;
    (*to_change)->left = temp->left;
    (*to_change)->right = temp->right;
    (*to_change)->key = temp->key;
    free(temp);
}

void out_from_tree(root *tr, int data){
    if(*tr) {
        if ((*tr)->key > data) {
            out_from_tree(&((*tr)->left), data);
        } else if ((*tr)->key < data) {
            out_from_tree(&((*tr)->right), data);
        } else {
            if ((*tr)->left == NULL && (*tr)->right == NULL){
                root temp = *tr;
                *tr = NULL;
                free(temp);
            } else if ((*tr)->left == NULL){
                copy_root_to_del(&(*tr), (*tr)->right);
            } else if ((*tr)->right == NULL){
                copy_root_to_del(&(*tr), (*tr)->left);
            } else {
                root temp = (*tr)->right;
                if (temp->left == NULL) {
                    (*tr)->right = temp->right;
                    (*tr)->key = temp->key;
                    free(temp);
                } else {
                    while (temp->left->left) {
                        temp = temp->left;
                    }
                    (*tr)->key = temp->left->key;
                    out_from_tree(&(temp->left), temp->left->key);
                }
            }
        }
    }
}

int search_data(root tr, int data){
    return tr? search_data(tr->left, data) + search_data(tr->right,  data) + (tr->key == data): 0;
}

int main() {
    int inp_key;
    char c;
    root tr_root = NULL;

    while (get_key(&c, &inp_key)){
        switch (c){
            case '+': in_tree(&tr_root, inp_key);
                break;
            case '-': out_from_tree(&tr_root, inp_key);
                break;
            case '?': printf("\n%u %s\n", inp_key, search_data(tr_root, inp_key)?"yes":"no");
                break;
            default: printf("Invalid operator");
                break;
        }
    }
    return 0;
}