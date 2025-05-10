#include<stdio.h>
#include<limits.h>

#define EDGES 5
#define NODES 5

int u[EDGES], v[EDGES], weight[EDGES];
int parent[NODES];

int total_weight = 0;

int find(int x) {
    while(parent[x] != x) {
        x = parent[x];
    }

    return x;
}

void union_set(int a, int b) {
    a = find(a);
    b = find(b);

    parent[a] = b;
}

void init_setup() {
    int i;

    for(i=0; i<NODES; i++) {
        parent[i] = i;
    }

    printf("Enter the values for u, v and weight\n");
    for(i=0; i<EDGES; i++) {
        scanf("%d %d %d", &u[i], &v[i], &weight[i]);
    }
}

void sort_all_edges() {
    int i, j, temp;

    for(i=0; i<EDGES; i++) {
        for(j=i; j<EDGES; j++) {
            if(weight[j] < weight[i]) {
                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = u[i];
                u[i] = u[j];
                u[j] = temp;

                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

void calculate_MST() {
    int i, a, b;

    printf("Edge list in MST:\n");
    for(i=0; i<EDGES; i++) {
        a = find(u[i]);
        b = find(v[i]);

        if(a != b) {
            printf("%d - %d\t %d\n", u[i], v[i], weight[i]);
            total_weight = total_weight + weight[i];
            union_set(a, b);
        }
    }
}

void main() {
    init_setup();
    sort_all_edges();
    calculate_MST();

    printf("\nTotal minimum cost required = %d", total_weight);
}