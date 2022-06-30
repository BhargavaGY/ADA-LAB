#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void main()
{
    int i,j, key;
    int temp,n;
    int start, end;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    for(i=0; i < n; i++)
    {
        arr[i] = rand()%10000;
    }
    
    start = clock();
    
    for(i=1;i<n;i++)
    {
        key = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > key)
        {
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            j--;
        }
        key = arr[j+1];
    
    }
    end = clock();
    
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    printf("Excecution time is %lf",(double)(end - start)/CLOCKS_PER_SEC);
    
}
