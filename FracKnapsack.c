#include<stdio.h>

#define SIZE 3

int p[SIZE], w[SIZE];
float pw[SIZE];

int m;
float profit = 0;

void init_setup() {
    int i, j, curr;
    float temp;

    printf("Size of Knapsack = ");
    scanf("%d", &m);
    printf("Enter Profits: ");
    for(i=0; i<SIZE; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter Weights: ");
    for(i=0; i<SIZE; i++) {
        scanf("%d", &w[i]);
    }

    for(i=0; i<SIZE; i++) {
        pw[i] = (float) p[i]/ (float) w[i];
    }

    for(i=0; i<SIZE; i++) {
        for(j=i; j<SIZE; j++) {
            if(pw[j] > pw[i]) {
                temp = pw[j];
                pw[j] = pw[i];
                pw[i] = temp;

                curr = p[j];
                p[j] = p[i];
                p[i] = curr;

                curr = w[j];
                w[j] = w[i];
                w[i] = curr;
            }
        }
    }
}

void frac_knapsack() {
    int i;

    for(i=0; i<SIZE; i++) {
        if(m>0 && w[i] <= m) {
            m = m-w[i];
            profit = profit + (float)p[i];
        }
        else if(m>0) {
            profit = profit + (float)p[i]*((float)m/(float)w[i]);
            break;
        } 
    }

    printf("Maximum Profit = %f\n", profit);
}

void main() {
    init_setup();
    frac_knapsack();
}