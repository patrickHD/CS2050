/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/8/2015
    Lab section: G
    Sub code: BST
    CS2050 Lab9
*/

#ifndef BST_H_
#define BST_H_

#include "stdio.h"
#include "stdlib.h"

typedef struct node_{
    int data;
	struct node_ *left;
	struct node_ *right;
}BST;

BST* insert(BST* tree, int data);
BST* find(BST* tree, int data);
void inorder(BST* tree);
void destroy(BST* tree);

#endif // BST_H_
