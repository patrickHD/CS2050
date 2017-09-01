/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 3/18/2015
    Lab section: G
    Sub code: Linked List
    CS2050 Lab7
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int val;
    struct node_ *next;
}node;

node* insert_at_head(node* head, int val);
node* create_list(char* file);
void print_list(node* head);
node* delete_even(node* head);
void del(node* head);
node* reverse_list(node* head);

//runs all of the functions
int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Incorrect number of command line arguments\n");
    }
    node *head=NULL;
    head=malloc(sizeof(node));
    head=create_list(argv[1]);
    print_list(head);
    //head=delete_even(head);
    head=reverse_list(head);
    print_list(head);
    del(head);
    return 0;
}
//inserts the given value into the head of the linked list
node* insert_at_head(node* head, int val)
{
	node *nodeN=(node*)malloc(sizeof(node));
	nodeN->val=val;
	nodeN->next=head;
	return nodeN;
}
//inserts each function into the head of the linked list
node* create_list(char* file)
{
    node *list=NULL;
    FILE* inputF=fopen(file, "r");
    int val;
    while(!feof(inputF))
    {
        fscanf(inputF, "%d", &val);
        list=insert_at_head(list, val);
    }
    return list;
}
//prints out each number of the linked list
void print_list(node *head)
{
    node *current=head;
    while(current!=NULL)
    {
        printf("%d  ", current->val);
        current=current->next;
    }
    printf("\n");
}
//deletes each node from the linked list that contains an even value
node* delete_even(node* head)
{
    node *current=head;
    node *temp;
    while(current!=NULL)
    {

        if(current->val%2==0)
        {
            temp=current->next;
            free(current);
            current=temp;
        }
        current=current->next;
    }
    return current;
}
//will delete each node from the linked list
void del(node* head)
{
    node *current=head;
    node *temp;
    while(current!=NULL)
    {
        temp=current->next;
        free(current);
        current=temp;
    }
}
//reverses the nodes in the linked list
node* reverse_list(node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    if(head->next==NULL)
    {
        return head;
    }
    node* rest=reverse_list(head->next);
    head->next->next=head;
    head->next=NULL;
    return rest;
}
