#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

/* 
 * Creates an empty stack and sets
 * the size equal to 0
 */

stack* create_stack() {
	stack* s = malloc(sizeof(stack));
	s->size = 0;
	s->stack = NULL;
	return s;
}

/*
 * pushes the value into the top of the stack
 */ 
void push(stack *s, int val) {
	node* newPtr = malloc(sizeof(node));//pointer to new node
	
	//insert the node at stack top
	if(newPtr != NULL)
	{
		newPtr->data = val;
		newPtr->next = s->stack;
		s->stack = newPtr;
	}
	else
	{
		printf("%d not inserted. No memory available.\n", val);
	}
}

/*
 * pops the head of the stack
 * the value is not returned
 */
void pop(stack *s) {
	if(s->size == 0)
	{
		return;
	}
	node* tempPtr;//temporary node pointer
	
	tempPtr = s->stack;
	s->stack = s->stack->next;
	free(tempPtr);
	s->size--;
}


/*
 * returns the value at the top of the stack
 * the stack remains unchanged
 */
int top(stack *s) {
	return s->stack->data;
}

/*
 * returns 1 if the stack is empty
 * 0 otherwise
 */
int isEmpty(stack *s) {
	if(s->stack == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
