#include<stdio.h>
#include<limits.h>

#define n 4

int m[n+1][n+1];
int s[n][n];

void matrix_chain(int p[]) {
    int i, j, k, l, q, min;

    for(l=2; l<=n; l++) {
        for(i=1; i<=n-l+1; i++) {
            j = i+l-1;
            m[i][j] = INT_MAX;

            for(k=i; k<j; k++) {
                q = m[i][k] + m[k+1][j] + (p[i-1]*p[j]*p[k]);
                if(q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++) {
            if(i>j) {
                printf("-\t");
            } else {
                printf("%d\t", m[i][j]);
            }
        }
        printf("\n");
    }
}

void optimalparens(int i, int j) {
    if(i==j) {
        printf("A%d ", i);
    } else {
        printf("(");
        optimalparens(i, s[i][j]);
        optimalparens(s[i][j]+1, j);
        printf(")");
    }

}

void main() {
    int p[] = {5, 4, 6, 2, 7};
    matrix_chain(p);

    printf("\n");
    optimalparens(1, n);
}