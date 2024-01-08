#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    string s = "hello who &* are";
    int m = s.length();
    reverse(s.begin() + 1, s.end());
    cout << s;
    return 0;
}