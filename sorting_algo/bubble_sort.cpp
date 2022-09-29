
#include <iostream>
using namespace std;

// swapping fuction

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort function ]

void bubble_sort(int arr[], int size)
{

    bool swapped;
    for (int pass = 0; pass < size - 1; pass++)
    {
        swapped = false;
        for (int i = 0; i < size - pass - 1; i++)
        {

            if (arr[i] > arr[i + 1])
            {
                swapped = true;
                swap(&arr[i], &arr[i + 1]);
            }
        }

        // if no element is swapped by inner loop i then break
        if (swapped == false)
        {
            break;
        }
    }
}
int main()
{
    int arr[] = {6, 4, 27, 8, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, size);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}