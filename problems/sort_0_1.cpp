#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void sort1(int arr[], int size)
{
    int i = 0, j = size - 1;

    while (i < j)
    {
        while (!arr[i] && i < j)
        {
            i++;
        }
        while (arr[j] && i < j)
        {
            j--;
        }
        if (arr[i] && !arr[j])
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
}
int main()
{
    int arr[] = {0, 0, 1, 0, 0, 1, 0, 1};

    sort1(arr, 8);

    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
