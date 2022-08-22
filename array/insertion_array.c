#include <stdio.h>
// TRAVERSAL CODE
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// INSERTION CODE
int sinsertion(int arr[], int size, int capacity, int element, int index)
{
    if (size >= capacity)
    {
        return -1;
    }

    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    return 1;
}
// MAIN FUCTION
int main()
{
    int arr[100] = {4, 6, 7, 9, 12};
    int size = 5, element = 10, index = 1, sus;
    display(arr, size);
    sus = sinsertion(arr, size, 100, element, index);
    if (sus == -1)
    {
        printf("Insertion Unsuccessfull!!\n");
    }
    else
    {
        size += 1;
        printf("insertion successfull !! \n new array is \n");
        display(arr, size);
    }

    return 0;
}