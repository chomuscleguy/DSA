#include "LinkedList.h"

int LinkedListExample(void)
{
	Node* list = NULL;
	Node* cur = NULL;

	for (int i = 0; i < 5; i++)
	{
		Node* newNode = SLL_CreateNode(i);

		if (newNode != NULL)
			SLL_AppendNode(&list, newNode);
	}

	SLL_InsertNewHead(&list, SLL_CreateNode(-1));
	SLL_InsertNewHead(&list, SLL_CreateNode(-2));

	int cnt = SLL_GetNodeCount(list);
	printf("List Size : %d\n", cnt);

	cur = list;
	int index = 0;

	while (cur != NULL)
	{
		printf("List[%d] : %d\n", index++, cur->data);
		cur = cur->nextNode;
	}

	printf("\nInserting 3000 After [2]\n\n");

	cur = SLL_GetNodeAt(list, 2);

	SLL_InsertAfter(cur, SLL_CreateNode(3000));

	cnt = SLL_GetNodeCount(list);
	printf("List Size : %d\n", cnt);

	cur = list;
	index = 0;

	while (cur != NULL)
	{
		printf("List[%d] : %d\n", index++, cur->data);
		cur = cur->nextNode;
	}

	printf("\nDestroying List...\n");

	while (list != NULL)
	{
		cur = list;
		SLL_RemoveNode(&list, cur);
		SLL_DestroyNode(cur);
	}

	return 0;
}