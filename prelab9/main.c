#include <stdio.h>
#include <stdlib.h>

typedef struct node_ {
    int val;
	struct node_ *left;
	struct node_ *right;
} node;

node* insert (node* root, int val);
void inorder(node* root);

int main(void)
{
    node *root=NULL;
    int val;
    while(val != -1)
    {
        printf("Enter a number. -1 to quit: ");
        scanf("%d", &val);
        if(val!=-1)
        {
            root=insert(root, val);
        }
    }
    inorder(root);
    return 0;
}

node* insert(node* root, int val)
{
    if(root==NULL)
    {
        root=malloc(sizeof(node));
        (root)->val=val;
        (root)->left=NULL;
        (root)->right=NULL;
        return root;
    }
    else if(val<(root)->val)
    {
        root->left=insert(root->left, val);
        return root;
    }
    else
    {
        root->right=insert(root->right, val);
        return root;
    }
}

void inorder(node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\n", root->val);
        inorder(root->right);
    }
}
