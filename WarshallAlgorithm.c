#include<stdio.h>

#define INF  99999
#define n 4


void printSolution(int graph[][n])
{
    printf("Solution array is:\n");
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(graph[i][j] == INF)
                    printf("INF\t");
                else
                    printf("%d\t",graph[i][j]);
            }
            printf("\n");
        }
}

void findShortestPath(int dist[][n])
{
    
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j] 
                &&(dist[i][k] != INF && dist[k][j] != INF))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    
    printSolution(dist);
}

void main()
{
    int graph[][n] = { {0,   5,  INF, 10},
                    {INF,  0,  3,  INF},
                    {INF, INF, 0,   1},
                    {INF, INF, INF, 0} };
                    
    findShortestPath(graph);
}

