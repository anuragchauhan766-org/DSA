#include <stdio.h>
#include <stdlib.h>

// structure for linked list
struct node
{
    int data;
    struct node *next;
};

// traversal fuction
void traversal(struct node *ptr)
{
    int i = 1;
    while (ptr != NULL)
    {
        printf("element %d = %d\n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

// function to insetert a begeining of node
struct node *frontinsert(struct node *ptr)
{
    struct node *five;
    five = (struct node *)malloc(sizeof(struct node));
    // joining five to head
    five->data = 5;
    five->next = ptr;

    return five;
}

// insterting after a node
void insertafter(struct node *ptr, int node)
{

    struct node *five;
    five = (struct node *)malloc(sizeof(struct node));
    // joining five to head
    for (int i = 1; i < node; i++)
    {
        ptr = ptr->next;
    }
    five->data = 5;
    five->next = ptr->next;
    ptr->next = five;
}

// inserting at end of list
void insertend(struct node *ptr)
{

    struct node *five;
    five = (struct node *)malloc(sizeof(struct node));
    // joining five to head
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    five->data = 5;
    ptr->next = five;
    five->next = NULL;
}

// main fuction starts
int main()
{
    struct node *head, *second, *third, *fourth;

    // allocating memory to NODES
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    // jointing and assigning data to the nodes

    // jointing first and second nodes
    head->data = 1;
    head->next = second;

    // jointing second and third nodes
    second->data = 2;
    second->next = third;

    // assigning data to third nodes
    third->data = 3;
    third->next = fourth;

    // adding node between 2 and 3 nodes
    fourth->data = 4;
    fourth->next = NULL;
    printf("*****linked list before insertion***********\n");
    traversal(head);

    // head = frontinsert(head);
    // insertafter(head, 2);
    insertend(head);
    printf("*******linked list after insertion*********\n");
    traversal(head);
    
    return 0;
}