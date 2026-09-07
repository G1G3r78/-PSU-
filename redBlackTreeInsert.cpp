#include <iostream>

using namespace std;

typedef enum Color {RED, BLACK};

struct node {
    int d;
    Color color;
    node *left, *right, *parent;
};

node *createNode(int d){
    node *n = new node;
    (*n).d = d;
    (*n).left = (*n).right = (*n).parent = NULL;
    (*n).color = RED;
    return n;
}

void rotateLeft();

void rotateRight();

node *insert(int x, node *tr){
    if (tr == NULL) {
        tr = createNode(x);
        return tr;
    }

    if (x < (*tr).d) {
        (*tr).left = insert(x, (*tr).left);
        (*(*tr).left).parent = tr;
    } else if (x > (*tr).d) {
        (*tr).right = insert(x, (*tr).right);
        (*(*tr).right).parent = tr;
        } else {
            cout << "уже есть в дереве\n";
        }
    return tr;
}

/*
лист и корень чёрные
у красного узла до 2 чёрных потомков
один. кол-о чёрных узлов от корня до листа
*/


struct tree {
    int d;
    bool isRed;
    tree *parent;
    tree *left;
    tree *right;
};

void rotateLeft(tree *tr){}

void rotateRight(tree *tr){}

tree *searchInsert(tree *root, int x){
    if (root == NULL) {
        tree *tr = new tree;
        (*tr).parent = (*tr).left = (*tr).right = NULL;
        (*tr).isRed = true;
        (*tr).d = x;
        return tr;
    } else {
        //простая вставка
        if (x < (*root).d) {
            (*root).left = searchInsert((*root).left, x);
            (*(*root).left).parent = root;
        } else if (x > (*root).d) {
            (*root).right = searchInsert((*root).right, x);
            (*(*root).right).parent = root;
        } else cout <<"есть - нет вставки\n";
        return root;
    }
}

void fixInsert(tree *root){
    tree *s, *p, *u, *g;

    s = root;
    p = (*s).parent;
    g = (*p).parent;
    if (p == (*g).left) u = (*g).right;
        else u = (*g).left;

    //проверки на балансировку
    if ((*u).isRed == true) {
        (*p).isRed = false;
        (*u).isRed = false;
        if ((*g).parent == NULL) (*g).isRed = false;
            else (*g).isRed = true;
    } else if ((*u).isRed == false && p == (*g).left && s == (*p).left) {
        rotateRight(g);
        (*p).isRed = false;
        (*g).isRed = true;
    } else if ((*u).isRed == false && p == (*g).right && s == (*p).right) {
        rotateLeft(g);
        (*p).isRed = false;
        (*g).isRed = true;
    } else if ((*u).isRed == false && p == (*g).left && s == (*p).right) {
        (*g).isRed = true;
        rotateLeft(p);
        p = (*s).parent;
        g = (*p).parent;
        (*p).isRed = false;
        (*g).isRed = true;
    } else if ((*u).isRed == false && p == (*g).right && s == (*p).left) {
        (*g).isRed = true;
        rotateRight(p);
    }
}