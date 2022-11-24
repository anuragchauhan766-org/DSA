
#include <iostream>
using namespace std;

#define n 5
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
    void printqueue();
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
        r = (r + 1) % n;
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
        f = (f + 1) % n;
        s--;
        return item;
    }
}

bool queue::empty()
{
    return s == 0;
}
bool queue::full()
{
    return s == n;
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

void queue::printqueue()
{
    if (s == 0)
    {
        cout << "queue is empty";
        return;
    }

    if (r >= f)
    {
        for (int i = f; i <= r; i++)
            printf("%d ", arr[i]);
    }
    else
    {
        int i;
        for (i = f; i != r; i = (i + 1) % s)
        {
            cout << arr[i] << " ";
        }
        cout << arr[i];

        // or

        // for (int i = f; i < n; i++)
        //     printf("%d ", arr[i]);

        // for (int i = 0; i <= r; i++)
        //     printf("%d ", arr[i]);
    }
}

int main()
{
    queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.printqueue();
    cout << endl;
    cout << q1.size() << endl;

    // cout << q1.full() << endl;
    // cout << q1.empty() << endl;

    return 0;
}