#include<stdio.h>

#define SIZE 10 //size for original Text
#define n 3 // size for pattern

char text[SIZE];
char pattern[n];

int mod_value;

int target_hash;

int value(char ch) {
    return (ch-'0')-48;
}

void init_setup() {
    int i;

    printf("Enter the Text of size %d: ", SIZE);
    scanf("%s", text);
    printf("Enter the pattern of size %d: ", n);
    scanf("%s", pattern);

    target_hash = 0;
    for(i=0; i<n; i++) {
        target_hash = (target_hash*10) + value(pattern[i]);
    }

    mod_value = 1;
    for(i=1; i<n; i++) {
        mod_value = mod_value*10;
    }
}

void RabinKarp() {
    int current_hash = 0;
    int i, k, index;

    for(i=0; i<n; i++) {
        current_hash = (current_hash*10) + value(text[i]);
    }

    k = n;
    while(target_hash != current_hash && k<SIZE) {
        current_hash = ((current_hash%mod_value)*10) + value(text[k]);
        k++;
    }

    if(target_hash == current_hash) {
        index = k-n;
    } else {
        index = -1;
    }

    if(index > -1) {
        printf("Match found at index %d in text.\n", index);
    } else {
        printf("Pattern not found in text\n");
    }
}

void main() {
    init_setup();
    RabinKarp();
}