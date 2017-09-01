/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/22/2015
    Lab section: G
    Sub code: Summer
    CS2050 Lab10
*/

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char* argv[])
{
    if(argc<3)
    {
        printf("Incorrect arguments\n");
        return 0;
    }

    FILE* fp = fopen(argv[1], "r");
    int size;
    fscanf(fp, "%d", &size);

    int *arr=malloc(sizeof(int)*size);
    int i;
    for(i=0; i<size; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }
    BST* tree = build_balanced_tree(arr, 0, size-1);
    print(tree);
    printf("-------------------------------------\n");
    delete_node(tree, atoi(argv[2]));
    print(tree);
    printf("-----------------BONUS---------------\n");
    mirror(tree);
    print(tree);
    return 0;
}
