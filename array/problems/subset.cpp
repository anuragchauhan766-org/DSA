#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<vector<int>> subsets(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> ans;
    int sub_size = pow(2, n);
    for (int i = 0; i < sub_size; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }
    return ans;
}
void solve(vector<int> &nums, vector<int> &temp, int n, vector<vector<int>> &ans)
{
    // base case
    if (n >= nums.size())
    {
        ans.push_back(temp);
        return;
    }

    // exclude
    solve(nums, temp, n + 1, ans);

    // include
    int element = nums[n];
    temp.push_back(element);

    solve(nums, temp, n + 1, ans);
}
vector<vector<int>> subsets_rec(vector<int> &nums)
{

    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> temp;
    int index = 0;
    solve(nums, temp, index, ans);
    return ans;
}
int main()
{
    vector<int> v{1, 2, 3};
    vector<vector<int>> ans = subsets_rec(v);
    for (auto &i : ans)
    {
        cout << " { ";
        for (auto &j : i)
        {
            cout << j << " , ";
        }
        cout << " } ";
    }
    return 0;
}