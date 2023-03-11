
#include <iostream>
using namespace std;

// creating a node
class node
{

public:
    int data;
    node *next;
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

// queue class
class queue
{
    node *front;
    node *rear;
    int s = 0;

public:
    queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int);
    void dequeue();
    bool empty();
    void display();
    int size();
};

void queue::enqueue(int data)
{
    node *new_node = new node(data);
    if (new_node == NULL)
    {
        cout << "queue is full !!";
        return;
    }
    else
    {
        if (empty())
        {
            front = rear = new_node;
            s++;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
            s++;
        }
    }
}

void queue::dequeue()
{
    if (empty())
    {
        cout << "queue is empty!!";
    }
    else
    {
        node *ptr = front;
        front = front->next;
        delete ptr;
        s--;
    }
}

bool queue::empty()
{
    return front == NULL;
}
int queue::size()
{
    return s;
}
void queue::display()
{
    if (front == NULL)
    {
        cout << "queue is empty !! \n";
        return;
    }

    node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.display();

    cout << q1.size();

    return 0;
}