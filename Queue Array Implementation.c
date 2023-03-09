#include<stdio.h>
#define MAX 101

int rear,front,A[MAX];

int IsEmpty()
{
    if(front == -1 && rear == -1)
        return 1;
    else
        return 0;
}

void Enqueue(int x)
{
    if((rear+1)%MAX == front)
        return;
    else if(IsEmpty() == 1)
    {
        front = 0;
        rear = 0;
    }

    else
        rear = (rear+1)%MAX;

    A[rear] = x;
}

void Dqueue()
{
    if(IsEmpty() ==1)
        return;
    else if(front == rear)
        {
            front = -1;
            rear = -1;
        }
    else
        front = (front+1)%MAX;

}

int Front()
{
    if(IsEmpty() == 1)
        printf("Error: Queue is Empty");
    else
        return A[front];
}

void Print()
{
    // Finding number of elements in queue
    int count = (rear+MAX-front)%MAX + 1;
    printf("Queue:");
    for(int i = 0; i <count; i++)
    {
        int index = (front+i) % MAX; // Index of element while traversing circularly from front
        printf("%d ",A[index]);
    }
    printf("\n");

}

int main()
{
    // empty queue
    front = -1;
    rear = -1;

    Enqueue(1);Print();
    Enqueue(3);Print();
    Enqueue(5);Print();
    Enqueue(7);Print();
    Enqueue(9);Print();
    Enqueue(11);Print();
    Dqueue();Print();

    printf("Front = %d",Front());

    return 0;

}

