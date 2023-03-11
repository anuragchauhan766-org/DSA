
#include <iostream>
using namespace std;
#define size 10

// creating stack class
class stack
{
    int *arr;
    int top;

public:
    stack()
    {
        top = -1;
        arr = new int[size];
    }
    void push(int);
    void pop();
    int top_val();
    bool empty();
};

// push fucntion
void stack::push(int data)
{
    if (top == size - 1)
    {
        cout << "stack overflow !!! \n";
        return;
    }

    arr[++top] = data;
}
void stack::pop()
{
    if (top == -1)
    {
        cout << "stack empty \n";
        return;
    }
    top--;
}
int stack::top_val()
{
    if (top == -1)
    {
        cout << "stack empty!! \n";
    }

    return arr[top];
}
bool stack::empty()
{
    return (top == -1);
}
int main()
{
    stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s1.push(6);
    s1.push(7);
    s1.push(8);
    s1.push(9);
    s1.push(10);
    // s1.push(11);
    cout << s1.top_val();
    s1.pop();
    cout << s1.top_val();
    cout << s1.empty();
    return 0;
}