/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/25/2015
    Lab section: G
    CS2050 HW4
*/

#include "link.h"

List* add(List* list, char* wrd)
{
    List* new_node = malloc(sizeof(List));
	if (!new_node) return NULL;

	// copy data
	new_node->word = malloc(sizeof(char)*(strlen(wrd) + 1));
	strcpy(new_node->word, wrd);
	new_node->next = NULL;

	// make sure queue exists, if not start it
	if(!list) return new_node;
	List* current_node = list;
	while(current_node->next != NULL) {
		current_node = current_node->next;
	}
	current_node->next = new_node;
	return current_node;
}

void destroy(List* list)
{
    List* clist=list;
	while(list)
    {
		list = list->next;
		free(clist);
		clist = list;
	}
}
int is_pos(List* pwords, char* word)
{
    List* tmp=pwords;
    while(tmp)
    {
        //printf("xx\n");
        if(tmp->word==word)
        {
            return 1;
        }
        tmp=tmp->next;
    }
    return 0;
}

int is_neg(List* nwords, char* word)
{
    List* tmp=nwords;
    while(tmp)
    {
        //printf("zz\n");
        if(tmp->word==word)
        {
            return 1;
        }
        tmp=tmp->next;
    }
    return 0;
}

int positivity(List* pwords, List* nwords, List* review)
{
    int pos=0;
    int neg=0;
    while(review!=NULL)
    {
        while(pwords!=NULL)
        {
            if(pwords->word==review->word)
            {
                pos++;
            }
            pwords=pwords->next;
        }
        while(nwords!=NULL)
        {
            if(nwords->word==review->word)
            {
                neg++;
            }
            nwords=nwords->next;
        }
        review=review->next;
    }
    if(pos>neg)
        return 1;
    else if(pos==neg)
        return 0;
    else
        return -1;
}
