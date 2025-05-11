#include<stdio.h>

#define SIZE 6

int x[SIZE];
int w[SIZE];

int total = 0;
int target;

void init_setup() {
    int i;

    printf("Enter the value for Target = ");
    scanf("%d", &target);

    printf("Enter the values for w array:\n");
    for(i=0; i<SIZE; i++) {
        scanf("%d", &w[i]);
    }
    for(i=0; i<SIZE; i++) {
        total = total + w[i];
    }
}

void SumOfSub(int s, int k, int r) {
    int i;

    x[k] = 1;
    if(s+w[k] == target) {
        for(i=0; i<=k; i++) {
            if(x[i] == 1) {
                printf("%d ", w[i]);
            }
        }
        printf("\n");
    }
    else if(s+w[k]+w[k+1] <= target) {
        SumOfSub(s+w[k], k+1, r-w[k]);
    } 

    if((s+r-w[k] >= target) && (s+w[k+1] <= target)) {
        x[k] = 0;
        SumOfSub(s, k+1, r-w[k]);
    }
}

void main() {
    init_setup();
    SumOfSub(0, 0, total);
}