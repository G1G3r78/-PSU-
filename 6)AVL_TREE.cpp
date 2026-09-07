//АВЛ-дерево - сбалансрование дерево поиска, в котором высота правого и левого потомков отличаются не более чем на 1.
#include <iostream>

using namespace std;

struct tree {
    int data;
    tree *left;
    tree *right;
};

tree *search_insert_avl(tree *root, int x)
{
    if (root == NULL) //создание нового узла
    {
        tree *t = new tree;
        (*t).data = x;
        (*t).left = NULL;
        (*t).right = NULL;
        return t;
    }
    //рекурсивный спуск на создание узлов
    if (x < (*root).data)
    {
        (*root).left = search_insert_avl((*root).left, x);
    }
    else if (x > (*root).data)
    {
        (*root).right = search_insert_avl((*root).right, x);
    }
    else {
        //узел существует - нет вставки
        return root;
    }
    int bal = balance(root);
    if (bal < -1 && x < (*(*root).left).data) return RR(root);
    if (bal < -1 && x > (*(*root).left).data) return LR(root);
    if (bal > 1 && x < (*(*root).right).data) return LL(root);
    if (bal > 1 && x > (*(*root).right).data) return RL(root);
}