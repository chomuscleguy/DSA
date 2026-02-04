#include "LinkedList.h"

int LinkedListExample(void)
{
	Node* list = NULL;
	Node* cur = NULL;
	int cnt = 0;

	for (int i = 0; i < 5; i++)
	{
		Node* newNode = SLL_CreateNode(i);
		SLL_AppendNode(&list, newNode);
	}

	SLL_InsertNewHead(&list, SLL_CreateNode(-1));
	SLL_InsertNewHead(&list, SLL_CreateNode(-2));

	cnt = SLL_GetNodeCount(list);

	for (int i = 0; i < cnt; i++)
	{
		cur = SLL_GetNodeAt(list, i);
		printf("List[%d] : %d\n", i, cur->data);
	}

	printf("\nInserting 3000 After [2]\n\n");

	cur = SLL_GetNodeAt(list, 2);
	SLL_InsertAfter(cur, SLL_CreateNode(3000));

	cnt = SLL_GetNodeCount(list);

	for (int i = 0; i < cnt;i++)
	{
		cur = SLL_GetNodeAt(list, i);
		printf("List[%d] : %d\n", i, cur->data);
	}

	printf("\nDestroying List...\n");

	for (int i = 0; i < cnt;i++)
	{
		cur = SLL_GetNodeAt(list, 0);

		if (cur != NULL)
		{
			SLL_RemoveNode(&list, cur);
			SLL_DestroyNode(cur);
		}
	}

	return 0;
}