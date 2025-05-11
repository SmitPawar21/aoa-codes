#include<stdio.h>
#include<stdlib.h>

#define N 8

int x[N+1];

int Place(int k, int i) {
    int j;

    for(j=1; j<=k-1; j++) {
        if((x[j] == i) || (abs(x[j] - i) == abs(j-k))) {
            return 0;
        }
    }

    return 1;
}

void NQueens(int k, int n) {
    int i, j;

    for(i=1; i<=n; i++) {
        if(Place(k, i)) {
            x[k] = i;

            if(k==N) {
                for(j=1; j<=n; j++) {
                    printf("%d ",x[j]);
                }
                printf("\n");
            } else {
                NQueens(k+1, n);
            }
        }
    }
}

void main() {
    int i;

    for(i=1; i<=N; i++) {
        x[i] = 0;
    }

    NQueens(1, N);
}