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

// deletion fuction for first nodes
struct node *firstnode(struct node *ptr)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p = ptr;
    ptr = ptr->next;
    free(p);
    return ptr;
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
    printf("***********before deletion*************\n");
    traversal(head);
    head = firstnode(head);
    printf("***********After deletion**************\n");
    traversal(head);

    return 0;
}