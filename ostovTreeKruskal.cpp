#include <iostream>

using namespace std;

struct Edge { //ребро
    int u; //первая вершина
    int v; //вторая вершина
    int weight; //вес
};

const int max_edges = 100;
int parent[max_edges];//массив для хранения родителей вершин

void sortEdges(int m, Edge edges[]){//позырёк
    for (int i = 1; i < m; i++){
        for (int j = 0; i < m-i; j++){
            if (edges[j].weight > edges[j+1].weight){
                int temp = edges[j].weight;
                edges[j].weight = edges[j+1].weight;
                edges[j+1].weight = temp;
            }
        }
    }
};

int find(int v){ //поиск корня компоненты
    if (parent[v] == v) return v;//если вершина сама себе родитель - корень

    parent[v] = find(parent[v]);//поиск родителя
    return parent[v];
};

void unite(int u, int v){
    u = find(u);
    v = find(v);
    if (u != v) parent[v] = u;
};

void kruskal(int n, int m, Edge edges[]){//кол-о вершин, рёбер, массив рёбер
    for (int i = 0; i < n; i++) parent[i] = i; //изначально каждая вершина является отдельной компонентой

    sortEdges(m, edges);//сортировка по возрастанию

    int totalWeight = 0;//итоговая стоимость остовного дерева
    int edgeCount = 0;//кол-о добавленных рёбер в ост. дер.

    for (int i = 0; i < m; i++){//перебор всех отсортированных рёбер
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (find(u) != find(v)){//если вершины в разных кмпонентах
            unite(u, v);//объединяем компоненты вершин

            totalWeight += weight;//считаем стоимость
            edgeCount += 1;//увеличиваем кол-о рёбер

            if (edgeCount == n-1) break; //прекратить - дерево построено
        }
    }
}