#include<stdio.h>
#include<time.h>

#define SIZE 10000

int best_arr[SIZE];
int worst_arr[SIZE];

void insertion_sort(int arr[], int n) {
    int i, j, key;

    for(i=0; i<n; i++) {
        key = arr[i];
        j = i-1;

        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }

        arr[j+1] = key;
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
    insertion_sort(best_arr, SIZE);
    end_best = clock();
    time_best = ((double)(end_best - start_best)) / CLOCKS_PER_SEC;

    start_worst = clock();
    insertion_sort(worst_arr, SIZE);
    end_worst = clock();
    time_worst = ((double)(end_worst - start_worst)) / CLOCKS_PER_SEC;

    printf("Time for Best Case: %lf\n", time_best);
    printf("Time for Worst Case: %lf", time_worst);
}