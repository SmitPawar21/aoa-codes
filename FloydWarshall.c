#include<stdio.h>
#include<limits.h>

#define NODES 4

int INF = INT_MAX;

void floyd_ASSP(int graph[NODES][NODES]) {
    int i, j, k;

    for(k=0; k<NODES; k++) {
        for(i=0; i<NODES; i++) {
            for(j=0; j<NODES; j++) {
                if(graph[i][k]!=INF && graph[k][j]!=INF && graph[i][k] + graph[k][j] < graph[i][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
}

void main() {

    int graph[NODES][NODES] = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    floyd_ASSP(graph);

    int i, j;

    for(i=0; i<NODES; i++) {
        for(j=0; j<NODES; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

}