#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int findelement(int arr[], int size, int target)
{
    int s = 0, e = size - 1, mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (arr[mid] == target)
            return mid;

        if (arr[mid] >= arr[s])
        {
            if (arr[mid] >= target && target >= arr[s])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= target && target <= arr[e])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    int arr[] = {7, 9, 10, 2, 3};
    int ans = findelement(arr, 5, 3);
    cout << ans << endl;
    return 0;
}