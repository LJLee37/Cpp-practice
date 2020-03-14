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
void stack_pop(Stack* target);
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
	target->nodeNumber++;
	return true;
}
Data stack_top(Stack* target)
{
	if(target->nodeNumber)
		return target->top->data;
	else
	{
		printf("Empty\n");
		return -1;
	}
	
}
void stack_pop(Stack* target)
{
	if(target->nodeNumber)
	{
		NodePtr tempNode = target->top;
		target->top = tempNode -> next;
		free(tempNode);
		target->nodeNumber--;
		return;
	}
	else
	{
		printf("Warning attemp to pop empty stack\n");
		printf("Nothing will happen\n");
		return;
	}
}
unsigned int stack_size(Stack* target)
{
	return target->nodeNumber;
}
int main()
{
	printf("스택 테스트용 프로그램.\n");
	printf("시작 데이터 : ");
	Data tempData;
	scanf("%d", &tempData);
	Stack* stack = stack_init(tempData);
	while(true)
	{
		printf("1. 푸시 2. 팝 3. 탑 4. 사이즈 5. 삭제");
		printf("선택 : ");
		unsigned int sw;
		scanf("%d", &sw);
		switch (sw)
		{
		case 1:
			printf("푸시할 데이터 입력 : ");
			scanf("%d", &tempData);
			stack_push(stack, tempData);
			break;
		case 2:
			printf("팝\n");
			stack_pop(stack);
			break;
		case 3:
			printf("탑 : %d\n", stack_top(stack));
			break;
		case 4:
			printf("사이즈 : %d\n", stack_size(stack));
			break;
		case 5:
			printf("스택 삭제\n");
			return (int)(!stack_remove(stack));
			break;
		default:
			break;
		}
	}
}