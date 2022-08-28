#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// TODO: try to create a templete of linked list and able to get data from user of a node
// node implementation using class
// it represent  a node in list

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
};

void linked_list::insertnode(int data)
{

    // creating a new node a allocating memory to it
    node *newnode = new node(data);

    // checking if head is empty or linked list is empty
    if (head == NULL)
    {
        head = newnode;
        return;
    }

    // if list is not empty then creating and tansvering to the end of list

    // creating a temp pointer to get to end of list
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

void linked_list::delete_node(int node_no)
{
    // decalring two pointer to the node
    node *temp1 = head, *temp2 = NULL;

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

    // checking if node to be deleted is head
    temp1 = head;
    if (node_no == 1)
    {
        head = head->next;
        delete temp1;
        return;
    }

    // finding the node to be deleted
    while (node_no-- > 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    delete temp1;
}

// function to print list

void linked_list::printlist()
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\n";
        temp = temp->next;
    }
}

// main fuction
int main()
{

    linked_list node1;
    node1.insertnode(1);
    node1.insertnode(2);
    node1.insertnode(3);
    node1.insertnode(4);
    node1.printlist();
    cout << "\n";
    node1.delete_node(-1);
    node1.printlist();

    return 0;
}