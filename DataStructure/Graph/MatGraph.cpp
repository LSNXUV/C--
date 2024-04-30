#include <iostream>

using namespace std;

#define MAXVEX 100

typedef char VertexType[10];

typedef struct vertex
{
    int adjvex;
    VertexType data;
} VType;

typedef struct graph
{
    int n,e;
    VType vexs[MAXVEX];
    int edges[MAXVEX][MAXVEX];
} MatGraph;




int main(){


    system("pause");
    return 0;
}