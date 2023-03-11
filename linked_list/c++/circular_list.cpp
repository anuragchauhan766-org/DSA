#include <bits/stdc++.h>
#include <iostream>
using namespace std;

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
        this->next = NULL;
    }
};
class linked_list
{

public:
    node *head;
    linked_list()
    {
        head = NULL;
    }
    void insertnode(int);
    void printlist();
    void delete_node(int);
    void insertnode(int, int);

    // todo: to be implimented
    int search(int);
    void reverse();
};
void linked_list::insertnode(int data)
{
    node *new_node = new node(data);

    // checking if list is empty
    if (head == NULL)
    {
        head = new_node;
        new_node->next = new_node;
        return;
    }

    // creating a poitner to get to end of list
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
}

// insert list at any where
void linked_list::insertnode(int data, int node_no)
{
    node *new_node = new node(data);

    // if list is empty
    if (head == NULL)
    {
        new_node->next = new_node;
        head = new_node;
    }

    // to insert at head
    node *temp = head;
    if (node_no == 1)
    {
        while (temp->next != head)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
        head = new_node;
        return;
    }

    // getting length of the list
    int list_length = 0;
    do
    {
        temp = temp->next;
        list_length++;
    } while (temp != head);

    // checking if node_no is correct

    if (list_length + 1 < node_no)
    {
        cout << "index out of range!! \n";
        return;
    }
    temp = head;
    for (int i = 1; i < node_no - 1; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}

// for displaying
void linked_list::printlist()
{
    node *temp = head;
    do
    {
        cout << temp->data << "\n";
        temp = temp->next;

    } while (temp != head);
}

// for deleting a node

void linked_list::delete_node(int node_no)
{
    // if list is empty
    if (head == NULL)
    {
        cout << "list is empty \n";
        return;
    }

    // if list contain only one node
    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }
    //
    node *temp1 = head, *temp2 = head;
    if (node_no == 1)
    {
        while (temp2->next != head)
        {
            temp2 = temp2->next;
        }
        temp2->next = head->next;
        head = head->next;
        delete temp1;
        return;
    }
    // getting list length
    int list_length = 0;
    do
    {
        temp1 = temp1->next;
        list_length++;
    } while (temp1 != head);

    // checking if list to be deleted are in range of list length or out of bound
    if (list_length < node_no)
    {
        cout << "Indez out of range \n";
        return;
    }
    temp1 = head;
    while (node_no-- > 1)
    {
        temp1 = temp2;
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    delete temp2;
}
int main()
{
    linked_list node1;
    node1.insertnode(1);
    node1.insertnode(2);
    node1.insertnode(3);
    node1.insertnode(4);
    node1.insertnode(5);
    node1.printlist();
    cout << endl;
    node1.insertnode(6, 6);
    // node1.delete_node(1);
    node1.printlist();

    return 0;
}