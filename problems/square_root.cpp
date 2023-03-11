#include <bits/stdc++.h>
#include <iostream>
using namespace std;
double mySqrt(int x, int precision)
{
    int s = 0, e = x;
    long long int mid;
    double ans;
    bool perfectsq = false;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (mid * mid > x)
        {
            e = mid - 1;
        }
        else if (mid * mid < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (mid * mid == x)
        {
            perfectsq = true;
            return mid;
        }
    }
    if (!perfectsq)
    {
        double factor = 1.0;
        for (int i = 0; i < precision; i++)
        {
            factor = factor / 10;
            while (ans * ans < x)
            {
                ans += factor;
            }
            ans = ans - factor;
        }
    }

    return ans;
}
int main()
{
    cout << mySqrt(45, 3);
    // double x = 1.00 / 10000;
    // cout << x;

    return 0;
}