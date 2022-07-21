#include<stdio.h>

void quicksort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pivot_index = partition(arr,low,high);
        
        quicksort(arr,low,pivot_index-1);
        quicksort(arr,pivot_index+1,high);
    }
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    
    int i = low - 1;
    int temp;
    
    for(int j = 0; j <= high-1; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    
    temp = arr[i+1];
    arr[i+1] = pivot;
    arr[high] = temp;
    
    return i+1;
    
}

void printArray(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d\t",arr[i]); 
    }
}

void  main()
{
    int arr[] = {10, 30, 80, 90, 40, 50, 70};
    
    
    printf("Array before sorting\n");
    printArray(arr, 7);
    
    quicksort(arr,0,6);
    
    printf("Array after sorting\n");
    printArray(arr, 7);
    
}
