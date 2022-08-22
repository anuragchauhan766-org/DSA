#include <stdio.h>
#include <stdlib.h>
// entering element in the array
void inputelement(int *arr, int size)
{
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
// linearsearch function
int linearsearch(int *arr, int size, int search)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == search)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int *p, size, search, result;
    printf("Enter the size of array: \n");
    scanf("%d", &size);
    // allocating memory
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
    printf("\nenter a element to be searched:");
    scanf("%d", &search);

    result = linearsearch(p, size, search);
    if (result == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element is found at %d index", result);
    }

    free(p);
    return 0;
}