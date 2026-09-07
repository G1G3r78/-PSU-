#include <iostream>

using namespace std;

struct tree {
    int d;
    int pr;
    tree *left;
    tree *right;
};

tree *merge(tree *left, tree *right){
    if (left == NULL) return right;
    if (right == NULL) return left;
    else {
        if (left->pr > right->pr) {
            left->right = merge(left->right, right);
            return left;
        } 
        else {
            right->left = merge(right->left, left);
            return right;
        }
    }
}

tree *deletion(tree *root, int x){
    tree *cur, *prev;
    cur = root;
    prev = NULL;

    while ((*cur).d != x && cur != NULL){
        prev = cur;
        if (x < (*cur).d) cur = cur->left;
            else cur = cur->right;
    }


    if (cur->d != x) cout << "не найден\n";
        else {
            //0 потомков
            if (cur->left == NULL && cur->right == NULL){
                if (prev->left == cur) prev->left = NULL;
                    else prev->right = NULL;
                delete(cur);
            }
            //1 потомок слева
            else if ((cur->left != NULL && cur->right != NULL)) {
                if (prev->left == cur) {prev->left = cur->left; cur->left = NULL;}
                    else {prev->right = NULL; prev->right = cur->left;}
                delete(cur);
            //1 потомок справа
            } else if (cur->left == NULL && cur->right != NULL){
                if (prev->left == cur) {prev->left = cur->left; cur->right = NULL;}
                    else {prev->right = NULL; prev->right = cur->right;}
                delete(cur);
            }
            //2 потомка
            else if (cur->left != NULL && cur->right != NULL){
                tree *newTr = merge(cur->left, cur->right);
                if (prev == NULL) {
                    delete(cur);
                    return newTr;
                } else {
                    if (prev->left == cur){
                        prev->left = newTr;
                    } else prev->right = newTr;
                    delete(cur);
                }
            }
        }
    return root;
}