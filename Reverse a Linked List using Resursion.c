#include <stdio.h>
/* Define struct */
struct node{
int data;
struct node* next;
};
struct node* head;
void insert_node(int data){
/* Create a new node. */
struct node* newnode = (struct node*)malloc(sizeof(struct node*));
newnode->data = data;
newnode->next = head;
head = newnode;
}
void reverse(struct node* p){
if(p->next == NULL){
head = p;
return;
}
/* Calling reverse method recursively */
reverse(p->next);
struct node* rev = p->next;
rev->next = p;
p->next = NULL;
}
void print(){
struct node* p;
p = head;
while(p!=NULL){
printf("%d\n",p->data);
p=p->next;
}
printf("\n");
}
main()
{
head = NULL;
insert_node(2);
insert_node(4);
insert_node(6);
print();
reverse(head);
print();
}
