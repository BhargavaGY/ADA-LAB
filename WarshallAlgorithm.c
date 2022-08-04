#include<stdio.h>

#define n 4


void printSolution(int graph[][n])
{
    printf("Solution array is:\n");
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    printf("1\t");
                else
                    printf("%d\t",graph[i][j]);
            }
            printf("\n");
        }
}

void findPath(int reach[][n])
{
    
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                reach[i][j] = reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }
    
    printSolution(reach);
}

void main()
{
    int graph[][n] = { {1, 1, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 1, 1},
                        {0, 0, 0, 1}
                      };
                    
    findPath(graph);
}

