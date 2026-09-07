#include <iostream>

struct tree {
    int d;
    tree *left;
    tree *right;
};

bool isSym(tree *a, tree *b){
    if (a == NULL && b == NULL) return true;
    if (a == NULL || b == NULL) return false;

    if (a->d != b->d) return false;

    bool leftRes = isSym(a->left, b->right);
    bool rightRes = isSym(a->right, b->left);
    bool result = leftRes && rightRes;

    return result;
}