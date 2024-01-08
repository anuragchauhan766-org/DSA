#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int compress(vector<char> &chars)
{
    string s;
    int m = chars.size();
    if (m == 1)
        return 1;
    int i = 0, j = 0;
    int group_size;
    while (i < m)
    {

        if (chars[i] == chars[i + 1])
        {
            i++;
        }
        else
        {
            group_size = i - j + 1;
            s.push_back(chars[i]);
            if (group_size != 1)
            {
                string s1 = to_string(group_size);
                s += s1;
            }
            i++;
            j = i;
        }
    }
    for (int k = 0; k < s.length(); k++)
    {
        chars[k] = s[k];
    }
    return s.length();
}
int main()
{
    vector<char> c{'a', 'a'};

    int size = compress(c);
    for (int i = 0; i < size; i++)
    {
        cout << c[i];
    }
    cout << endl;
    return 0;
}