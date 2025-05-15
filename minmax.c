#include<stdio.h>
#include<limits.h>

int min = INT_MAX;
int max = INT_MIN;

void minmax(int arr[], int s, int e) {
    int mid;

    if(s == e) {
        if(arr[s] < min) {
            min = arr[s];
        }
        if(arr[e] > max) {
            max = arr[e];
        }
        return;
    }

    else if(e == s+1) {
        if(arr[s] < arr[e]) {
            if(arr[s] < min) min = arr[s];
            if(arr[e] > max) max = arr[e];
        }
        if(arr[s] > arr[e]) {
            if(arr[s] > max) max = arr[s];
            if(arr[e] < min) min = arr[e];
        }
    }

    else {
        mid = (s+e)/2;

        minmax(arr, s, mid);
        minmax(arr, mid+1, e);
    }
}

void main() {
    int arr[6] = {2,6,4,-1,7,8};
    int n = sizeof(arr) / sizeof(arr[0]);

    minmax(arr, 0, n-1);
    printf("max = %d\n", max);
    printf("min = %d", min);
}