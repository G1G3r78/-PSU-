#include <stdio.h>

typedef struct edge { //ребро
    int src; //начальная вершина ребра
    int dest;//конечная
    int wt;  //вес ребра
} edge;

const int maxi = 999;

void bellman_ford(int nv, edge e[], int src_graph, int ne){//кол-о вершин, массив рёбер, нач. вершина, кол-о рёбер
    int u, v, weight;//нач. и конеч. вершина, итераторы, вес
    int dis[maxi];//массив крат. расстояний

    for (int i = 0; i < nv; i++){
        dis[i] = maxi;
    }
    dis[src_graph] = 0;//начальная вершина всегда 0

    for (int i = 0; i < nv-1; i++){
        for (int j = 0; j < ne; j++){
            u = e[j].src;
            v = e[j].dest;
            weight = e[j].wt;

            if (dis[u] != 999 && dis[v] > dis[u] + weight) dis[v] = dis[u]+weight;
        }
    }
    for (int j = 0; j < ne; j++){
        u = e[j].src;
        v = e[j].dest;
        weight = e[j].wt;

        if (dis[v] > dis[u] + weight) {
            printf("Отрицательный цикл!\n");
            return;
        }
    }

    //вывод расстояний
    for (int i = 1; i <= nv; i++){
        printf("\n%d\t%d", i, dis[i]);
    }
}