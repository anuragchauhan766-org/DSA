
#include <iostream>
#define max 5
using namespace std;
class Dequeue
{
public:
    int *arr;
    int f, r, s;
    Dequeue()
    {
        arr = new int[max];
        f = -1;
        r = -1;
        s = 0;
    }
    bool isFull();
    bool isEmpty();
    void insertFront(int data);
    void insertRear(int data);
    void DeleteFront();
    void DeleteRear();
    void display();
    int getFront();
    int getRear();
};

bool Dequeue::isFull()
{
    return (f == 0 && r == max - 1) || (f == r + 1);
}
bool Dequeue::isEmpty()
{
    return f == -1 && r == -1;
}
void Dequeue::insertFront(int data)
{
    if (isFull())
    {
        cout << "Queue is overflowed !!!";
        return;
    }
    if (f == -1)
    {
        f = 0;
        r = 0;
    }
    else
    {
        f = (f + max - 1) % max;
    }
    s++;
    arr[f] = data;
}
void Dequeue::insertRear(int data)
{
    if (isFull())
    {
        cout << "Queue is overflowed !!!";
        return;
    }
    if (r == -1)
    {
        f = 0;
        r = 0;
    }
    else
    {
        r = (r + 1) % max;
    }
    s++;
    arr[r] = data;
}
void Dequeue::DeleteFront()
{
    if (isEmpty())
    {
        cout << "Queue is Empty !!";
        return;
    }
    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        f = (f + 1) % max;
    }
    s--;
}
void Dequeue::DeleteRear()
{
    if (isEmpty())
    {
        cout << "Queue is Empty !!";
        return;
    }
    if (f == r)
    {
        f = -1;
        r = -1;
    }
    else
    {
        r = (r + max - 1) % max;
    }
    s--;
}
void Dequeue::display()
{
    if (isEmpty())
    {
        cout << "Queue is Empty !!";
        return;
    }
    for (int i = f; i != r; i = (i +  1)% max)
    {
        cout << arr[i] << " ";
    }
    cout << arr[r];
}
int Dequeue::getFront()
{
    if (isEmpty())
    {
        cout << "Queue is Empty !!";
        return -1;
    }

    return arr[f];
}
int Dequeue::getRear()
{
    if (isEmpty())
    {
        cout << "Queue is Empty !!";
        return -1;
    }

    return arr[r];
}

int main()
{
    Dequeue q;
    q.insertRear(1);
    q.insertRear(2);
    q.insertRear(3);
    q.insertRear(4);
    q.insertRear(5);
    // cout << q.getFront();
    // cout << q.getRear();
    q.display();
    q.DeleteFront();
    q.DeleteFront();
    q.DeleteFront();
    q.DeleteRear();
    cout << endl;
    q.display();
    cout << endl;
    q.insertFront(6);
    q.insertFront(7);
    q.insertFront(8);
    q.insertFront(9);
    cout << q.s;
    // q.insertFront(10);
    q.display();

    return 0;
}