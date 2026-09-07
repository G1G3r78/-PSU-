#include <iostream>

using namespace std;

//Понятие списка. Реализация операций со списком.
struct node {
    int d;
    node *next;
};

//добавление в начало
node *addNachcalo(node *head, int x) {
    node *t;
    t = new node();
    (*t).d = x;
    (*t).next = NULL;
    head = t;
    return head;
}

//добавление в конец
node *addEnd(node *head, int x){
    node *t1, *t2;
    t1 = head;
    t2 = NULL;
    while ((*t1).next != NULL) {
        t1 = (*t1).next;
    }
    t2 = new node();
    (*t2).d = x;
    (*t2).next = NULL;
    (*t1).next = t2;
    return t1;
}

//удаление из начала
node *delNachalo(node *head){
    node *t1, *t2;
    t1 = head;
    t2 = (*t1).next;
    (*t1).next = NULL;
    delete t1;
    head = t2;
    return head;
}

//удаление из конца
node *delEnd(node *head){
    node *t1, *t2;
    t1 = head;
    t2 = NULL;
    while ((*t1).next != NULL) {
        t2 = t1;
        t1 = (*t1).next;
    }
    (*t2).next = NULL;
    delete t1;
    return head;
}

//поиск элемента
node *search(node *head, int x){
    node *t;
    t = head;
    while ((*t).d != x) {
        t = (*t).next;
    }
    return t;
}

//Понятие стека. Реализация операций со стеком.
struct stack {
    int d;
    stack *next;
};

//добавление первого элемента
stack *firstElement(stack *head, int x){
    stack *t;
    t = new stack();
    (*t).d = x;
    (*t).next = NULL;
    head = t;
    return head;
}

//добавление в начало
stack *addToNach(stack *head, int x){
    stack *t1;
    t1 = new stack();
    (*t1).next = head;
    head = t1;
    return head;
}

//удаление из начала
stack *delNach(stack *head){
    stack *t1, *t2;
    t1 = head;
    t2 = (*t1).next;
    delete t1;
    head = t2;
    return head;
}

//Понятие очереди. Реализация операций с очередью.
struct queue {
    int d;
    queue *next;
};

//создание 1 элемента
void create(queue *&head, queue *&tail, int x){
    queue *t, *head, *tail;
    head = NULL;
    tail = NULL;
    t = new queue();
    (*t).d = x;
    (*t).next = NULL;
    head = t;
    tail = t;
}

//добавление в конец
void addEnd(queue *&head, queue *&tail, int x){
    queue *t;
    t = new queue();
    (*t).d = x;
    (*t).next = NULL;
    (*tail).next = t;
    tail = t;
}

//удаление из начала
void delNach(queue *&head, queue *&tail){
    queue *t;
    t = head;
    head = (*t).next;
    (*t).next = NULL;
    delete t;
}

//Понятие дека. Реализация операций с деком.
struct deque {
    int d;
    deque *next;
};

//добавление в начало
deque *addNach(deque *head, int x){
    deque *t;
    t = new deque();
    (*t).d = x;
    (*t).next = NULL;
    head = t;
    return head;
}

//добавление в конец
deque *addEnd(deque *head, int x){
    deque *t1, *t2;
    t1 = head;
    while ((*t1).next != NULL){
        t1 = (*t1).next;
    }
    (*t2).d = x;
    (*t2).next = NULL;
    (*t1).next = t2;
    return head;
}

//удлаение начала
deque *delNach(deque *head){
    deque *t;
    t = head;
    head = (*head).next;
    (*t).next = NULL;
    delete t;
    return head;
}

//удаление конца
deque *delEnd(deque *head){
    deque *t1, *t2;
    t1 = head;
    while ((*t1).next != NULL) {
        t2 = t1;
        t1 = (*t1).next;
    }
    (*t2).next = NULL;
    delete t1;
    return head;
}