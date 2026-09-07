#include <stdio.h>

struct tree {
    int d;
    tree *left;
    tree *right;
};

/*int minEl(tree *node){
    tree *minP = node;
    while (minP->left != NULL) {
        minP = minP->left;
    }
    return minP->d;
}

int maxEl(tree *node){
    tree *maxP = node;
    while (maxP->right != NULL){
        maxP = maxP->right;
    }
    return maxP->d;
}*/

tree *swapMinMax(tree *root){
    tree *minP, *maxP, *minPrev, *maxPrev, *r;
    int min, max;

    /*min = minEl(root);
    max = maxEl(root);*/
    minP = root, maxP = root, r = root;
    minPrev = NULL, maxPrev = NULL;

    while (minP->left != NULL) {
        minPrev = minP;
        minP = minP->left;
    }
    while (maxP->right != NULL){
        maxPrev = maxP;
        maxP = maxP->right;
    }

    if (r->left != NULL && r->right != NULL) {
        minPrev->left = maxP;
        maxPrev->right = minP;
    }
    else if (r->left == NULL && r->right != NULL){
        maxP->right = r->right;
        r->right = NULL;
        maxPrev->right = r;
    }
    else if (r->left != NULL && r->right == NULL){
        minP->left = r->left;
        r->left = NULL;
        minPrev->left = r;
    }

    return root;
}