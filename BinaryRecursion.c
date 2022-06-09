#include<stdio.h>
#include<time.h>

int key = 0;

void delay()
{
    int j,temp;
    for(j = 0; j < 10000; j++)
        temp = 10;
}

int BinaryRec(int arr[],int end, int beg)
{
    int index;

    if(beg <= end)
    {
        delay();
        int mid = (end + beg)/2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
        {
            end = mid - 1;
            index = BinaryRec(arr,end, beg);
        }
        else
        {
            beg = mid + 1;
            index = BinaryRec(arr,end,beg);
        }

    }
    else
        return -1;

    return index;

}

void main()
{
    int i,n, arr[10000];
    clock_t sTime, eTime;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        arr[i] = i;
    }

    sTime = clock();
    int index = BinaryRec(arr,n-1,0);
    eTime = clock();

    printf("excecution time is %lf",(double) (eTime-sTime)/CLOCKS_PER_SEC);

    if(index != -1)
        printf("Element found at %d", index);
    else
        printf("Element not found");

}
