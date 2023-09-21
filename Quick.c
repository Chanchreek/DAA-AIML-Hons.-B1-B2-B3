#include <stdio.h>

void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
	printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int arr[], int low, int high) 
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;
    int temp;


    do
    {
        while(arr[i]<=pivot)
        {
    	    i++;
        }

        while(arr[j]>pivot)
        {
    	    j--;
        }

        if(i<j)
        {
    	    temp=arr[i];
	        arr[i]=arr[j];
	        arr[j]=temp;
        }

    }while(i<j);

    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi;//index of pivot after partition
	    pi = partition(arr, low, high);

	    print(arr, 5);

        quickSort(arr, low, pi - 1);//sort left sub-array


        quickSort(arr, pi + 1, high);//sort right sub-array
    }
}

int main() 
{
    int a[7] = {59, 77, 32, -50, 100};
    int n = 5;

    print(a, n);
    quickSort(a, 0, n - 1);
    print(a, n);
    

    return 0;
}
