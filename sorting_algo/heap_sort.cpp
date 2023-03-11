
#include <iostream>
using namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;  // left child
    int right = 2 * i + 2; // right child

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heap_sort(int arr[], int n)
{
    // heapify the array
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[i], &arr[0]);
        heapify(arr, i, 0);
    }
}
int main()
{
    int arr[] = {100, 0, 100, 29, 90, 23, 3, 60};
    int size = sizeof(arr) / sizeof(arr[0]);
    heap_sort(arr, size);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}