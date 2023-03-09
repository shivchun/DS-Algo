#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* top;

void Push(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->link = top;
    top = temp;
}
void Pop()
{
    struct Node* temp = top;
    if(top == NULL)
    {
        printf("Error : Stack is Empty\n");
    }
    else
    {
        top = top->link;
    }
    free(temp);
}
void Print()
{
    struct Node* temp = top;
    printf("Stack:");
    while(temp!= NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int Top()
{
    return top->data;
}
int IsEmpty()
{
    if(top == NULL)
        return 0;
    else
        return 1;
}

int main()
{

    top  = NULL; // empty stack

    Push(2);Print();
    Push(4);Print();
    Push(6);Print();
    Push(8);Print();
    Pop();Print();

    // value at top of stack
    printf("Stack Top = %d \n",Top());

    // stack is empty or not
    if(IsEmpty() == 0)
        printf("Stack is Empty");
    else
        printf("Stack is not Empty");

    return 0;
}
