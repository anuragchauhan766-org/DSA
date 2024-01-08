#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
    if (index == nums.size() - 1)
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, ans, index + 1);
        swap(nums[index], nums[i]);
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    return ans;
}

int main()
{
    vector<int> a{1, 2, 3};
    vector<vector<int>> ans = permute(a);
    for (auto &i : ans)
    {

        for (auto j : i)
            cout << j << " ,";
        cout << endl;
    }

    return 0;
}