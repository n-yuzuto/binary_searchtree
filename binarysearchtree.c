#include <stdio.h>
#include <stdlib.h>
#include "binarysearchtree.h"

int min_bst(Node *root){
    if(root==NULL) return -1;
    Node *p = root;
    while(p -> left != NULL) p = p -> left;
    return p -> value;
}

bool search_bst(Node *root, int d){
    struct node *p;
    p = root;
    bool t = true;
    bool f = false;
    while(p != NULL){
        if(d < p -> value){
            p = p -> left;
        }
        else if(d > p -> value){
            p = p -> right;
        }
        else{
            return t;
        }
    }
    return f;
}

void insert_bst(Node **root, int d){
    struct node *another;
    struct node *node;
    another = (struct node*)malloc(sizeof(struct node));
    another -> left = NULL;
    another -> right = NULL;
    another -> value = d;

    if(*root == NULL){
        *root = another;
        return;
    }

    node = *root;

    while(1){
        if(d < node -> value){
            if(node -> left == NULL){
                node -> left = another;
                return;
            }
            else node = node -> left;
        }
        else if(d > node -> value){
            if(node -> right == NULL){
                node -> right = another;
                return;
            }
            else node = node -> right;
        }else{
            printf("%d already exist\n",d);
            return;
        }
    }
}

void delete_bst(Node **root, int d){
    if (root == NULL){
        return;
    }
    Node *p = *root;
    Node *q = NULL;
    char *lr;
    while (p != NULL){
        if (p->value > d){
            q = p;
            lr = 'L';
            p = p->left;
        }
        else if (p->value < d){
            q = p;
            lr = 'R';
            p = p->right;
        }
        else{
            if (p->left == NULL || p->right == NULL){
                delete_el(p, q, lr);
                return;
            }
            Node *r = p->right;
            q = p;
            lr = 'R';
            while (r->left != NULL){
                q = r;
                r = r->left;
                lr = 'L';
            }
            p->value = r->value;
            r->value = d;
            delete_el(r, q, lr);
            return;
        }
    }
    return;
}

void delete_el(Node *p, Node *q, char *lr){
    if (p -> left == NULL && p -> right == NULL){
        if (q == NULL){
            p == NULL;
        }
        else if (lr == 'L'){
            q -> left = NULL;
        }
        else if (lr == 'R'){
            q -> right = NULL;
        }
        free(p);
        return;
    }
    if (p -> left == NULL ||  p -> right == NULL){
        if (p -> left == NULL){
            if (q == NULL){
                p = p -> right;
            }
            else{
                if (lr == 'L'){
                    q -> left = p -> right;
                }
                else if (lr == 'R'){
                    q -> right = p -> right;
                }
            }
        }
        else if (p -> right == NULL){
            if (q == NULL){
                p = p -> left;
            }
            else{
                if (lr == 'L'){
                    q -> left = p -> left;
                }
                else if (lr == 'R'){
                    q -> right = p -> left;
                }
            }
        }
        free(p);
        return;
    }
}

void display(Node *n) {
    if (n == NULL) {
        printf("null");
    }
    else {
        printf("%d(", n->value);
        display(n->left);
        printf(",");
        display(n->right);
        printf(")");
    }
}
