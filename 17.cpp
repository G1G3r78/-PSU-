#include <stdio.h>

struct tree {
    tree *left;
    tree *right;
    int d;
};

void print(tree *root, int level){
    if (root == NULL) return;

    print(root->right, level+1);
    for (int i = 0; i < level; i++){
        printf("    ");
    }
    printf("%d\n", root->d);
    print(root->left, level+1);
}