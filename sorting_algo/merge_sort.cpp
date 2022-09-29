
#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int sorting_arr[high + 1];
    int i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            sorting_arr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            sorting_arr[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        sorting_arr[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        sorting_arr[k] = arr[j];
        j++;
        k++;
    }
    for (int a = low; a <= high; a++)
    {
        arr[a] = sorting_arr[a];
    }
}
void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    merge_sort(arr, 0, size - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}