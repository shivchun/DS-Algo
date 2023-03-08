
#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int data;
    struct Node* link;
};

struct Node* Insert(struct Node* head,int data)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = NULL;
    if(head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node* temp1 = head;
        while(temp1->link != NULL)
        {
            temp1 = temp1->link;

        }
        temp1->link = temp;

    }
    return head;
}

void Print(struct Node* head)
{
    if(head == NULL)return;

    printf("%d ",head->data);
    Print(head->link);
}

void ReversePrint(struct Node* head)
{
    if(head == NULL)return;

    ReversePrint(head->link);
    printf("%d ",head->data);


}
int main()
{
    struct Node* head = NULL;

    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,8);

    Print(head);
    printf("\n");
    ReversePrint(head);




    return 0;
}
