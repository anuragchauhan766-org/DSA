
#include <iostream>
using namespace std;

// swapping fuction

void swap(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}

// bubble sort function ]

void bubble_sort(int arr[], int size)
{

    if (size == 0 || size == 1)
    {
        return;
    }

    for (int i = 0; i < size - 1; i++)
    {

        if (arr[i] > arr[i + 1])
        {

            swap(arr[i], arr[i + 1]);
        }
    }
    bubble_sort(arr, size - 1);
}
int main()
{
    int arr[] = {100, 12, 100, 1, 1, 12, 100, 1, 12, 100, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, size);
    // for (auto i : arr)
    // {
    //     cout << i << " ";
    // }

    return 0;
}