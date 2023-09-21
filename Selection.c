#include <stdio.h>

int main() 
{
    int n, arr[100], count=0;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
              minIndex = j;
            }
        }
        if (minIndex != i) 
        {
          count++;
          int temp = arr[i];
          arr[i] = arr[minIndex];
          arr[minIndex] = temp;
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Number of steps: %d", count);

    return 0;
}