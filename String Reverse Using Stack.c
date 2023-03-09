#include<stdio.h>
#include<string.h>

#define MAX 101

int top;
char stack[MAX];

void Push(char x)
{
    if(top == MAX - 1)
    {
         printf("Error : Stack is Overflow");
         return;
    }
    else
    {
        stack[++top] = x;
    }


}

void Pop()
{
    if(top == -1)
    {
        printf("Error: Stack is Empty");
        return;
    }
    else
    {
        printf("%c",stack[top]);
        top--;
    }

}

int main()
{
    char str[] = "Shiv Shankar";

    int len = strlen(str);

    top = -1;

    for(int i = 0;i<len;i++)
    {
        Push(str[i]);
    }

    // Normal String
    printf("String: ");
    for(int i = 0;i<len;i++)
    {
       printf("%c",stack[i]);
    }


    printf("\n");

    // reverse string
    printf("Reverse: ");
    for(int i = 0;i<len;i++)
    {
        Pop();
    }

    return 0;
}
