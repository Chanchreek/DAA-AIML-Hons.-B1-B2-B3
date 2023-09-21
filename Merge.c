#include <stdio.h>

void merge(int arr[], int left[], int right[], int left_size, int right_size) 
{
    int i = 0, j = 0, k = 0;
    
    while (i < left_size && j < right_size) 
    {
        if (left[i] <= right[j]) 
        {
            arr[k++] = left[i++];
        } 
        else 
        {
            arr[k++] = right[j++];
        }
    }

    while (i < left_size) 
    {
        arr[k++] = left[i++];
    }

    while (j < right_size) 
    {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int n) 
{
    if (n <= 1) 
    {
        return;
    }

    int mid = n / 2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++) 
    {
        left[i] = arr[i];
    }
    for (int i = mid; i < n; i++) 
    {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, n - mid);

    merge(arr, left, right, mid, n - mid);
}

int main() 
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
