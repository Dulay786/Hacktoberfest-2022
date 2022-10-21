#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubblesort();
int arr[100];
int n;

void main()
{
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the sequence: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    bubblesort();
}

void bubblesort()
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        printf("Pass %d\n", i + 1);
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                int k;
                for (k = 0; k < n; k++)
                {
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }
    }
    int k;
    printf("Sorted sequence: \n");
    for (k = 0; k < n; k++)
    {
        printf("%d ", arr[k]);
    }
}
