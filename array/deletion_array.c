#include <stdio.h>
// FOR TRAVERSAL
void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// for deletion
void deletion(int arr[], int size, int index)
{

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
}
int main()
{
    int arr[100] = {2, 3, 5, 1, 6}, size = 5;
    display(arr, size);
    deletion(arr, size, 2);
    size -= 1;
    display(arr, size);

    return 0;
}