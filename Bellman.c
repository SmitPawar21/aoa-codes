#include<stdio.h>
#include<limits.h>

#define NODES 5
#define EDGES 7
#define SOURCE 0

int u[EDGES], v[EDGES], weight[EDGES];
int dist[NODES];

void init_setup() {
    int i;
    
    printf("There are %d nodes and %d edges.\n", NODES, EDGES);
    printf("Enter the values for u, v and weight:\n");
    for(i=0; i<EDGES; i++) {
        scanf("%d %d %d", &u[i], &v[i], &weight[i]);
    }

    for(i=0; i<NODES; i++) {
        dist[i] = INT_MAX;
    }

    dist[SOURCE] = 0;
}

void bellman_SSSP() {
    int i;
    int count = NODES;

    while(count != 0) {
        for(i=0; i<EDGES; i++) {
            if(dist[u[i]] != INT_MAX && dist[u[i]] + weight[i] < dist[v[i]]) {
                dist[v[i]] = dist[u[i]] + weight[i];
            }
        }

        count--;
    }
}

void display_path() {
    int i;

    for(i=0; i<NODES; i++) {
        printf("%d -> %d = %d\n", SOURCE, i, dist[i]);
    }
}

void main() {
    init_setup();
    bellman_SSSP();
    display_path();
}