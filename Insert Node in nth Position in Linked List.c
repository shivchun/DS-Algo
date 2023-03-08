#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

struct Node* head;
void Insert(int data,int n)
{
    struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node));
    temp1->data = data;
    temp1->link = NULL;
    if(n==1)
    {
        temp1->link = head;
        head = temp1;
        return;
    }
    struct Node* temp2 = head;
    for(int i = 0;i<n-2;i++)
    {
        temp2 = temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;
}
void Print()
{
    struct Node* temp = head;
    printf("List is:");
    while(temp != NULL)
    {
        printf("%d ",temp->data);
        temp = temp->link;
    }
    printf("\n");
}

void Delete(int n)
{
    struct Node* temp1 = head;
    if(n==1)
    {
        head = temp1->link;
        free(temp1);
        return;
    }
    for(int i = 0;i<n-1;i++)
    {
        temp1 = temp1->link;//(n-1)th node
    }
    struct Node* temp2 = temp1->link; // nth node
    temp1->link = temp2->link;  //(n+1)th node
    free(temp2); //delete temp2

}
int main()
{
    head = NULL;//empty List

    Insert(5,1);Print();
    Insert(7,2);Print();
    Insert(9,1);Print();
    Delete(2);Print();
    Delete(1);Print();


    return 0;
}
