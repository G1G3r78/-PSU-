#include <iostream>

using namespace std;

struct n {
    int d;
    n *next; //указатель на следующие адреса элементов
};

void outsp(n* one)
{
    //вывод элементов списка
    n *tVyvod;
    for (tVyvod = one; tVyvod != NULL; tVyvod = (*tVyvod).next) {
        cout << "Адрес числа " << (*tVyvod).d << "=" << &(*tVyvod).d <<
            ", адрес след элемента - " << (*tVyvod).next << endl;
    }
    cout << endl;
}

void zap(n* one, int amount)
{
    n *t = NULL; //заземлённый указатель
    t = new (n);
    one = t; //перевод адреса на данный 
    one->d = rand() % 100;
    cout << "Инициализация списка:\n";
    outsp(one);

    for (int i = 0; i < amount-1; i++) {
        
        n *t2;
        t2 = one;
        while ((*t2).next != NULL) t2 = (*t2).next; //поиск последнего заземлённого поля
        t = new (n);
        t->next = NULL; //заземление данного поля
        (*t).d = rand() % 100; //передача данных в данную ячейку 
        (*t2).next = t; //заземление вспомогательного указателя
    }
    cout << "Заполненный список:\n";
    outsp(one);
}


int main()
{

    srand(time(NULL));

    int amount;
    cout << "Введите кол-о элементов: ";
    cin >> amount;

    n *one; //указатель на список (первый элемент списка)
    zap(one, amount); //заполнение

    return 0;
}

/*
Введите кол-о элементов: 5
Инициализация списка:
Адрес числа 0=0x55d0c5a58b40, адрес след элемента - 0

Заполненный список:
Адрес числа 0=0x55d0c5a58b40, адрес след элемента - 0x55d0c5a58b60
Адрес числа 83=0x55d0c5a58b60, адрес след элемента - 0x55d0c5a58b80
Адрес числа 86=0x55d0c5a58b80, адрес след элемента - 0x55d0c5a58ba0
Адрес числа 77=0x55d0c5a58ba0, адрес след элемента - 0x55d0c5a58bc0
Адрес числа 15=0x55d0c5a58bc0, адрес след элемента - 0x55d0c5a58be0
Адрес числа 93=0x55d0c5a58be0, адрес след элемента - 0
*/