#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionsort();
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
    insertionsort();
}

void insertionsort()
{
    for (int i = 1; i < n; i++)
    {
        printf("Pass %d\n", i);
        int j = i;
        int x = arr[i];
        while (arr[j - 1] > x && j != 0)
        {
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = x;

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
