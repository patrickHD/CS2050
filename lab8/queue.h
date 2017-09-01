/*
    Name: Patrick Daniel
    Pawprint: phd6x2
    Date: 4/1/2015
    Lab section: G
    Sub code: Queue
    CS2050 Lab8
*/

#ifndef QUEUE_H_
#define QUEUE_H_

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct node_ {
	char* name;
	struct node_ *next;
} queue;

void enqueue(queue** head, char* name);
char dequeue(queue** head);
void free_queue(queue* head);

#endif
