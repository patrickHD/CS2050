/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/1/2015
    Lab section: G
    Sub code: Queue
    CS2050 Lab8
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#define MAX_STRING_LEN 20

queue* load_queue(char* input);
queue* play_game(int passes, queue* head);


int main(int argc, char* argv[])
{
	if(argc<2)
	{
		printf("Not enough args.\n");
		return 0;
	}
	queue** head;
	head=malloc(sizeof(queue));
	head=load_queue(argv[1]);
	
	//-_-
	return 0;
}

queue* load_queue(char* input)
{
	char* name=malloc(sizeof(char)*MAX_STRING_LEN);
	queue** head=malloc(sizeof(queue));
	FILE* inputF=fopen(input, "r");
	int i;
	for(i=0; i<5; i++)
	{
		fscanf(inputF, "%s", name);
		printf("%s\n", name);
		enqueue(head, name);
	}
	fclose(inputF);
}

queue* play_game(int passes, queue* head)
{
	return NULL;
}