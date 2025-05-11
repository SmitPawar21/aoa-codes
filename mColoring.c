#include <stdio.h>

#define NODES 4

int graph[NODES + 1][NODES + 1];
int x[NODES + 1];
int m;

void init_setup()
{
    int i, j;

    printf("Enter the max number of colours: ");
    scanf("%d", &m);

    printf("Enter the values for Graph with %d nodes:\n", NODES);
    for (i = 1; i <= NODES; i++)
    {
        for (j = 1; j <= NODES; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
}

void NextValue(int k)
{
    int j;

    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
        {
            return;
        }

        for (j = 1; j <= NODES; j++)
        {
            if (graph[k][j] != 0 && (x[k] == x[j]))
            {
                break;
            }
        }
        if (j == NODES + 1)
        {
            return;
        }
    }
}

void mColoring(int k)
{
    int i;

    while (1)
    {
        NextValue(k);

        if (x[k] == 0)
        {
            return;
        }
        if (k == NODES)
        {
            for (i = 1; i <= k; i++)
            {
                printf("%d ", x[i]);
            }
            printf("\n");
        }
        else
        {
            mColoring(k + 1);
        }
    }
}

void main()
{
    init_setup();
    printf("Answers:\n");
    mColoring(1);
}