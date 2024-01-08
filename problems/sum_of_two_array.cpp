#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<int> sumoftwo(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size();
    int n = nums2.size();
    int i = m - 1, j = n - 1;
    int carry = 0;
    int size = max(m, n);
    int k = size - 1;
    vector<int> ans(size);
    while (i >= 0 && j >= 0)
    {
        int sum = carry + nums1[i] + nums2[j];
        carry = sum / 10;
        ans[k--] = sum % 10;
        i--;
        j--;
    }
    while (i >= 0)
    {
        int sum = carry + nums1[i];
        carry = sum / 10;
        ans[k--] = sum % 10;
        i--;
    }
    while (j >= 0)
    {
        int sum = carry + nums1[j];
        carry = sum / 10;
        ans[k--] = sum % 10;
        j--;
    }
    return ans;
}

int main()
{
    vector<int> num1{1, 2, 3};
    vector<int> num2{9, 9};
    vector<int> ans;
    ans = sumoftwo(num1, num2);
    for (auto &i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}