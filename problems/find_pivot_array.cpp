#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int getPivot(int arr[], int size)
{
    int s = 0, e = size - 1, mid;
    while (s < e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}
int main()
{
    int arr[] = {3, 4, 5, 1, 2};
    int ans = getPivot(arr, 5);
    cout << ans << endl;
    return 0;
}