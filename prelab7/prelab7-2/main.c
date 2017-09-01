#include <stdio.h>
#include <stdlib.h>

typedef struct node_
{
    int val;
    struct node_ *next;
}node;

node* insert_at_head(node* head, int val);

int main()
{
    printf("Hello world!\n");
    return 0;
}

node* insert_at_head(node* head, int val)
{
    node *next;
    next->val=5;
    return next;
}
