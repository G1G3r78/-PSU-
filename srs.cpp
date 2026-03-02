#include <iostream>

using namespace std;

struct och {
    int d;
    och *next;
};

struct STEK {
    double d;
    STEK *next;
};

struct STEK2 {
    double sum;
    double mult;
    double sr;
};

//процедура вывода очереди через пробел
void outpQueue(och* nach) {
    while (nach != NULL) {
        cout << (*nach).d << " ";
        nach = (*nach).next;
    }
}

//процедура вывода стека
void outpStek(STEK* head) {
    int elNum = 1;//счётчик элементов
    while (head != NULL) {
        STEK *yd = head;
        cout << elNum << " элемент - " << yd->d << endl;
        head = (*head).next;  // переход к следующему
        delete yd;          // удаление текущего
        elNum++;
    }
}

int main() {

    srand(time(NULL));

    // ==========
    // Задание 1

    //инициализация очереди
    och *nach;
    och *end;
    nach = NULL;
    end = NULL;

    //заполнение очереди
    for (int i = 1; i <= 10; i++) {
        och *t;
        t = new (och);
        (*t).d = rand() % 100;
        if (end == NULL) {
            end = t;
            nach = t;
        } else {
            (*end).next = t;
            end = t;
        }
        cout << i << " элемент очереди = " << (*end).d << endl;
    }

    //вывод через пробел значений очереди
    outpQueue(nach);

    //освобождение памяти
    nach = NULL;
    end = NULL;
    delete nach;
    delete end;

    // =================

    // =================
    // 2 задание

    //инициализация стека
    STEK *head;
    head = NULL;

    int n;
    double sum = 0.0, mult = 1.0, sr = 0.0;

    cout << "\nВведите кол-о элементов стека: ";
    cin >> n;

    //заполнение стека
    for (int i = 0; i < n; i++) {
        STEK *p = new STEK;
        (*p).d = (rand() % 100) * 0.1;
        (*p).next = head;  // новый элемент указывает на текущую голову
        head = p;        // новый элемент становится головой

        cout << "Добавление элемента " << (*head).d << endl;
        sum += (*p).d;
        mult *= (*p).d;
    }
    sr = sum / n;

    cout << "Полный стек:\n";
    outpStek(head);

    //инициализация и заполнение STEK2
    cout << "Сумма = " << sum << ", произв. = " << mult << ", ср. ариф. = " << sr << endl;
    STEK2 *t;
    t = new STEK2;
    (*t).sum = sum;
    (*t).mult = mult;
    (*t).sr = sr;

    return 0;
}

/*
1 элемент очереди = 11
2 элемент очереди = 6
3 элемент очереди = 74
4 элемент очереди = 23
5 элемент очереди = 69
6 элемент очереди = 38
7 элемент очереди = 84
8 элемент очереди = 69
9 элемент очереди = 69
10 элемент очереди = 56
11 6 74 23 69 38 84 69 69 56
Введите кол-о элементов стека: 5
Добавление элемента 2.2
Добавление элемента 4.3
Добавление элемента 4.5
Добавление элемента 4.5
Добавление элемента 5.6
Полный стек:
1 элемент - 5.6
2 элемент - 4.5
3 элемент - 4.5
4 элемент - 4.3
5 элемент - 2.2
Сумма = 21.1, произв. = 1072.76, ср. ариф. = 4.22
 */