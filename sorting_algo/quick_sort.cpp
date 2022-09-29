
#include <iostream>
using namespace std;
void swapped(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partion(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low + 1; // find the element index greater then pivot
    int j = high;    // find the element index smaller then pivot
    do
    {
        while (arr[i] < pivot)
        {
            i++;
        }
        while (arr[j] > pivot)
        {
            j--;
        }

        // if element is find swapp i and j elements
        if (i < j)
        {
            swapped(&arr[j], &arr[i]);
        }

    } while (i < j);

    // set the pivot element to its right position
    swapped(&arr[low], &arr[j]);
    return j;

    // ** or

    // int pivot = arr[high]; // pivot
    // int i = (low - 1);     // Index of smaller element and indicates
    //                        /* the right position of pivot found so far*/

    // for (int j = low; j <= high - 1; j++)
    // {
    //     /* If current element is smaller than the pivot*/
    //     if (arr[j] < pivot)
    //     {
    //         i++; // increment index of smaller element
    //         swapped(&arr[i], &arr[j]);
    //     }
    // }
    // swapped(&arr[i + 1], &arr[high]);
    // return (i + 1);
}
void quick_sort(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int partion_index = partion(arr, low, high);
    quick_sort(arr, low, partion_index - 1);
    quick_sort(arr, partion_index + 1, high);
}
int main()
{
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int size = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, size - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}