#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int x)
{
    if(top == MAX_SIZE - 1)
    {
        printf("Error : Stack Overflow\n");
        return;
    }
    else
    {
        A[++top] = x;
    }

}

void Pop()
{
    if(top == -1)
    {
        printf("Error : No Element in Stack\n");
        return;
    }
    top--;
}
int Top()
{
    return A[top];
}

int IsEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void Print()
{
    printf("Stack:");
    for(int i =0;i<=top;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main()
{
    Push(1);Print();
    Push(3);Print();
    Push(5);Print();
    Push(7);Print();
    Push(9);Print();
    Pop();Print();

     // to check stack top
    printf("Top = %d\n",Top());


    // To check stack is empty or not
    if(IsEmpty() == 0)
        printf("Stack is not Empty");
    else
        printf("Stack is Empty");

    return 0;
}
