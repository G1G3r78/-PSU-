#include <iostream>

struct tree {
    int d;
    tree *left;
    tree *right;
};

int H(tree *root){
    int hRight = H(root->right);
    int hLeft = H(root->left);
    if (hRight > hLeft) return hLeft+1;
        else return hRight+1;
}

void maxLevel(tree *root, int level, int &max)
{
    if (root == NULL) return;

    if (level == 0)
    {
        if (root->d > max) max = root->d;
        return;
    }

    maxLevel(root->left, level - 1, max);
    maxLevel(root->right, level - 1, max);
}

void printMax(tree *root){
    int h, max;
    h = H(root);

    for (int level = 0; level < h; level++){
        max = -1;
        maxLevel(root, level, max);
        std::cout << max << "\n";
    }
}