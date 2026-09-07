#include <iostream>

using namespace std;

const int n = 5; // кол-о вершин

int a[n][n] = { //матрица начальных мин. расстояний (связей)
    {0, 10, 999, 30, 100},
    {10, 0, 50, 999, 999}, 
    {999, 50, 0, 20, 10}, 
    {30, 999, 20, 0, 60},
    {100, 999, 10, 60, 0}
};

void printM(int a[n][n]){
    cout << "Матрица расстояний:\n";
    cout << "    1    2    3    4\n";
    for (int i = 0; i < n; i++){
        cout << i+1 << "   ";
        for (int j = 0; j < n; j++){
            (a[i][j] / 100 > 0) ? cout << a[i][j] << " " : cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}

int main() {

    int d[n]; //массив мин. расстояний
    int prev[n]; //предшествующие вершины данным
    int temp;
    int minInd, mini; //индекс мин. вершины и мин. вес соответсвено
    bool v[n]; //посещённые вершины

    for (int i = 0; i < n; i++){
        d[i] = 999;
        prev[i] = -1;
        v[i] = false;
    }
    d[0] = 0; // d[i] - начальная вершина

    do {
        minInd = 999;
        mini = 999;
        for (int i = 0; i < n; i++){
            if (v[i] == false && d[i] < mini) {
                mini = d[i];
                minInd = i;
            }
        }
        if (minInd != 999) {
            for (int j = 0; j < n; j++){
                if (a[minInd][j] > 0) {
                    temp = mini + a[minInd][j];
                    if (temp < d[j]) {
                        d[j] = temp;
                        prev[j] = minInd + 1;
                    }
                }
            }
            v[minInd] = true;
        }
    } while (minInd < 999);

    cout << "Мин. путь от 1 до 4: " << d[3];

    return 0;
}