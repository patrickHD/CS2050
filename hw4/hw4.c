/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/25/2015
    Lab section: G
    CS2050 HW4
*/

#include <stdio.h>
#include <stdlib.h>
#include "link.h"
#define MAX_WORD_LEN 30
#define MAX_LINE 250

List* create_list(char* file);

int main(int argc, char* argv[])
{
    if(argc < 3)
    {
        printf("Incorrect arguments.\n");
        printf("Need: ./exc pwords.txt nwords.txt review.txt\n");
    }

    List* pwords=create_list(argv[1]);
    List* nwords=create_list(argv[2]);
    List* review=create_list(argv[3]);
/*
    FILE* fp=fopen(argv[3], "r");
    if(fp==NULL)
    {
        printf("Error opening file.\n");
        return -1;
    }

    char buffer[MAX_LINE];
    char* token=NULL;
    while(fgets(buffer, MAX_LINE, fp))
    {
        if(buffer[strlen(buffer)-1]=='\n');
        {
            buffer[strlen(buffer)-1]='\0';
        }
        token=strtok(buffer, " \r\n\t.,-");
        while(token!=NULL)
        {
            review=add(review, token);
            token=strtok(NULL, "\r\n\t.,-");
        }
    }
*/
    if(positivity(pwords, nwords, review)==1)
    {
        printf("review is positive\n");
    }
    else if(positivity(pwords, nwords, review)==0)
    {
        printf("review is neutral\n");
    }
    else
    {
        printf("review is negative\n");
    }


    //fclose(fp);
    destroy(pwords);
    destroy(nwords);
    return 0;
}

List* create_list(char* file)
{
    FILE *fp = fopen(file, "r");
	if (fp == NULL)
    {
		printf("Error opening file\n");
		return NULL;
	}

	// read file into linked list
	char* word=malloc(sizeof(char)*MAX_WORD_LEN);
	List* list=NULL;//=malloc(sizeof(List));
	List* head;
	int flag=0;
	while (fscanf(fp, "%s", word) == 1)
    {
		list=add(list, word);
		if(flag==0)
        {
            head=list;
            flag=99;
        }
	}
	// close file and return length
	fclose(fp);
	return head;
}
