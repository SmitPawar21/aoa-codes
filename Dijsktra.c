#include<stdio.h>
#include<limits.h>

#define NODES 5
#define SOURCE 0

int graph[NODES][NODES];
int visited[NODES];
int dist[NODES];

void init_setup() {
    int i, j;

    printf("Enter the values for Graph:\n");
    for(i=0; i<NODES; i++) {
        for(j=0; j<NODES; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for(i=0; i<NODES; i++) {
        visited[i] = 0;
        dist[i] = INT_MAX;
    }

    dist[SOURCE] = 0;
}

int findMin() {
    int i, index;
    int min = INT_MAX;

    for(i=0; i<NODES; i++) {
        if(!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }

    return index;
}

void dijsktra_SSSP() {
    int u, i;
    int count = NODES-1;

    while(count != 0) {
        u = findMin();
        visited[u] = 1;
    
        for(i=0; i<NODES; i++) {
            if(!visited[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i]) {
                dist[i] = dist[u] + graph[u][i];
            }
        }

        count--;
    } 
}

void display_distance() {
    int i;

    printf("\nShortest Distance From Source To All Nodes:\n");
    for(i=0; i<NODES; i++) {
        printf("%d -> %d = %d\n", SOURCE, i, dist[i]);
    }
}

void main() {
    init_setup();
    dijsktra_SSSP();
    display_distance();
}