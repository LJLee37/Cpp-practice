//linear linked list
//headers
#include <stdio.h>

//data types

typedef int Data;
typedef struct{
	Data data;
	Node* next = NULL;
} Node;
typedef struct{
	Node* head;
	Node* cur;

} List;

//function prototypes
List* listInit(int data);
int listDelete(List* target);
Data listCurData(List* target);
Data listHead(List* target);
int listNext(List* target);
int listInsert(List* tarList, Data tarData);
int listRemove(List* target);

//function definitions
int main()
{
	//
