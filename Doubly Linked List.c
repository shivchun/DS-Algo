#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

void InsertAtHead(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
    head->prev = temp;
    temp->next = head;
    head =temp;
    }
}

void InsertAtTail(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->prev = NULL;
    temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node* temp1 = head;
        while(temp1->next!=NULL)
        {
            temp1=temp1->next;
        }
        temp1->next = temp;
        temp->prev = temp1;
    }

}

void Print(struct Node* p)
{
    printf("List is:");
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
void ReversePrint(struct Node* p)
{
    if(p == NULL)  // empty list return
        return;
    // Going to last node

    while(p->next != NULL)
    {
        p = p->next;
    }
    // Traversing backword using prev pointer

    printf("Reverse List:");
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->prev;
    }
    printf("\n");

}

void Delete(int n)
{
    struct Node* temp = head;
    if(n == 1)
    {
     head = temp->next;
     head->prev = NULL;
     free(temp);
    }
    else
    {
        for(int i = 0;i<n-1;i++)
        {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}


int main()
{
    head = NULL; // empty list
    InsertAtHead(2);Print(head);
    InsertAtHead(4);Print(head);
    InsertAtHead(6);Print(head);
    InsertAtTail(3);Print(head);

    ReversePrint(head);

    Delete(2);
    Print(head);


    return 0;
}
