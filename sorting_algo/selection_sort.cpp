
#include <iostream>
using namespace std;
void swapped(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int arr[], int size)
{
    for (int pass = 0; pass < size - 1; pass++)
    {
        int min_index = pass;
        for (int j = pass + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        // not stable version
        // swapped(&arr[min_index], &arr[pass]);

        // or stable version
        int key = arr[min_index];
        while (min_index > pass)
        {
            arr[min_index] = arr[min_index - 1];
            min_index--;
        }
        arr[pass] = key;
    }
}
int main()
{
    int arr[] = {12, 5, 16, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr, size);
    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}