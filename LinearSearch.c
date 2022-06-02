#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void delay()
{
    int temp,j;
    for( j = 0; j < 500000;j++)
    {
        temp = 10;
    }
}

int main()
{
    int n,i,arr[10000],key;
    int start, end;

    printf("Enter the value of n:");
    scanf("%d",&n);

    for(i = 0; i < n ; i++)
    {
        arr[i] = i;
    }

    key = arr[n-1];

    i = 0;
    start = clock();

    while(i < n && arr[i]!=key)
    {
        delay();h
       i++;
    }

    end = clock();

    printf("Excecution time is %lf",(double)(end - start)/CLOCKS_PER_SEC);

    if(i < n)
        printf("Element found at %d",i+1);
    else
        printf("Element not found");
    return 0;
}
