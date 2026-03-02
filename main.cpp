#include <iostream>
using namespace std;

struct R {
    double d;
    R *next;
};

struct Y {
    int d;
    Y *next;
};

struct U {
    double dS;
    int dQ;
    U *next;
};

R* initStek(R* origin) {
    origin = new R;
    (*origin).d = (rand() % 100) * 0.1;
    cout << (*origin).d << endl;
    (*origin).next = NULL;
    return origin;
}

R* zapStek(R* st, int NR) {
    for (int i = 1; i < NR; i++) {
        R *p;
        p = new R;
        (*p).d = (rand() % 100) * 0.1;
        cout << (*p).d << endl;
        (*p).next = st;
        st = p;
    }
    return st;
}

void outpStek(R* st) {
    R* current = st;
    while (current != NULL) {
        cout << (*current).d << " ";
        current = (*current).next;
    }
    cout << endl;
}

Y* zapQueue(Y* yo, Y *zo, int NY) {
    for (int i = 0; i < NY; i++) {
        Y *t;
        t = new (Y);
        (*t).d = rand() % 100;
        if (zo == NULL) {
            zo = t;
            yo = t;
        } else {
            (*zo).next = t;
            zo = t;
        }
    }
    return yo;
}

void outpQueue(Y* yo) {
    while (yo != NULL) {
        cout << (*yo).d << " ";
        yo = (*yo).next;
    }
}

void outpU(U* u) {
    U* cur = u;
    while (cur != NULL) {
        cout << "(" << (*cur).dS << ", " << (*cur).dQ << ") ";
        cur = (*cur).next;
    }
    cout << endl;
}

U* zapU(R* &st, Y* &yo) { // Передаем по ссылке, чтобы обнулить оригиналы
    U *u = NULL;
    U *currentU = NULL;

    // Заполнение из стека R
    while (st != NULL) {
        U *newU = new U;
        (*newU).dS = (*st).d;  // Берем значение из стека
        (*newU).dQ = 0;         // Для элементов из стека dQ = 0
        (*newU).next = NULL;

        if (u == NULL) {
            u = newU;
            currentU = u;
        } else {
            (*currentU).next = newU;
            currentU = newU;
        }

        // Удаляем элемент из стека
        R *temp = st;
        st = (*st).next;
        delete temp;
    }

    // Заполнение из очереди Y
    while (yo != NULL) {
        U *newU = new U;
        (*newU).dS = 0;          // Для элементов из очереди dS = 0
        (*newU).dQ = (*yo).d;     // Берем значение из очереди
        (*newU).next = NULL;

        if (u == NULL) {
            u = newU;
            currentU = u;
        } else {
            (*currentU).next = newU;
            currentU = newU;
        }

        // Удаляем элемент из очереди
        Y *temp = yo;
        yo = (*yo).next;
        delete temp;
    }

    return u;
}
int main() {
    srand(time(NULL));

    int NR, NY;
    cout << "Введите кол-о элементов стека: R: ";
    cin >> NR;

    //инициализация стека R
    R *st;
    st = NULL; //вершина стека
    st = initStek(st);

    //заполнение стека R и его вывод
    st = zapStek(st, NR);
    cout << "стек R: ";
    outpStek(st);

    cout << "Введите кол-о элементов очереди Y: ";
    cin >> NY;

    //инициализация очереди Y
    Y *yo;//начало очереди
    Y *zo;//конец очереди
    yo = NULL;
    zo = NULL;

    //заполнение очереди
    yo = zapQueue(yo, zo, NY);
    //вывод очереди Y
    cout << "Очередь Y: ";
    outpQueue(yo);
    cout << endl;

    //создание списка U
    U *u;
    u = NULL;
    u = zapU(st, yo);
    cout << "Список U: ";
    outpU(u);

    return 0;
}