//linear linked list
//headers
#include <stdio.h>
#include <stdlib.h>

//data types
typedef int Data;
typedef struct
{
	Data data;
	Node* next = NULL;
} Node;
typedef struct
{
	Node* head;
	Node* cur;
} List;

//function prototypes
List* listInit(int data);//ok
int listDelete(List* target);//ok
Data listCurData(List* target);//ok
Data listHead(List* target);//ok
int listNext(List* target);//ok
int listInsert(List* tarList, Data tarData);//ok
int listRemove(List* target);//ok

//function definitions
int main()
{
	//대충 테스트할 코드들
}
List* listInit(int data);
{
	List* retval = malloc(sizeof(List));
	Node* temp = malloc(sizeof(Node));
	temp->data = data;
	retval->head = temp;
	retval->cur = retval->head;
	return retval;
}
Data listCurData(List* target)
{
	return target->cur->data;
}
Data listHead(List* target)
{
	target->cur = target->head;
	return listCurData(target);
}
int listNext(List* target)
{
	if(target->cur->next == NULL)
		return 0;
	target->cur = target->cur->next;
	return 1;
}
int listInsert(List* target, Data data)
{
	Node* temp = malloc(sizeof(Node));
	temp->data = data;
	temp->next = target->cur->next;
	target->cur->next = temp;
	return 1;
}
int listRemove(List* target)
{
	if (target->cur->next == NULL)
		return 0;
	Node* rmTarget = target->cur->next;
	target->cur->next = target->cur->next->next;
	free(rmTarget);
	return 1;
}
int listDelete(List* target)
{
	listHead(target);
	while(listRemove(target));
	free(target->head);
	free(target);
	return 1;
}