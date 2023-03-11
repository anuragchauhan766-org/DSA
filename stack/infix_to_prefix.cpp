#include <bits/stdc++.h>

using namespace std;
int isoperand(char op)
{
    if ((op >= 'a' && op <= 'z') || (op >= 'A' && op <= 'Z') || (op >= '1' && op <= '9'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int prec(char op)
{
    if (op == '/' || op == '*')
    {
        return 3;
    }
    else if (op == '+' || op == '-')
    {
        return 2;
    }
    else
    {
        return -1;
    }
}

// function to convert infix to postfix

string infix_to_postfix(string infix)
{
    stack<char> s1;
    string postfix;

    // iterate through whole string
    for (unsigned int i = 0; i < infix.length(); i++)
    {

        // if char is not operator
        if (isoperand(infix[i]))
        {
            postfix += infix[i];
        }

        // if char is opening bracket
        else if (infix[i] == '(')
        {
            s1.push(infix[i]);
        }

        // if char is closing bracket
        else if (infix[i] == ')')
        {
            while (s1.top() != '(')
            {
                postfix += s1.top();
                s1.pop();
            }
            s1.pop();
        }

        // if char is operator
        else
        {
            while (!s1.empty() && (prec(infix[i]) <= prec(s1.top())))
            {
                postfix += s1.top();
                s1.pop();
            }
            s1.push(infix[i]);
        }
    }

    // empty the whole stack
    while (!s1.empty())
    {
        postfix += s1.top();
        s1.pop();
    }
    return postfix;
}
// fuction to convert infix to prefix
string infix_to_prefix(string s)
{
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }
    string prefix = infix_to_postfix(s);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}
int main()
{
    string infix;

    cout << "enter a expression to covert into postfix !! \n";
    getline(cin, infix);

    cout << infix_to_postfix(infix) << endl;
    cout << infix_to_prefix(infix);

    return 0;
}
