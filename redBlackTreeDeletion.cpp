#include <iostream>

using namespace std;

struct tree {
    int d;
    bool isRed;
    tree *left;
    tree *right;
    tree *parent;
};

void LL(tree *tr){}
void RR(tree *tr){}

tree *searchDelete(tree *root, int x){ //x - удал. элемент
    tree *ud;
    ud = root;

    while (ud != NULL) {
        if (x < (*ud).d) return searchDelete((*ud).left, x);
            else if (x > (*ud).d) return searchDelete((*ud).right, x);
    }
    if (ud == NULL) cout << "нет элемента\n";
        else { //есть, значит удаление как в BST дереве - 0,1,2+ потомка
            if ((*ud).left == NULL && (*ud).right == NULL) {
                if ((*ud).d > (*(*ud).parent).d) (*(*ud).parent).right = NULL;
                    else (*(*ud).parent).left = NULL;

            } else if ((*ud).left != NULL || (*ud).right != NULL){
                if ((*ud).left != NULL) {
                    if ((*ud).d > (*(*ud).parent).d) (*(*ud).parent).right = (*ud).left;
                        else (*(*ud).parent).left = (*ud).left;
                } else {
                    if ((*ud).d > (*(*ud).parent).d) (*(*ud).parent).right = (*ud).right;
                        else (*(*ud).parent).left = (*ud).right;
                }
            } else {
                tree *dop = ud;
                if ((*ud).d > (*(*ud).parent).d) {
                    while ((*ud).left != NULL) ud = (*ud).left;
                    (*(*dop).parent).right = ud;
                } else {
                    while ((*ud).right != NULL) ud = (*ud).right;
                    (*(*dop).parent).left = ud;
                }
                (*ud).left = (*ud).right = NULL;
            }
            delete(ud);
        }
    return root;
}

/*void fix(tree *root){
    //проверка на 5 возможных случаев
    tree *x, *p, *s, *n, *f;

    x = root;
    p = (*x).parent;
    if (x == (*p).left) s = (*p).right;
        else s = (*p).left;
    n = (*s).left;
    f = (*s).right;

    //5 случаев
    if ((*x).isRed == true) (*x).isRed = !((*x).isRed);
        else if ((*x).isRed == false && (*s).isRed == true) {
            (*p).isRed = true;
            (*s).isRed = false;
            if ((*p).left == x) LL(p);
                else RR(p);
        } else if ((*x).isRed == false && (*s).isRed == false && ((*n).isRed) == (*f).isRed == false) {
            (*s).isRed = true;
            x = p;
            p = (*x).parent;
        } else if ((*x).isRed == false && (*s).isRed == false && (*n).isRed == true && (*f).isRed == false) {
            (*n).isRed = false;
            (*s).isRed = true;
            if ((*p).left == x) RR(s);
                else LL(s);
        } else if ((*x).isRed == false && (*s).isRed == false && (*n).isRed == false && (*f).isRed == true) {
            (*s).isRed = (*p).isRed;
            (*p).isRed = false;
            (*f).isRed = false;
            if ((*p).left == x) LL(s);
                else RR(s);
        }
}*/

void fix(tree *root){
    tree *s, *x, *f, *n, *p;

    x = root;
    p = (*x).parent;
    if (x == (*p).left) s = (*p).right;
        else s = (*p).left;
    n = (*s).left;
    f = (*s).right;

    if ((*x).isRed == true) (*x).isRed = false;
        else if ((*x).isRed == false && (*s).isRed == true) {
            (*s).isRed = false;
            (*p).isRed = true;
            if (x == (*p).left) LL(p);
                else RR(p);
        } else if ((*x).isRed == false && (*s).isRed == false && (*n).isRed == false && (*f).isRed == false) {
            (*s).isRed = true;
            x = p;
            p = (*x).parent;
            if (x == (*p).left) s = (*p).right;
                else s = (*p).left;
            n = (*s).left;
            f = (*s).right;
        } else if ((*x).isRed == false && (*s).isRed == false && (*n).isRed == true && (*f).isRed == false){
            (*s).isRed = true;
            (*n).isRed = false;
            RR(s);
        } else if ((*x).isRed == false && (*s).isRed == false && (*n).isRed == false && (*f).isRed == true){
            (*s).isRed = (*p).isRed;
            (*p).isRed = false;
            (*f).isRed = false;
            LL(s);
        }
}