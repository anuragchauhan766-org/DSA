
#include <iostream>
using namespace std;

#define n 20
// queue class for implimenting

class queue
{
    int *arr;
    int f;
    int r;
    int s;

public:
    queue()
    {
        arr = new int[n];
        f = r = -1;
        s = 0; // size
    }

    void enqueue(int);
    int dequeue();
    int front();
    int rear();
    bool empty();
    int size();
    bool full();
};

// insertion at the end of queue
void queue::enqueue(int data)
{
    if (full())
    {
        cout << "overflow !!\n";
        return;
    }
    else
    {
        r++;
        arr[r] = data;
        s++;
        if (f == -1)
        {
            f++;
        }
    }
}

// deletion at front of queue

int queue::dequeue()
{
    if (empty())
    {
        cout << "underflow !!";
        return -1;
    }
    else
    {
        int item = arr[f];
        f++;
        s--;
        return item;
    }
}

bool queue::empty()
{
    return (f == -1 || f > r);
}
bool queue::full()
{
    return (r == n - 1);
}
int queue::front()
{

    return arr[f];
}
int queue::rear()
{
    return arr[r];
}
int queue::size()
{
    return s;
}
int main()
{
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    cout << q1.dequeue() << endl;

    cout << q1.dequeue() << endl;

    cout << q1.dequeue() << endl;

    cout << q1.dequeue() << endl;
    cout << q1.front();

    return 0;
}