#include<stdio.h>

int graph[10][10];
int visited[10];
int stack[10];
int top = -1;
int n;

void push(int val)
{
    stack[++top] = val;
}

void topologicalsort()
{
    int i;
    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for(i = 0; i < n; i++)
        if(!visited[i])
            topologicalrec(i);

    for(i = top; i > -1; i--)
    {
        printf("%d\t", stack[i]);
    }
}

void topologicalrec(int vertice)
{
    visited[vertice] = 1;

    for(int i = 0; i < n; i++)
    {
        if(graph[vertice][i] && !visited[i])
            topologicalrec(i);
    }

    push(vertice);
}

void main()
{
    int i,j;

    printf("enter the number of nodes");
    scanf("%d", &n);

    

    printf("enter the adjacency matrix \n");
    for(i = 0; i < n; i++)
    {
        for(j=0; j < n; j++)
            scanf("%d", &graph[i][j]);
    }

    topologicalsort(n);

}
