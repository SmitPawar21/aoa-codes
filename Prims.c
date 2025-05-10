#include<stdio.h>
#include<limits.h>

#define NODES 7

int graph[NODES][NODES];
int answer[NODES][NODES];
int visited[NODES];

int minimum_cost = 0;
int source = 0;

void init_setup() {
    int i, j;

    printf("Enter the values for Graph matrix:\n");
    for(i=0; i<NODES; i++) {
        for(j=0; j<NODES; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for(i=0; i<NODES; i++) {
        visited[i] = 0;
    }
}

void calculate_MST() {
    visited[0] = 1; // source
    int i, j, min;
    int x, y;
    int count = NODES - 1;

    while(count != 0) {
        x = -1, y = -1;
        min = INT_MAX;

        for(i=0; i<NODES; i++) {

            if(visited[i]) {
                for(j=0; j<NODES; j++) {
                    if(visited[j] == 0 && (graph[i][j] != 0) && graph[i][j] < min) {
                        min = graph[i][j];
                        x=i;
                        y=j;
                    }
                }
            }
        }

        if(x>-1 && y>-1) {
            minimum_cost = minimum_cost + graph[x][y];
            visited[y] = 1;
            printf("%d - %d\t %d\n",x,y,graph[x][y]);
            count--;
        } else {
            printf("\nGraph is not connected\n");
        }
    }
}   

void main() {
    init_setup();
    calculate_MST();
    printf("\nMinimum cost = %d", minimum_cost);
}