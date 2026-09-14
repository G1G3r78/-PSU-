#include <iostream>

using namespace std;

struct tree {
    int d;
    tree *left;
    tree *right;
};

void LL(tree *root);
void RL(tree *root);
void LR(tree *root);
void RR(tree *root);

int H(tree *root){
    if (root == NULL) return 0;
    int Hright, Hleft;
    Hleft = H(root->left);
    Hright = H(root->right);
    if (Hright > Hleft) return (Hright+1);
        else return (Hleft+1);
}


int balance(tree *root){
    if (root == NULL) return 0;
    int Hright, Hleft, result;
    Hleft = H(root->left);
    Hright = H(root->right);
    result = Hright-Hleft;
    return result;
}

tree *fixBal(tree *root){
    int bal = balance(root);
    if (bal > 1 && balance(root->right) >= 0) LL(root);
    if (bal > 1 && balance(root->right) < 0) RL(root);
    if (bal < -1 && balance(root->left) <= 0) RR(root);
    if (bal < -1 && balance(root->left) > 0) LR(root);
    return root;
}

tree *deletion(tree *root, int x){
    tree *cur, *prev;
    cur = root;
    prev = NULL;
    
    //поиск и удаление BST
    while ((*cur).d != x || (*cur).left != NULL || (*cur).right != NULL) {
        prev = cur;
        if (x < (*cur).d) cur = cur->left;
            else cur = cur->right;
    }
    if (x != (*cur).d) {
        cout << "not found!\n";
        return root;
    } else {
        //удаление корня
        if (root == cur) {
            tree *list = root->right;
            tree *prev_list = root;
            while ((*list).left != NULL) {
                prev_list = list;
                list = list->left;
            }
            prev_list->left = NULL;
            list->left = root->left;
            list->right = root->right;
            root->left = root->right = NULL;
            root = list;
        } else {
            //удал. эл. - лист
            if ((*cur).left == NULL && (*cur).right == NULL){
                if ((*prev).left == cur) prev->left = NULL;
                    else prev->right = NULL;
                delete(cur);
            }
            //удал. эл. имеет 1 потомка
            else if ((*cur).left != NULL || (*cur).right != NULL) {
                tree *cur_potomok;
                if (cur->left != NULL) {cur_potomok = cur->left; cur->left = NULL;}
                    else {cur_potomok = cur->right; cur->right = NULL;}
                if (prev->left == cur) prev->left = cur_potomok;
                    else prev->right = cur_potomok;
                delete(cur);
            }
            //удал. эл. имеет 2 потомка
            else {
                tree *cur_potomok, *mini;
                if (cur->left != NULL) {
                    cur_potomok = cur->left;
                    mini = cur_potomok;
                    while ((*mini).right != NULL) {
                        cur_potomok = mini;
                        mini = mini->right;
                    }
                }
                else {
                    cur_potomok = cur->right;
                    mini = cur_potomok;
                    while ((*mini).right != NULL) {
                        cur_potomok = mini;
                        mini = mini->right;
                    }
                }
                cur_potomok = NULL;
                if (prev->left == cur) {
                    prev->left = NULL;
                    prev->left = mini;
                } else {
                    prev->right = NULL;
                    prev->right = mini;
                }
                mini->left = cur->left;
                mini->right = cur->right;
                cur->left = NULL;
                cur->right = NULL;
                delete(cur);
            }
        }
    }
    return fixBal(root);
}