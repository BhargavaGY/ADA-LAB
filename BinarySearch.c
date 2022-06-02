#include<stdio.h>
#include<time.h>

void delay()
{
    int temp, j;

    for(j = 0; j < 50000; j++)
        temp = 10;
}

int main()
{
    int arr[10000],i,n,key;
    clock_t sTime, eTime;
    int mid,end,beg;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        arr[i] = i;

    key = n + 1;
    end = n - 1;
    beg = 0;

    sTime = clock();

    while(beg <= end)
    {
        delay();
        mid = (end + beg)/2;

        if(arr[mid] == key)
        {
            printf("Element found at %d", mid+1);
            return 0;
        }
        else if(arr[mid] > key)
            end = mid - 1;
        else
            beg = mid + 1;
    }

    eTime = clock();

    printf("Execution time is %lf", (double)(eTime - sTime)/CLOCKS_PER_SEC);

    printf("Element not found \n");
    return 0;
}
