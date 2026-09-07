#include <stdio.h>

struct tree {
    tree *left;
    tree *right;
    int d;
};

int count(tree *root){
    if (root == NULL) return 0;
    int l = count(root->left);
    int r = count(root->right);
    return 1+l+r;
}

void search(tree *root){
    if (root == NULL) return;

    int l = count(root->left);
    int r = count(root->right);

    if (l != r) printf("%d\n", root->d);

    search(root->left);
    search(root->right);
}