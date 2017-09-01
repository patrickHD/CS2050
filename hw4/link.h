/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/25/2015
    Lab section: G
    CS2050 HW4
*/

#ifndef LINK_H_INCLUDED
#define LINK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct node_ {
	char* word;
	struct node_*next;
} List;

List* add(List* list, char* wrd);
void destroy(List* list);
int is_pos(List* pwords, char* word);
int is_neg(List* nwords, char* word);
int positivity(List* pwords, List* nwords, List* review);

#endif // LINK_H_INCLUDED
