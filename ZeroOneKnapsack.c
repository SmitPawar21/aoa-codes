#include<stdio.h>

#define n 5 // number of elements
#define m 7 // knapsack size

int dp[n+1][m+1];
int profit[n], weight[n];
int x[n];

void init_setup() {
    int i;

    printf("Enter values for profits:\n");
    for(i=0; i<n; i++) {
        scanf("%d", &profit[i]);
    }
    printf("Enter values for weights:\n");
    for(i=0; i<n; i++) {
        scanf("%d", &weight[i]);
    }
}

int max(int a, int b) {
    return (a>b) ? a : b;
}

void knapsack_table() {
    int i, w;

    for(i=0; i<=n; i++) {
        for(w=0; w<=m; w++) {
            if(i==0 || w==0) {
                dp[i][w] = 0;
            }

            if(w < weight[i-1]) {
                dp[i][w] = dp[i-1][w];
            } else {
                dp[i][w] = max(dp[i-1][w], profit[i-1] + dp[i-1][w-weight[i-1]]);
            }
        }
    }
}

void display_answer() {
    int max = dp[n][m];
    int i, w;

    for(i=0; i<n; i++) {
        x[i] = 0;
    }

    w = m;
    for(i=n; i>0; i--) {
        if(w!=0 && dp[i][w] != dp[i-1][w]) {
            x[i-1] = 1;
            w = w - weight[i-1];
        }
    }

    for(i=0; i<n; i++) {
        printf("%d ", x[i]);
    }
}

void main() {
    init_setup();
    knapsack_table();
    display_answer();
}

