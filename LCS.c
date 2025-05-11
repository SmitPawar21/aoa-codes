#include<stdio.h>

char str1[100], str2[100];

int n, m;

void init_setup() {
    int i, j;

    printf("Enter the First word: ");
    scanf("%s", str1);
    printf("Enter the second word: ");
    scanf("%s", str2);

    i=0, j=0;
    while(str1[i] != '\0') {
        i++;
    }
    n = i;
    while(str2[j] != '\0') {
        j++;
    }
    m = j;
}

void match(char signs[m+1][n+1], int i, int j) {
    if(i==0 || j==0) {
        return;
    }

    if(signs[i][j] == '+') {
        match(signs, i-1, j-1);
        printf("%c ", str2[i-1]);
    } else if(signs[i][j] == '|') {
        match(signs, i-1, j);
    } else {
        match(signs, i, j-1);
    }

}

void LCS() {
    int i, j;
    int matrix[m+1][n+1];
    char signs[m+1][n+1];

    for(i=0; i<m+1; i++) {
        matrix[i][0] = 0;
    }
    for(j=0; j<n+1; j++) {
        matrix[0][j] = 0;
    }

    for(i=1; i<=m; i++) {
        for(j=1; j<=n; j++) {
            if(str1[j-1] == str2[i-1]) {
                matrix[i][j] = matrix[i-1][j-1] + 1;
                signs[i][j] = '+';
            } else {
                if(matrix[i-1][j] >= matrix[i][j-1]) {
                    matrix[i][j] = matrix[i-1][j];
                    signs[i][j] = '|';
                } else {
                    matrix[i][j] = matrix[i][j-1];
                    signs[i][j] = '-';
                }
            }
        }
    }

    match(signs, m, n);

}

void main() {
    init_setup();
    LCS();
}