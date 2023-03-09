#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* rear = NULL;
struct Node* front = NULL;

void Enqueue(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = x;
    temp->link = NULL;
    if(rear == NULL && front == NULL)
    {
        rear = temp;
        front  = temp;
        return;
    }
    rear->link = temp;
    rear = temp;
}

void Dqueue()
{
    struct Node* temp = front;
    if(front == NULL)
    {
        printf("Error:No element in Queue");
        return;
    }
    else if(rear == front)
    {
        rear = NULL;
        front = NULL;
    }
    else
    {
        front = front->link;
    }
    free(temp);
}

void Print()
{
    struct Node* temp = front;
    printf("Queue:");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int Front()
{
    if(front==NULL)
    {
        printf("Error: No element in Queue");
    }
    else
        return front->data;
}

int main()
{
    Enqueue(2);Print();
    Enqueue(4);Print();
    Enqueue(6);Print();
    Enqueue(8);Print();
    Dqueue();Print();

    printf("Front Element = %d",Front());

    return 0;
}
