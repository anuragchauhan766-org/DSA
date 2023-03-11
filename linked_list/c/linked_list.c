#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

void insertatend(node **head, int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;

    if (*head == NULL)
    {
        newnode->next = NULL;
        *head = newnode;
        return;
    }
    node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->next = NULL;
}
void insertatbeg(node **head, int data)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = *head;
    *head = newnode;
}
void insertafter(node **head, int data, int node_no)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    if (node_no == 1)
    {
        newnode->next = (*head)->next;
        (*head)->next = newnode;
        return;
    }
    node *temp = *head;
    while (node_no-- != 1)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    node *head = NULL;

    insertatend(&head, 1);
    insertatend(&head, 2);
    insertatbeg(&head, 7);
    insertatend(&head, 3);
    insertatend(&head, 4);
    insertatend(&head, 5);
    insertatend(&head, 6);
    insertatbeg(&head, 8);
    insertafter(&head, 9, 6);
    display(head);
    return 0;
}