#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{

    int x = 2 ^ 3 ^ 2^4^7;
    int y = (~x) ^ 3;
    cout << y<<x;
    return 0;
}