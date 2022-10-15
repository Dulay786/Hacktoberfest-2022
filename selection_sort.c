#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionsort();
int arr[100];
int n;

void main()
{
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the sequence: ");
    for (int a = 0; a < n; a++)
    {
        scanf("%d", &arr[a]);
    }
    selectionsort();
}

void selectionsort()
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        printf("Pass %d\n", i + 1);
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        int k;
        for (k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    int k;
    printf("Sorted sequence: \n");
    for (k = 0; k < n; k++)
    {
        printf("%d ", arr[k]);
    }
}
