#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    while (a != b)
    {
        if (a > b)
        {
            a = a - b; // euclid theorem
        }
        else
        {
            b = b - a; // euclid theorem
        }
    }
    return a;
}
int gcd_d(int a, int b)
{
    // iterative
    // if (a == 0)
    // {
    //     return b;
    // }
    // if (b == 0)
    // {
    //     return a;
    // }

    // while (b)
    // {
    //     int temp = b;
    //     b = a % b;
    //     a = temp;
    // }
    // return a;

    // recurcive
    if (b == 0)
    {
        return a;
    }

    return gcd_d(b, a % b);
}
int main()
{
    cout << gcd_d(0, 4);
    return 0;
}