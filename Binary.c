#include <stdio.h>

int main() 
{
    int n, target;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the sorted elements:\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element: ");
    scanf("%d", &target);

    int left = 0;
    int right = n - 1;
    int result = -1;
    int count=0;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) 
        {
            result = mid;
            count++;
            break;
        } 
        else if (arr[mid] < target) 
        {
            left = mid + 1;
            count++;
        } 
        else 
        {
            right = mid - 1;
            count++;
        }
    }

    if (result != -1) 
    {
        printf("Element %d found at index %d in %d step(s).\n", target, result, count);
    } 
    else 
    {
        printf("Element not found.\n");
    }

    return 0;
}
