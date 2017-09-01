/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/22/2015
    Lab section: G
    Sub code: Summer
    CS2050 Lab10
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

BST* build_balanced_tree(int a[], int low, int high);
BST* delete_node(BST* tree, int data);
BST* min(BST* tree);
void padding(char ch, int n);
void structure(BST* root, int level);
void print(BST* root);
void mirror(BST* tree);

#endif
