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
    printf("List is:");
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->link;
    }
    printf("\n");
}

struct Node* Reverse(struct Node* head)
{
    struct Node *current,*prev,*link; //link is used as a address of next Node
    current = head;
    prev = NULL;
    while(current !=NULL)
    {
        link = current->link;
        current->link = prev;
        prev = current;
        current = link;

    }
    head = prev;
    return head;


}
int main()
{
    struct Node* head = NULL;

    head = Insert(head,2);
    head = Insert(head,4);
    head = Insert(head,6);
    head = Insert(head,8);

    Print(head);
    head = Reverse(head);
    Print(head);



    return 0;
}
