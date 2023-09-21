#include<stdio.h>
int main()
{
    int i, n, constraint, count = 0;
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    int a[n];
    float profit[n], weight[n], Profit_by_Weight[n];
    for(i=0; i<n; i++)
    {
        printf("\nEnter weight of object %d: ", i+1);
        scanf("%f", &weight[i]);
        printf("Enter profit margin of object %d: ", i+1);
        scanf("%f", &profit[i]);
        printf("\n");
        Profit_by_Weight[i] = (float)profit[i]/weight[i];
        printf("\n%.2f", Profit_by_Weight);
    }
    printf("\n");
    for (int i = 0; i < n - 1; i++) 
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (Profit_by_Weight[j] > Profit_by_Weight[maxIndex]) 
            {
              maxIndex = j;
            }
        }
        if (maxIndex != i) 
        {
          count++;
          int temp = Profit_by_Weight[i];
          int temp2 = weight[i];
          Profit_by_Weight[i] = Profit_by_Weight[maxIndex];
          weight[i] = weight[maxIndex];
          Profit_by_Weight[maxIndex] = temp;
          weight[maxIndex] = temp2;
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%.2f ", Profit_by_Weight[i]);
    }
    printf("\n");
    for(i=0; i<n; i++)
    {
        printf("%.2f ", weight);
    }
    return 0;
}