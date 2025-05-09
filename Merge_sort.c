#include<stdio.h>
#include<time.h>

#define SIZE 10000

int best_arr[SIZE];
int worst_arr[SIZE];

void merge(int arr[], int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int i, j, k;

    int L[n1], R[n2];
    for(i=0; i<n1; i++) {
        L[i] = arr[start+i];
    }
    for(i=0; i<n2; i++) {
        R[i] = arr[mid+1+i];
    }

    i=0, j=0, k=start;

    while(i<n1 && j<n2) {
        if(L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while(i<n1) {
        arr[k++] = L[i++];
    }
    while(j<n2) {
        arr[k++] = R[j++];
    }
}

void merge_sort(int arr[], int start, int end) {
    if(start < end) {
        int mid = (start+end)/2;
    
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
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
    merge_sort(best_arr, 0, SIZE-1);
    end_best = clock();
    time_best = ((double)(end_best - start_best)) / CLOCKS_PER_SEC;

    start_worst = clock();
    merge_sort(worst_arr, 0, SIZE-1);
    end_best = clock();
    time_worst = ((double)(end_worst - start_worst)) / CLOCKS_PER_SEC;

    printf("Best case time = %lf\n", time_best);
    printf("Worst case time = %lf\n", time_worst);
}