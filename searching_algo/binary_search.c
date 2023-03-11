#include <stdio.h>
#include <stdlib.h>
// entering element in the array
void inputelement(int *arr, int size)
{
    printf("Enter element of array in ascending order:\n");

    for (int i = 0; i < size; i++)
    {
        printf("Enter %d element :", i + 1);
        scanf("%d", &arr[i]);
    }
}
// for displaying
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
// binary search algorithm
int binarysearch(int *arr, int size, int search, int min, int max)
{
    // int mid = (min + max) / 2;
    int mid = min + ((max - min) / 2);
    // will search until min and max converges
    if (max >= min)
    {

        if (arr[mid] == search)
        {
            return mid;
        }
        else if (arr[mid] < search)
        {
            return binarysearch(arr, size, search, mid + 1, max);
        }
        else
        {
            return binarysearch(arr, size, search, min, mid - 1);
        }
    }

    else
    {
        return -1;
    }
}
int main()
{
    int *p, size, search, result;
    printf("Enter the size of array:\n");
    scanf("%d", &size);
    // memory allocation
    p = (int *)malloc(size * sizeof(int));
    if (p == NULL)
    {
        printf("memmory can't be allocated\n");
    }
    else
    {
        printf("memory allocated successfully\n");
    }
    inputelement(p, size);
    display(p, size);
    printf("Enter element to be searched: \n");
    scanf("%d", &search);

    result = binarysearch(p, size, search, 0, size - 1);
    if (result == -1)
    {
        printf("Element not found !!!\n");
    }
    else
    {
        printf("Element found at %d index\n", result);
    }
    free(p);
    return 0;
}