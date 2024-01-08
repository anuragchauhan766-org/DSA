#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int power(int x, int y, int m)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
        {
             res = (res * x) % m;
        }
        y = y >> 1;
        x = (x * x) % m;
    }
    return res;
}
int main()
{
    cout << power(11, 23, 187);
    return 0;
}