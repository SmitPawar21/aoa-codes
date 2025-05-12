#include<stdio.h>

#define SIZE 2

void main() {
    int p, q, r, s, t, u, v, i, j;
    int a[SIZE][SIZE] = {{1,2}, {3,4}};
    int b[SIZE][SIZE] = {{3,4}, {5,6}};
    int c[SIZE][SIZE];

    p = (a[0][0] + a[1][1])*(b[0][0] + b[1][1]);
    q = (a[0][1] + a[1][1])*(b[0][0]);
    r = (a[0][0])*(b[0][1] - b[1][1]);
    s = (a[1][1])*(b[1][0] - b[0][0]);
    t = (a[0][0] + a[0][1])*(b[1][1]);
    u = (a[1][0] - a[0][0])*(b[0][0] + b[0][1]);
    v = (a[0][1] - a[1][1])*(b[1][0] + b[1][1]);

    c[0][0] = p+s-t+v;
    c[0][1] = r+t;
    c[1][0] = q+s;
    c[1][1] = p+r-q+u;

    printf("Answer:\n");
    for(i=0; i<SIZE; i++) {
        for(j=0; j<SIZE; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

}