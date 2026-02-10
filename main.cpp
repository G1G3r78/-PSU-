#include <iostream>
#include <stdlib.h>

using namespace  std;

struct n {
    int d; // данные
    n *next; //*-указатель на список node
};

int main() {

    // инициализцаия
    /*n *one = NULL;
    n *t = NULL;
    t = new (n);
    (*t).d = 108;
    one = t;

    //вставка 2 элемента в начало
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
    cout << endl;*/

    int amount;
    cout << "Введите кол-о элементов: ";
    cin >> amount;

    n *one = NULL;
    n *t = NULL;
    t = new (n);
    one = t;

    for (int i = 0; i < amount; i++) {
        
        n *t2;
        t2 = one;
        while ((*t2).next != NULL) t2 = (*t2).next;
        t = new (n);
        t->next = NULL;
        (*t).d = rand() % 100;
        (*t2).next = t;
    }

    n *tVyvod;
    for (tVyvod = one; tVyvod != NULL; tVyvod = (*tVyvod).next) {
        cout << "Адрес числа " << (*tVyvod).d << "=" << &(*tVyvod).d <<
            ", адрес след элемента - " << (*tVyvod).next << endl;
    }

    return 0;
}

/*
Введите кол-о элементов: 5
Адрес числа 0=0x563138d75b40, адрес след элемента - 0x563138d75b60
Адрес числа 83=0x563138d75b60, адрес след элемента - 0x563138d75b80
Адрес числа 86=0x563138d75b80, адрес след элемента - 0x563138d75ba0
Адрес числа 77=0x563138d75ba0, адрес след элемента - 0x563138d75bc0
Адрес числа 15=0x563138d75bc0, адрес след элемента - 0x563138d75be0
Адрес числа 93=0x563138d75be0, адрес след элемента - 0
 */
