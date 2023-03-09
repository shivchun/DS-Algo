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
        top--;


}
int ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') return 1;
	else if(opening == '{' && closing == '}') return 1;
	else if(opening == '[' && closing == ']') return 1;
	return 0;
}


int CheckBalancedParenthesis()
{
    char exp[MAX];
    printf("Enter Epression:");
    scanf("%s",&exp);

    int len = strlen(exp);

    for(int i =0;i<len;i++)
	{
		if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			Push(exp[i]);
		else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if(top == -1 || ArePair(stack[top],exp[i]) == 0)
				return 0;
			else
				Pop();
		}
	}
	return top == -1 ? 1 : 0;

}

int main()
{
    int result;
    top = -1; // empty stack


    result = CheckBlancedParenthesis();

    if(result == 1)
        printf("Balanced Expression");
    else
        printf("Not Balanced");


    return 0;
}
