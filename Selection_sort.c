#include<stdio.h>
#include<time.h>

#define SIZE 10000

int best_arr[SIZE];
int worst_arr[SIZE];

void selection_sort(int arr[], int n) {
    int i, j, min, temp;

    for(i=0; i<n; i++) {
        min = arr[i];
        for(j=i; j<SIZE; j++) {
            if(arr[j] < min) {
                temp = arr[j];
                arr[j] = min;
                min = temp;
            }
        }
    }
}

void generate_best_array() {
    int i;

    for(i=0; i<SIZE; i++) {
        best_arr[i] = i+1;
    }
}

void generate_worst_array() {
    int i;

    for(i=0; i<SIZE; i++) {
        worst_arr[i] = SIZE - i;
    }
}

void main() {
    generate_best_array();
    generate_worst_array();

    clock_t start_best, end_best, start_worst, end_worst;
    double time_best, time_worst;

    start_best = clock();
    selection_sort(best_arr, SIZE);
    end_best = clock();
    time_best = ((double)(end_best - start_best)) / CLOCKS_PER_SEC;

    start_worst = clock();
    selection_sort(worst_arr, SIZE);
    end_worst = clock();
    time_worst = ((double)(end_worst - start_worst)) / CLOCKS_PER_SEC;

    printf("Best case time = %lf\n", time_best);
    printf("Worst case time = %lf", time_worst);
}