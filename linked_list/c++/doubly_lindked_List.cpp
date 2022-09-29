#include <bits/stdc++.h>
#include <iostream>
using namespace std;
// node class
class node
{
public:
    int data;
    node *previous;
    node *next;
    node()
    {
        data = 0;
        previous = NULL;
        next = NULL;
    }
    node(int data)
    {
        this->data = data;
        previous = NULL;
        next = NULL;
    }
};

// doubly linked list class
class doubly_list
{

public:
    node *head;
    doubly_list()
    {
        head = NULL;
    }
    void insertnode(int);
    void printlist();
    void delete_node(int);
    void insertnode(int, int);
};

// inserting at the end of list

void doubly_list::insertnode(int data)
{
    node *new_node = new node(data);
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;

    new_node->previous = temp;
}

// inserting at a positon in a list

void doubly_list::insertnode(int data, int node_no)
{
    node *new_node = new node(data);
    node *temp1 = head;

    if (node_no <= 0)
    {
        cout << "incorrect index !! \n";
        return;
    }

    // getting the length of a list
    int list_length = 0;
    while (temp1 != NULL)

    {
        temp1 = temp1->next;
        list_length++;
    }

    // checking if list to be inserted are in range of list length or out of bound
    if (list_length + 1 < node_no)
    {
        cout << "Indez out of range \n";
        return;
    }
    if (node_no == 1)
    {
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        new_node->next = head;
        head->previous = new_node;
        head = new_node;
        return;
    }
    if (list_length == node_no - 1)
    {
        insertnode(data);
        return;
    }
    temp1 = head;
    while (node_no-- > 1)
    {
        temp1 = temp1->next;
    }
    new_node->previous = temp1->previous;
    temp1->previous = new_node;
    new_node->previous->next = new_node;
    new_node->next = temp1;
}

// deletion
void doubly_list::delete_node(int node_no)
{
    node *temp1 = head;

    // checking if node exist
    if (head == NULL)
    {
        cout << "list does not exist!!! \n";
        return;
    }

    if (node_no <= 0)
    {
        cout << "incorrect index !! \n";
        return;
    }

    // getting the length of a list
    int list_length = 0;
    while (temp1 != NULL)

    {
        temp1 = temp1->next;
        list_length++;
    }

    // checking if list to be deleted are in range of list length or out of bound
    if (list_length < node_no)
    {
        cout << "Indez out of range \n";
        return;
    }

    // if node to be delelted is head
    temp1 = head;
    if (node_no == 1)
    {
        head = head->next;
        head->previous = NULL;
        delete temp1;
        return;
    }
    while (node_no-- > 1)
    {
        temp1 = temp1->next;
    }
    temp1->previous->next = temp1->next;

    if (temp1->next != NULL)
    {
        temp1->next->previous = temp1->previous;
    }

    delete temp1;
}
// printing list

void doubly_list::printlist()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}
int main()
{
    doubly_list node1;
    node1.insertnode(1);
    node1.insertnode(2);
    node1.insertnode(3);
    node1.insertnode(4);
    node1.insertnode(5);
    node1.printlist();
    cout << endl;
    node1.delete_node(5);
    // node1.insertnode(6, 6);
    node1.printlist();
    return 0;
}