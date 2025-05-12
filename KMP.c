#include <stdio.h>

#define SIZE 15
#define n 5

char text[SIZE];
char pattern[n + 1];

int lps[n + 1];

void init_setup()
{
    int i, k, q;

    printf("Enter the Text of size %d: ", SIZE);
    scanf("%s", text);

    printf("Enter the pattern of size %d: ", n);
    scanf("%s", pattern);

    for (i = n - 1; i >= 0; i--)
    {
        pattern[i + 1] = pattern[i];
    }

    lps[1] = 0;
    k = 0;

    for (q = 2; q <= n; q++)
    {
        while (k > 0 && pattern[k + 1] != pattern[q])
        {
            k = lps[k];
        }
        if (pattern[k + 1] == pattern[q])
        {
            k = k + 1;
        }
        lps[q] = k;
    }
}

void KnuthMorrisPratt()
{
    int i = 0, j = 0, index;

    while (i <= SIZE)
    {
        if (text[i] == pattern[j + 1])
        {
            i++;
            j++;
        }
        else
        {
            if(j>0){
                j = lps[j + 1];
                i++;
            } else {
                i++;
            }
        }
        if (j == n)
        {
            printf("Pattern found at index %d in Text\n", i-n);
            return;
        }
    }
    
    printf("Pattern not found\n");
}

void main()
{
    init_setup();
    KnuthMorrisPratt();
}