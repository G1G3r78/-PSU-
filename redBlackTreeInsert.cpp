#include <iostream>

using namespace std;

/*
лист и корень чёрные
у красного узла до 2 чёрных потомков
один. кол-о чёрных узлов от корня до листа
*/


typedef enum Color {RED, BLACK};

struct tree {
    int d;
    tree *parent;
    Color color;
    tree *left;
    tree *right;
};

//рекурсивная версия с red-black деревом не подходит
/*tree *insert(int x, tree *root){
    if (root == NULL) {
        tree *node = new tree;
        (*node).d = x;
        (*node).parent = (*node).left = (*node).right = NULL;
        (*node).color = RED;
        return node;
    } else {
        if (x < (*root).d) {
            (*root).left = insertBST(x, (*root).left);
            (*(*root).left).parent = root;
        }
        else if (x > (*root).d) {
            (*root).right = insertBST(x, (*root).right);
            (*(*root).right).parent = root;
        }
        else cout << "нет вставки, уже есть\n";
    }
    return root;
}*/

tree *rotateLeft(tree *root){};
tree *rotateRight(tree *root){};

tree *insert(int x, tree *root){

    tree *prev, *cur;
    prev = NULL;
    cur = root;

    while (cur != NULL && x != (*cur).d) {
        prev = cur;
        if (x < cur->d) cur = cur->left;
            else cur = cur->right;
    }

    tree *node = new tree;
    (*node).d = x;
    (*node).left = (*node).right = NULL;
    (*node).color = RED;
    (*node).parent = prev;

    if (prev == NULL) root = node;
        else if (x < prev->d) prev->left = node;
            else prev->right = node;

    return fixInsert(node);
}


tree *fixInsert(tree *root){
    tree *x, *p, *u, *g;

    x = root;

    while (x->parent != NULL && x->parent->color == RED) 
        if (x->parent == NULL) x->color = BLACK;
        if (x->parent != NULL) p = x->parent;
        if (p->parent != NULL) g = p->parent;
        if (g->left == p && g->right != NULL) u = g->right;
            else u = g->left;
            
        //дядя красный
        if (u != NULL && u->color == RED) {
            g->color = RED;
            p->color = BLACK;
            u->color = BLACK;
        } 
        //дядя чёрный и линия справа
        else if (u != NULL && u->color == BLACK && g->right == p && p->right == x) {
            rotateLeft(g);
            (*g).color = RED;
            (*p).color = BLACK;
        }
        //дядя чёрный и линия слева
        else if (u != NULL && u->color == BLACK && g->left == p && p->left == x) {
            rotateRight(g);
            (*g).color = RED;
            (*p).color = BLACK;
        }
        //дядя чёрный и треугольник справа
        else if (u != NULL && u->color == BLACK && g->right == p && p->left == x) {
            rotateRight(p);
        }
        //дядя чёрный и треугольник слева
        else if (u != NULL && u->color == BLACK && g->left == p && p->right == x) {
            rotateLeft(p);
        }
    
    //в случаях поворотах текущий узел - х, может находиться не там где был изначально,
    //ищем настоящий корень
    while (x->parent != NULL) x = x->parent;
    x->color = BLACK;

    return x;
}