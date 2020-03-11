/*
 * Name: stack.c
 * Purpose: stack 구현
 */

//Headers
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//Data types
typedef int Data;
typedef struct node* NodePtr;
typedef struct node
{
	Data data;
	NodePtr next;
} Node;
typedef struct stack
{
	NodePtr top;
	unsigned int nodeNumber;
} Stack;

//function prototypes
Stack* stack_init(Data initData);
bool stack_push(Stack* target, Data data);
Data stack_pop(Stack* target);
Data stack_top(Stack* target);
unsigned int stack_size(Stack* target);
bool stack_remove(Stack* target);

//function definitions
Stack* stack_init(Data initData)
{
	NodePtr tempNode = malloc(sizeof(Node));
	tempNode->data = initData;
	tempNode->next = NULL;
	Stack* retval = malloc(sizeof(Stack));
	retval->top = tempNode;
	retval->nodeNumber = 1;
	return retval;
}
bool stack_remove(Stack* target)
{
	while(target->nodeNumber > 0)
		stack_pop(target);
	free(target);
	return true;
}
bool stack_push(Stack* target, Data data)
{
	NodePtr tempNode = malloc(sizeof(Node));
	tempNode->data = data;
	tempNode->next = target->top;
	target->top = tempNode;
	return true;
}
Data stack_top(Stack* target)
{
	return target->top->data;
}
Data stack_pop(Stack* target)
{
	Data retval = stack_top(target);
	NodePtr tempNode = target->top;
	target->top = tempNode -> next;
	free(tempNode);
	nodeNumber--;
	return retval;
}

