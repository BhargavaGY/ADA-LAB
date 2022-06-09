#include<stdio.h>
#include<time.h>

int key;

void delay()
{
    int j,temp;
    for(j = 0; j < 5000; j++)
        temp = 10;
}

int findNum(int arr[], int size)
{
    delay();
    int rec;
    size--;

    if(size >= 0)
        if(arr[size] == key)
            return size;
        else
            rec = findNum(arr,size);
    else
        return -1;

    return rec;

}

int main()
{
    int i,n, arr[10000];
    clock_t sTime, eTime;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        arr[i] = i;
    }
    key = 0;

    sTime = clock();
    int index = findNum(arr,n);
    eTime = clock();

    printf("excecution time is %lf",(double) (eTime-sTime)/CLOCKS_PER_SEC);

    if(index != -1)
        printf("Element found at %d", index);
    else
        printf("Element not found");

    return 0;
}
