#include <iostream>

#include <queue>
#include <stack>
#include <list>

using namespace std;

//уже реализовано в библ. STL
/*template <class T, class Container = deque<T> >
class queue;*/

/*template <class T, class Container = deque<T> >
class stack;*/

void outpSP(list<int> SP) {
    for (int numSP: SP) {
        cout << numSP << " ";
    }
    cout << endl;
}

list<int> zapSP(list<int> SP, int n) {
    cout << "Заполнение первой половины списка с начала:\n";
    for (int i = 0; i < n/2; i++) {
        SP.push_front(rand() % 100);
        outpSP(SP);
    }
    cout << "Заполнение другой половины списка с конца:\n";
    for (int j = n/2; j < n; j++) {
        SP.push_back(rand() % 100);
        outpSP(SP);
    }
    return SP;
}

int main() {

    srand(time(NULL));

    //задание 1
    //Очередь
    queue<int> q;

    //заполнение
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Очередь:\n";
    cout << "Первый элемент: " << q.front() << endl;
    cout << "Последний элемент: " << q.back() << endl;
    cout << "Размерность: " << q.size() << endl;

    // вывод и удаление
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    //проверка пустоты
    cout << (q.empty() ? "\nОчередь пуста" : "\nОчередь заполнена") << endl;

    //Стек
    stack<int> s;

    // заполнение
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "\nСтек:\n";
    cout << "Вершина стека: " << s.top() << endl;
    cout << "Размер: " << s.size() << endl;

    //удаление
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    //проверка пустоты
    cout << (s.empty() ? "\nСтек пуст" : "\nСтек заполнен") << endl;

    //задание 2
    int nSP, delNumSP, addNumSP, indSP, amountSP, numsIndSP;
    list<int> SP;
    cout << "Введите кол-о элементов list: ";
    cin >> nSP;

    cout << "Заполнение list:\n";
    SP = zapSP(SP, nSP);
    cout << "Вывод полного list:\n";
    outpSP(SP);

    cout << "Какой элемент удалить: ";
    cin >> delNumSP;

    list<int>::iterator p = SP.begin();
    bool found = false;
    while (p != SP.end()) {
        if (*p == delNumSP) found = true;
        p++;
    }
    if (found) SP.remove(delNumSP);
        else cout << "Число не найдено\n";
    cout << "Вывод list после удаления:\n";
    if (SP.empty()) cout << "list пуст\n";
     else outpSP(SP);

    cout << "Какое число вставить: ";
    cin >> addNumSP;
    cout << "На какой индекс вставить: ";
    cin >> indSP;

    auto addP = SP.begin();
    advance(addP, indSP);
    SP.insert(addP, addNumSP);
    cout << "list после добавления:\n";
    outpSP(SP);

    cout << "Сколько чисел вставить: ";
    cin >> amountSP;
    cout << "На какой индекс эти числа вставить: ";
    cin >> numsIndSP;
    addP = SP.begin();
    advance(addP, numsIndSP);
    for (int i = 0; i < amountSP; i++) {
        int value = rand() % 100;
        addP = SP.insert(addP, value);
        advance(addP, 1);
    }
    cout << "list после добавления:\n";
    outpSP(SP);

    int rangeIndBeg, rangeIndEnd;
    cout << "Укажите диапазон вставки элементов:\n";
    cout << "Укажите индекс начала диапазона: ";
    cin >> rangeIndBeg;
    cout << "Укажите индекс конца диапазона: ";
    cin >> rangeIndEnd;

    auto startP = SP.begin(), endP = SP.end();
    advance(startP, rangeIndBeg);
    advance(endP, rangeIndEnd);

    for (int i = rangeIndBeg; i <= rangeIndEnd; i++) {
        int value = rand() % 100;
        startP = SP.insert(startP, value);
        advance(startP, 1);
    }
    cout << "list после вставки диапазона:\n";
    outpSP(SP);

    return 0;
}