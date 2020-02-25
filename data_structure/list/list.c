//linear linked list
//headers
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//data types
typedef int Data;
typedef struct
{
	Data data;
	Node* next;
} Node;
typedef struct
{
	Node* head;
	Node* cur;
} List;

//function prototypes
List* listInit(int data);//ok
bool listDelete(List* target);//ok
Data listCurData(List* target);//ok
Data listHead(List* target);//ok
bool listNext(List* target);//ok
bool listInsert(List* tarList, Data tarData);//ok
bool listRemove(List* target);//ok

//main()
int main()
{
	//대충 테스트할 코드들
	printf("Linked List Test Program\n\n");
	printf("Data type: int\n");
	printf("Initial Data : ");
	Data initData;
	scanf("%d", &initData);
	List* list = listInit(initData);
	int option = 0;
	Data tempData;
	while(true)
	{
		printf("1. Current data\t2. Head data\t3. Next\t4. Insert data\t5. Remove data\6. Delete list\n");
		printf("Select : ");
		scanf("%d", option);
		switch (option)
		{
		case 1:
			printf("Current Data : %d\n", listCurData(list));
			break;
		case 2:
			printf("Head Data : %d\n",listHead(list));
			break;
		case 3:
			if(listNext(list))
				printf("Success\n");
			else
				printf("Failed\n");
			break;
		case 4:
			printf("Inserting Data : ");
			scanf("%d",&tempData);
			if(listInsert(list,tempData))
				printf("Success\n");
			else
				printf("Failed\n");
			break;
		case 5:
			if(listDelete(list))
				printf("Success\n");
			else
				printf("Failed\n");
			break;
		case 6:
			if(listRemove(list))
				printf("Success\n");
			else
				printf("Failed\n");
			return 0;
		default:
			printf("Wrong option\n");
			break;
		}
	}
}

//function definitions
List* listInit(int data)
{
	List* retval = malloc(sizeof(List));
	Node* temp = malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
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
bool listNext(List* target)
{
	if(target->cur->next == NULL)
		return 0;
	target->cur = target->cur->next;
	return 1;
}
bool listInsert(List* target, Data data)
{
	Node* temp = malloc(sizeof(Node));
	temp->data = data;
	temp->next = target->cur->next;
	target->cur->next = temp;
	return 1;
}
bool listRemove(List* target)
{
	if (target->cur->next == NULL)
		return 0;
	Node* rmTarget = target->cur->next;
	target->cur->next = target->cur->next->next;
	free(rmTarget);
	return 1;
}
bool listDelete(List* target)
{
	listHead(target);
	while(listRemove(target));
	free(target->head);
	free(target);
	return 1;
}