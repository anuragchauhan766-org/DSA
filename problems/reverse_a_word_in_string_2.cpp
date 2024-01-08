#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string reverseWords(string s)
{
    int i = 0, j = 0, l = 0;
    int len = s.length();
    int words = 0;
    while (1)
    {
        while (i < len && s[i] == ' ')
            i++;
        if (i >= len)
            break;
        if (words)
            s[j++] = ' ';
        l = j;
        while (i < len && s[i] != ' ')
        {
            s[j] = s[i];
            i++;
            j++;
        }
        reverse(s.begin() + l, s.begin() + j);
        words++;
    }
    s.resize(j);
    reverse(s.begin(), s.end());
    return s;
}
int main()
{
    string s = "the sky is blue";
    cout << "'" << reverseWords(s) << "'" << endl;
    return 0;
}