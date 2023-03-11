#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int firstOccurance(vector<int> &nums, int target)
{
    int s = 0, e = nums.size() - 1, mid;

    int ans = -1;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
int lastOccurance(vector<int> &nums, int target)
{
    int s = 0, e = nums.size() - 1, mid;
    int ans = -1;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (nums[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (nums[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}
vector<int> searchRange(vector<int> &nums, int target)
{
    int first = firstOccurance(nums, target);
    int last = lastOccurance(nums, target);
    vector<int> ans;
    ans.push_back(first);
    ans.push_back(last);
    return ans;
}
int main()
{
    std::vector<int> arr{};
    vector<int> ans = searchRange(arr, 0);
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}