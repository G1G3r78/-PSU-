#include <iostream>

using namespace std;

struct tree {
    int d;
    int pr; //приоритет
    tree *left;
    tree *right;
};

tree *RR(tree *root){
    tree *tr = root;
    tree *trl = (*tr).left;
    (*tr).left = NULL;
    (*tr).left = (*trl).right;
    (*trl).right = NULL;
    (*trl).right = tr;
    root = trl;
    return root;
}

tree *LL(tree *root){
    tree *tr = root;
    tree *trr = (*tr).right;
    (*tr).right = NULL;
    (*tr).right = (*trr).left;
    (*trr).left = NULL;
    (*trr).left = tr;
    root = trr;
    return trr;
}

tree *insert(tree *root, int x, int pr){
    if (root == NULL){
        tree *t = new tree;
        (*t).d = x;
        (*t).pr = rand() % 101;
        (*t).left = (*t).right = NULL;
        return t;
    } else {
        if (x < (*root).d){
            (*root).left = insert((*root).left, x, pr);
            if ((*(*root).left).pr > (*root).pr) RR(root);
        }
        else if (x > (*root).d) {
            (*root).right = insert((*root).right, x, pr);
            if ((*(*root).right).pr > (*root).pr) LL(root);
        } else cout << "уже есть - нет вставки\n";
    }
    return root;
}