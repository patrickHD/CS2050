#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "stack.h"

#define MAX_EQU_LEN 100

/*
 * Returns a number corresponding the the preccedence 
 * of different arithmetic operators. * has a higher 
 * precedence that / which is greater than %, +, -
 * in that order. Higher precedence should return a higher
 * number so say 5 for * 1 for - and 0 for a non operator
 */
static int prec(char operator) {
	if(operator == '*')
	{
		return 5;
	}
	else if(operator == '/')
	{
		return 4;
	}
	else if(operator == '%')
	{
		return 3;
	}
	else if(operator == '+')
	{
		return 2;
	}
	else if(operator == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
 * Returns 1 if the string passed is an integer
 * 0 otherwise
 */
static int isNumeric(char *num) {
	int i;
	for(i = 0; num[i] != '\0'; i++)
	{
		if(isdigit(num[i]) != 0)
		{
			return 1;
		}
		return 0;
	}
	return 1;
}

/*
 * converts a valid infix expression into postfix
 * Hint put a space between numbers and operators 
 * so you can use strtok in evaluate_postfix
 * ex: get 7 8 + vs 78+
 *
 * This is done with the following algorithm
 *
 * for each token in the string
 *     if the next token is a number
 *         append it to the postfix string
 *     else if the next token is a left paren
 *          push it onto the stack
 *     else if the next token is a right paren
 *          while the stack is not empty and the left paren is not at the top of the stack
 *              pop the next operator off of the stack
 *              append it to the postfix string
 *          pop the left paren off of the stack and discard it
 *     else if the next token is an operator (+, -, *, /)
 *         while the stack is not empty and the operator at the top of the stack has a higher precedence than the token
 *              pop the top element off of the stack and append it to the postfix string
 *         push the current token onto the stack
 *
 * while there are elements remaining on the stack
 *     pop the top element off of the stack and append it to the postfix string
 */
char* infix_to_postfix(char* infix) {
	char* postfix = malloc(sizeof(char)*100);
	stack* operators = create_stack(); 
	int i;
	int j = 0;
	for(i = 0; infix[i] != '\0'; i++)
	{
		if(isNumeric(&(infix[i])) != 0)
		{
			postfix[j] = infix[i];
			j++;
		}
		else if(infix[i] == '(')
		{
			push(operators, infix[i]);
		}
		else if(infix[i] == ')')
		{
			while(operators != NULL && top(operators) != '(')
			{
				postfix[j] = top(operators);
				pop(operators);
				j++;
			}
			pop(operators);
		}
		else
		{
			while(operators != NULL && prec(top(operators)) > prec(infix[i]))
			{
				postfix[j] = top(operators);
				pop(operators); 
				j++;
			}
			push(operators, infix[i]);
		}
	}
	while(!isEmpty(operators))
	{
		postfix[j] = top(operators);
		pop(operators);
		j++;
	}
	return postfix;
	free(postfix);
}

/*
 * This function takes in a valid postfix expression
 * and evaluate it to an integer
 *
 * for each token in the string
 *      if the token is numeric
 *          convert it to an integer
 *          push it onto the stack
 *      else
 *          pop the top 2 element off of the stack
 *          the first goes into the right variable
 *          the second goes into the left variable
 *          apply the operation: 
 *              result = left op right
 *              ex result = left + right
 *
 *          push the result onto the stack
 *          
 * return the result from the stack
 */

int evaluate_postfix(char* postfix) {
	char* token = strtok(postfix, "\n");
	stack* head = create_stack();
	int i, x, y;
	int result;
	while(token != NULL)
	{
		if(isNumeric(token))
		{
			push(head, atoi(token));
		}
		else
		{
			x = top(head);
			pop(head);
			y = top(head);
			pop(head);
		}
		switch(token[0])
		{
			case '*':
				result = x * y;
			case '/':
				result = x / y;
			case '+':
				result = x + y;
			case '-':
				result = x - y;
		}
		push(head, result);
		token = strtok(NULL, " ");
	}
	//result = top(head);
	pop(head);
	free(head);
	return result;
}

