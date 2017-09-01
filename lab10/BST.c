/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/22/2015
    Lab section: G
    Sub code: Summer
    CS2050 Lab10
*/

#include "bst.h"

BST* build_balanced_tree(int a[], int low, int high)
{
    if(low>high)
	{
		return NULL;
	}

    int mid=(high+low)/2;
    BST* tree=malloc(sizeof(*tree));

    tree->data=a[mid];
    tree->left=build_balanced_tree(a,low,mid-1);
    tree->right=build_balanced_tree(a,mid+1,high);

    return tree;
}
BST* delete_node(BST* tree, int data)
{
    if(tree==NULL)
    {
        printf("Error\n");
        return tree;
    }
    BST* tmp=malloc(sizeof(*tmp));
    while(tree->data != data)
    {
        if(data<tree->data)
        {
            tree=tree->left;
        }
        else
        {
            tree=tree->right;
        }

        if(tree==NULL)
        {
            printf("Number does not exist in tree\n");
            return NULL;
        }
    }

    if(tree->left==NULL && tree->right==NULL)
    {
        tmp=tree;
        tree=NULL;
        free(tmp);
    }
    else if(tree->left != NULL && tree->right==NULL)
    {
        tmp=tree;
        tree=tree->left;
        free(tmp);
    }
    else if(tree->left==NULL && tree->right != NULL)
    {
        tmp=tree;
        tree=tree->right;
        free(tmp);
    }
    else if(tree->left != NULL && tree->right != NULL)
    {
        tmp=tree;
        while(tree->right != NULL)
        {
            tree->data=tree->right->data;
            tree=tree->right;
        }
        free(tree);
    }
    else
    {
        printf("Something went wrong... :( \n");
    }
    return tree;

}
BST* min(BST* tree)
{
    if(tree==NULL)
    {
        printf("Dead tree\n");
        return NULL;
    }

    while(tree->left != NULL)
    {
        tree=tree->left;
    }
    printf("%d", tree->data);
    return tree;
}

void padding(char ch, int n)
{
    int i;

    for (i = 0; i < n; ++i)
    {
        putchar(ch);
    }
}

void structure(BST* root, int level)
{
    if (root == NULL)
    {
        padding('\t', level);
        puts("~");
    }
    else
    {
        structure(root->right, level+1);
        padding('\t', level);
        printf("%d\n", root->data);
        structure(root->left, level+1);
    }
}

void print(BST* root)
{
	structure(root, 0);
}
//BONUS
void mirror(BST* tree)
{
    if(tree==NULL)
    {
        return;
    }
    else
    {
        BST* tmp;
        mirror(tree->left);
        mirror(tree->right);
        tmp=tree->left;
        tree->left = tree->right;
        tree->right = tmp;
    }
}
