#include "DoublyLinkedList.h"

int DoublyLinkedListExample(void)
{
	Node* list = NULL;
	Node* cur = NULL;
	int cnt = 0;

	for (int i = 0; i < 5; i++)
	{
		Node* newNode = DLL_CreateNode(i);
		DLL_AppendNode(&list, newNode);
	}

	cnt = DLL_GetNodeCount(list);

	for (int i = 0;i < cnt;i++)
	{
		cur = DLL_GetNodeAt(list, i);
		printf("List[%d] : %d\n", i, cur->data);
	}

	printf("\nInserting 3000 After [2]\n\n");

	cur = DLL_GetNodeAt(list, 2);
	DLL_InsertAfter(cur, DLL_CreateNode(3000));

	cnt = DLL_GetNodeCount(list);

	for (int i = 0; i < cnt; i++)
	{
		cur = DLL_GetNodeAt(list, i);
		printf("List[%d] : %d\n", i, cur->data);
	}

	printf("\nPrint Reverse\n\n");

	PrintReverse(list);

	printf("\nDestroying List...\n");

	cnt = DLL_GetNodeCount(list);

	for (int i = 0; i < cnt;i++)
	{
		cur = DLL_GetNodeAt(list, 0);

		if (cur != NULL)
		{
			DLL_RemoveNode(&list, cur);
			DLL_DestroyNode(cur);
		}
	}

	return 0;
}
