/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/8/2015
    Lab section: G
    Sub code: BST
    CS2050 Lab9
*/

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int closest(BST* tree, int data);

int main(int argc, char* argv[])
{
    if(argc<3)
    {
        printf("incorrect arguments\n");
        return 0;
    }
    int val;
    BST *tree=NULL;
    FILE *inputF = fopen(argv[1], "r");
    while(!feof(inputF))
    {
        fscanf(inputF, "%d", &val);
        tree=insert(tree, val);
    }
    int search=atoi(argv[2]);
    inorder(tree);
    tree=find(tree, search);
    if(tree!=NULL)
    {
        printf("%d was found\n", search);
    }
    else
    {
        printf("%d was not found\n", search);
    }
    return 0;
}

