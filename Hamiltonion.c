#include<stdio.h>

#define NODES 4

int graph[NODES+1][NODES+1];
int x[NODES+1];

void init_setup() {
    int i, j;

    printf("Enter the values for Graph with %d nodes:\n", NODES);
    for(i=1; i<=NODES; i++) {
        for(j=1; j<=NODES; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void NextValue(int k) {
    int j;

    while(1) {
        x[k] = (x[k]+1)%(NODES+1);
        if(x[k] == 0) {
            return;
        }
        if(graph[x[k-1]][x[k]] != 0) {
            for(j=1; j<=k-1; j++) {
                if(x[j] == x[k]) {
                    break;
                }
            }

            if(j == k) {
                if(k<NODES || ((k==NODES) && (graph[x[NODES]][x[1]] != 0))) {
                    return;
                }
            }
        }
    }
}

void hamiltonion(int k) {
    int i;

    while(1) {
        NextValue(k);
        if(x[k] == 0) {
            return;
        }
        if(k == NODES) {
            for(i=1; i<=NODES; i++) {
                printf("%d ", x[i]);
            }
            printf("%d\n", x[1]);
        }
        else {
            hamiltonion(k+1);
        }
    }
}

void main() {
    init_setup();
    x[1] = 1;
    printf("Answers:\n");
    hamiltonion(2);
}