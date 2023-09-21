#include<stdio.h>
int main()
{
    int i, x;
    int num;
    int a[20];
    int flg=-1;
    int count=0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &num);
    printf("Enter %d elements in the array:\n", num);
    for(i=0; i<num; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the target element: ");
    scanf("%d", &x);
    for(i=0; i<num; i++)
    {
        count++;
        if(a[i]==x)
        {
            flg=i;
            printf("Element found at index %d in %d steps", i, count);
            break;
        }
    }
    if(flg==-1)
    {
        printf("Element not found!!");
    }
    return 0;
}