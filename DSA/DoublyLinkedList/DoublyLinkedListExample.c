#include "DoublyLinkedList.h"

int DoublyLinkedListExample(void)
{
	Node* list = NULL;
	Node* cur = NULL;

	for (int i = 0; i < 5; i++)
	{
		Node* newNode = DLL_CreateNode(i);

		if (newNode != NULL)
			DLL_AppendNode(&list, newNode);
	}

	int cnt = DLL_GetNodeCount(list);
	printf("List Size : %d\n", cnt);

	cur = list;
	int index = 0;

	while (cur != NULL)
	{
		printf("List[%d] : %d\n", index++, cur->data);
		cur = cur->nextNode;
	}

	printf("\nInserting 3000 After [2]\n\n");

	cur = DLL_GetNodeAt(list, 2);
	DLL_InsertAfter(cur, DLL_CreateNode(3000));

	cnt = DLL_GetNodeCount(list);
	printf("List Size : %d\n", cnt);

	cur = list;
	index = 0;

	while (cur != NULL)
	{
		printf("List[%d] : %d\n", index++, cur->data);
		cur = cur->nextNode;
	}

	printf("\nPrint Reverse\n\n");

	PrintReverse(list);

	printf("\nDestroying List...\n");

	while (list != NULL)
	{
		cur = list;
		DLL_RemoveNode(&list, cur);
		DLL_DestroyNode(cur);
	}

	return 0;
}
