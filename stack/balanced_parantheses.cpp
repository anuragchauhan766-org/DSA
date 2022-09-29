#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

// fucntion to check balanced parantheses

bool isbalance(string s)
{

    stack<char> s1;
    for (int i = 0; i < s.length(); i++)
    {

        if (s.at(i) == '(' or s[i] == '[' or s[i] == '{')
        {
            s1.push(s[i]);
        }
        else
        {
            if (s[i] == ')')
            {
                if (s1.empty() || s1.top() != '(')
                {
                    return false;
                }
                else
                {
                    s1.pop();
                }
            }
            else if (s[i] == ']')
            {
                if (s1.empty() || s1.top() != '[')
                {
                    return false;
                }
                else
                {
                    s1.pop();
                }
            }
            else if (s[i] == '}')
            {
                if (s1.empty() || s1.top() != '{')
                {
                    return false;
                }
                else
                {
                    s1.pop();
                }
            }
        }
    }
    if (s1.empty())
    {
        return true;
    }
    return false;
}
int main()
{
    string exp;
    cout << "enter the expression \n";
    getline(cin, exp);
    if (isbalance(exp))
    {
        cout << " balanced expression \n";
    }
    else
    {
        cout << "not balanced expression \n";
    }

    return 0;
}