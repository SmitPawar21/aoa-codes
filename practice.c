#include<stdio.h>

#define n 6

void quick_sort(int arr[], int s, int e) {
    if(s<e) {
        pi = partition(arr, s, e);

        quick_sort(arr, s , pi);
        quick_sort(arr, pi, e);
    }
}

void main() {
    int arr[n] = {1,5,-1,8,7,6};

    printf("Original array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    quick_sort(arr, 0, n-1);

    printf("Sorted array: ");
    for(i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}