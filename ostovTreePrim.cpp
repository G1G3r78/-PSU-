#include <iostream>

using namespace std;

const int n = 5;//кол-о вершин
const int graph[n][n] = { //смежная матрица весов рёбер
    {},
    {},
    {},
    {},
    {}
};

bool used[n];//признак наличия вершины в остове
int minEdge[n];//массив мин. весов рёбер
int parent[n];//хранит начальные вершины связные с данными

void prim(int src_graph /*изначальная вершина*/){
    for (int i = 0; i < n; i++) {
        minEdge[i] = 999;
        parent[i] = -1;
    }
    minEdge[src_graph] = 0;
    int totalWeight = 0;//общая стоимость
    ...
}