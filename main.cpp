//Лыков БАС2
#include <iostream>

using namespace std;

struct node {
    int di;
    double dd;
    node *next;
};

void outp(node* head) {
    node *tv;
    for (tv = head; tv != NULL; tv = tv->next) {
        cout << (*tv).di << ", " << (*tv).dd << " - " << &(*tv).di << " " << &(*tv).dd << endl;
    }
}

node* zap(node *one, node *head) {
    one = NULL;
    node *t2 = NULL;
    for (int i = 0; i < (*head).di; i++) {
        node *t = new node;
        (*t).di = rand() % 100;
        (*t).dd = (rand() % 100) / 100.0;
        t->next = NULL;
        if (one == NULL) {
            one = t;
            t2 = t;
            (*head).next = one;
        } else {
            (*t2).next = t;
            t2 = t;
        }
    }

    cout << "Заполненный список:\n";
    outp(head);

    double sum = 0.0;
    node *cur = one;
    node *last = NULL;
    while (cur != NULL) {
        sum += ((*cur).dd + (*cur).di);
        last = cur;
        cur = (*cur).next;
    }
    if (last != NULL) {
        (*head).di = sum;//сумма в первое поле заглавного (di)
        (*head).dd = (*last).dd;//вещественное поле последнего элемента
    }
    return one;
}

node* deleteSeven(node *one, node *head) {
    if (one == NULL) return NULL;

    for (int i = 0; i < 7; i++) {
        if (one == NULL) break;
        node *temp = one;
        one = one->next;
        delete temp;
    }
    (*head).next = one;
    return one;
}

int main() {
    srand(time(NULL));

    int k;
    cout << "Введите кол-о элементов списка: ";
    cin >> k;

    node *head = new node;
    (*head).next = NULL;
    (*head).di = k;
    (*head).dd = 0.0;

    node *one = NULL;
    one = zap(one, head);

    cout << "\nЗаглавный элемент:\n";
    cout << "Сумма значений полей " << (*head).di << endl;
    cout << "значение последнего элемента последнего элемента: " << (*head).dd << endl;

    cout << "список через с изменённым заглавным:\n";
    outp(head);

    one = deleteSeven(one, head);
    cout << "список после удаления 7 элементов:\n";
    outp(head);

    return 0;
}

/*
 ТЕСТ
Введите кол-о элементов списка: 10
Заполненный список:
10, 0 - 0xc2d000a00 0xc2d000a08
22, 0.22 - 0x105525970 0x105525978
70, 0.06 - 0x105525990 0x105525998
38, 0.64 - 0x105525800 0x105525808
24, 0.21 - 0x105525820 0x105525828
94, 0.96 - 0x105525840 0x105525848
22, 0.86 - 0x105525860 0x105525868
40, 0.24 - 0x105525880 0x105525888
24, 0.28 - 0x1055258a0 0x1055258a8
1, 0.01 - 0x1055258c0 0x1055258c8
29, 0.72 - 0x1055258e0 0x1055258e8

Заглавный элемент:
Сумма значений полей 368
значение последнего элемента последнего элемента: 0.72
список через с изменённым заглавным:
368, 0.72 - 0xc2d000a00 0xc2d000a08
22, 0.22 - 0x105525970 0x105525978
70, 0.06 - 0x105525990 0x105525998
38, 0.64 - 0x105525800 0x105525808
24, 0.21 - 0x105525820 0x105525828
94, 0.96 - 0x105525840 0x105525848
22, 0.86 - 0x105525860 0x105525868
40, 0.24 - 0x105525880 0x105525888
24, 0.28 - 0x1055258a0 0x1055258a8
1, 0.01 - 0x1055258c0 0x1055258c8
29, 0.72 - 0x1055258e0 0x1055258e8
список после удаления 7 элементов:
368, 0.72 - 0xc2d000a00 0xc2d000a08
24, 0.28 - 0x1055258a0 0x1055258a8
1, 0.01 - 0x1055258c0 0x1055258c8
29, 0.72 - 0x1055258e0 0x1055258e8

Process finished with exit code 0

 */