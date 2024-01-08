#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// simple and O(n) method
int unique(vector<int> &nums)
{
    int result = 0;
    for (auto i : nums)
    {
        result = result ^ i;
    }
    return result;
}

// binary search method O(logn)
int uniqueb(vector<int> &nums)
{
    int s = 0, e = nums.size() - 1, mid;
    while (s < e)
    {
        mid = s + (e - s) / 2;

        if (!(mid & 1))
        {
            if (nums[mid] == nums[mid + 1])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }
        else
        {
            if (nums[mid] == nums[mid + 1])
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
    }
    return nums[s];
}
int main()
{
    vector<int> nums{1, 1, 2, 3, 3, 4, 4, 8, 8};
    // cout << unique(nums) << endl;
    cout << uniqueb(nums) << endl;
    return 0;
}