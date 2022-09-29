
#include <iostream>
using namespace std;

// creating node for stack
class node
{
    int data;
    node *next;
    friend class stack;

public:
    node()
    {
        data = 0;
        next = NULL;
    }
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

// stack class
class stack
{
    node *top;

public:
    stack()
    {
        top = NULL;
    }

    void push(int);
    void pop();
    bool is_empty();
    int top_val();
};

// push
void stack::push(int data)
{
    node *new_node = new node(data);
    if (!new_node)
    {
        cout << "stack overflow !!\n";
        return;
    }
    new_node->next = top;
    top = new_node;
}

// is empty fucntion
bool stack::is_empty()
{
    return (top == NULL);
}

void stack::pop()
{
    if (is_empty())
    {
        cout << "stack is empty\n";
        return;
    }
    node *temp = top;

    top = top->next;
    delete temp;
}

int stack::top_val()
{
    if (is_empty())
    {
        cout << "stack is empty\n";
        return -1;
    }

    return top->data;
}
int main()
{
    stack s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    cout << s1.top_val();
    s1.pop();
    cout << s1.top_val();
    return 0;
}