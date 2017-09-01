/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/8/2015
    Lab section: G
    Sub code: BST
    CS2050 Lab9
*/

#include "bst.h"

BST* insert(BST* tree, int data)
{
    if(tree==NULL)
    {
        tree=malloc(sizeof(BST));
        (tree)->data=data;
        (tree)->left=NULL;
        (tree)->right=NULL;
        return tree;
    }
    else if(data<=(tree)->data)
    {
        tree->left=insert(tree->left, data);
        return tree;
    }
    else
    {
        tree->right=insert(tree->right, data);
        return tree;
    }
}

BST* find(BST* tree, int data)
{
    if(tree==NULL || tree->data==data)
    {
            return tree;
    }
    else if(data<(tree)->data)
    {
        return find(tree->left, data);
    }
    else
    {
        return find(tree->right, data);
    }
}

void inorder(BST* tree)
{
    if(tree!=NULL)
    {
        inorder(tree->left);
        printf("%d\n", tree->data);
        inorder(tree->right);
    }
}

void destroy(BST* tree)
{
    if(tree!=NULL)
    {
        destroy(tree->left);
        destroy(tree->right);
        free(tree);
    }
}
