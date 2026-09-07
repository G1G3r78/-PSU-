#include <stdio.h>

struct T1 {
    T1 *left;
    T1 *right;
    int d;
};

struct T2 {
    T2 *left;
    T2 *right;
    int d;
};

T2 *copy(T1 *&root){
    if (root == NULL) return;

    T2 *rootT2 = new T2();

    rootT2->d = root->d;
    rootT2->left = copy(root->left);
    rootT2->right = copy(root->right);

    return rootT2;
}