
#include <iostream>
#include <string>

using namespace std;

// creating node for stack
template <class u>
class node
{

public:
    u data;
    node<u> *next;

    node()
    {
        data = 0;
        next = NULL;
    }
    node(u data)
    {
        this->data = data;
        next = NULL;
    }
};

// stack class
template <class u>
class stack
{
    node<u> *top;

public:
    stack()
    {
        top = NULL;
    }

    void push(u);
    void pop();
    bool is_empty();
    u top_val();
};

// push
template <class u>
void stack<u>::push(u data)
{
    node<u> *new_node = new node(data);
    if (!new_node)
    {
        exit(1);
    }
    new_node->next = top;
    top = new_node;
}

// is empty fucntion
template <class u>
bool stack<u>::is_empty()
{
    return (top == NULL);
}

template <class u>
void stack<u>::pop()
{
    if (is_empty())
    {

        return;
    }
    node<u> *temp = top;

    top = top->next;
    delete temp;
}

template <class u>
u stack<u>::top_val()
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

    stack<char> s1;
    s1.push('h');
    s1.push('g');
    s1.push('d');
    cout << s1.top_val();
    s1.pop();
    cout << s1.top_val();
    cout << s1.is_empty();
    return 0;
}