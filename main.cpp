#include <iostream>

using namespace  std;

struct n {
    int d; // данные
    n *next; //*-указатель на список node
};

int main() {

    // инициализцаия
    n *one = NULL;
    n *t = NULL;
    t = new (n);
    (*t).d = 108;

    //вставка 2 элемента
    one = t;
    t = new (n);
    (*t).next = NULL;
    (*t).d = 530;
    (*t).next = one;
    one=t;

    //вставка в конец
    n *t2;
    t2 = one;
    while ((*t2).next != NULL) t2 = (*t2).next;
    t = new (n);
    t->next = NULL;
    (*t).d = rand() % 100;
    (*t2).next = t;

    //вывод элементов списка
    n *tVsvod;
    for (tVsvod = one; tVsvod != NULL; tVsvod = (*tVsvod).next) {
        cout << "Адрес числа " << (*tVsvod).d << "=" << &(*tVsvod).d <<
            ", адрес след элемента - " << (*tVsvod).next << endl;
    }
    cout << endl;

    /*int amount;
    cout << "enter amount";
    cin >> amount;

    n *one = NULL;
    n *t = NULL;
    t = new (n);

    for (int i = 0; i < amount; i++) {
        (*t).d = rand()%100;

        (*t).next = one;
        one=t;
        (*t).next = NULL;
    }

    n *tVsvod;
    for (tVsvod = one; tVsvod != NULL; tVsvod = (*tVsvod).next) {
        cout << "Адрес числа " << (*tVsvod).d << "=" << &(*tVsvod).d <<
            ", адрес след элемента - " << (*tVsvod).next << endl;
    }*/

    return 0;
}

/*
Адрес числа 530=0x105289a60, адрес след элемента - 0x105289a50
Адрес числа 108=0x105289a50, адрес след элемента - 0x0
 */