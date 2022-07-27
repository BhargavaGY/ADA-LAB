#include<stdio.h>
#include<stdbool.h>

bool LEFT_TO_RIGHT = true;
bool RIGHT_TO_LEFT = false;

int findPosition(int a[], int mobile, int n)
{
    for(int i=0; i<n; i++)
    {
        if(a[i] == mobile)
            return i+1;
    }
}

int findMobile(int a[], bool dir[], int n)
{
    int mobile = 0, prev_mobile = 0;

    for(int i=0; i<n;i++)
    {
        if(dir[a[i]-1] == RIGHT_TO_LEFT && i !=0)
        {
            if(a[i] > a[i-1]  && a[i] > mobile)
            {
                mobile = a[i];
                prev_mobile = mobile;
            }
        }

        if(dir[a[i]-1] == LEFT_TO_RIGHT && i != n-1)
        {
            if(a[i] > a[i+1] && a[i] > mobile)
            {
                mobile = a[i];
                prev_mobile = mobile;
            }
        }
    }

    if(mobile == 0)
        return 0;
    else
        return mobile;
}

void printOnepermutation(int a[], bool dir[], int n)
{
    int mobile = findMobile(a, dir,n);
    int pos = findPosition(a,mobile,n);

    int temp;
    if(dir[a[pos-1]-1] == RIGHT_TO_LEFT)
    {
        temp = a[pos-1];
        a[pos-1] = a[pos-2];
        a[pos-2] = temp;
    }
    else
    {
        temp = a[pos-1];
        a[pos-1] = a[pos];
        a[pos] = temp;
    }
    

    for(int i=0; i<n; i++)
    {
        if(a[i] > mobile)
        {
            if(dir[a[i]-1] == RIGHT_TO_LEFT)
                dir[a[i]-1] = LEFT_TO_RIGHT;
            else
                dir[a[i]-1] = RIGHT_TO_LEFT;
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("%d", a[i]);
    }
    printf("\t");
}

int fact(int val)
{
    int res = 1;
    for(int j=0; j<val;j++)
    {
        res = res*(j+1);
    }
    return res;
}

void printPermutation(int n)
{
    int a[n];
    bool dir[n];

    for(int i=0; i<n; i++)
    {
        a[i] = i+1;
        printf("%d",a[i]);
    }
    printf("\t");

    for(int i=0; i<n;i++)
    {
        dir[i] = RIGHT_TO_LEFT;
    }

    for(int i=0; i<fact(n); i++)
    {
        printOnepermutation(a,dir,n);
    }
    
}

void main()
{
    int n;
    printf("Enter the number of digits\n");
    scanf("%d", &n);

    printPermutation(n);
}
