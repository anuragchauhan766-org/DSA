#include <bits/stdc++.h>
#include <iostream>
using namespace std;
string reverseWords(string s)
{
    int m = s.length();
    string temp;
    int start, end;
    for (int i = 0; i < m; i++)
    {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
        {
            start = i;
        }
        else if (s[i] != ' ' && (i == m - 1 || s[i + 1] == ' '))
        {

            end = i + 1;
            reverse(s.begin() + start, s.begin() + end);

            i++;
        }
        else if (s[i] == ' ' && (i == 0 || s[i - 1] == ' '))
        {
            s.erase(s.begin() + i);
            i--;
            m--;
        }
    }
    if (s.back() == ' ')
    {
        s.pop_back();
    }

    return s;
}
int main()
{
    string s = "a good   example";
    // getline(cin, s);
    cout << "'" << reverseWords(s) << "'" << endl;
    return 0;
}