#include "CircularDoublyLinkedList.h"

int CircularLinkedListExample(void)
{
	Node* list = NULL;
	Node* cur = NULL;
	int cnt = 0;

	for (int i = 0;i < 5;i++)
		CDLL_AppendNode(&list, CDLL_CreateNode(i));

	cnt = CDLL_GetNodeCount(list);
	printf("List Size : %d\n", cnt);

	cnt = CDLL_GetNodeCount(list);

	for (int i = 0;i < cnt;i++)
	{
		cur = CDLL_GetNodeAt(list, i);
		printf("List[%d] : %d\n", i++, cur->data);
	}

	printf("\nInserting 3000 After [2]\n\n");

	cur = CDLL_GetNodeAt(list, 2);
	CDLL_InsertAfter(cur, CDLL_CreateNode(3000));

	printf("\nRemoving Node at 2...\n");

	cur = CDLL_GetNodeAt(list, 2);
	CDLL_RemoveNode(&list, cur);
	CDLL_DestroyNode(cur);

	cnt = CDLL_GetNodeCount(list);

	for (int i = 0;i < cnt * 2;i++)
	{
		if (i == 0)
			cur = list;
		else
			cur = cur->nextNode;

		printf("List[%d] : %d\n", i, cur->data);
	}

	printf("\nDestroying List...\n");

	cnt = CDLL_GetNodeCount(list);

	for (int i = 0; i < cnt; i++)
	{
		cur = CDLL_GetNodeAt(list, 0);
		if (cur != NULL)
		{
			CDLL_RemoveNode(&list, cur);
			CDLL_DestroyNode(cur);
		}
	}

	return 0;
}