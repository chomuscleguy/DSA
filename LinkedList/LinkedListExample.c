#include "stdio.h"
#include "LinkedList.h"

int main(void)
{
	Node* List = NULL;
	Node* Cur = NULL;

	for (int i = 0; i < 5; i++)
	{
		Node* NewNode = SLL_CreateNode(i);

		if (NewNode != NULL)
			SLL_AppendNode(&List, NewNode);
	}

	SLL_InsertNewHead(&List, SLL_CreateNode(-1));
	SLL_InsertNewHead(&List, SLL_CreateNode(-2));

	int cnt = SLL_GetNodeCount(List);
	printf("List Size : %d\n", cnt);

	Cur = List;
	int index = 0;

	while (Cur != NULL)
	{
		printf("List[%d] : %d\n", index++, Cur->Data);
		Cur = Cur->NextNode;
	}

	printf("\nInserting 3000 After [2]\n\n");

	Cur = SLL_GetNodeAt(List, 2);

	if (Cur != NULL)
		SLL_InsertAfter(Cur, SLL_CreateNode(3000));

	cnt = SLL_GetNodeCount(List);
	printf("List Size : %d\n", cnt);

	Cur = List;
	index = 0;

	while (Cur != NULL)
	{
		printf("List[%d] : %d\n", index++, Cur->Data);
		Cur = Cur->NextNode;
	}

	printf("\nDestroying List...\n");

	while (List != NULL)
	{
		Cur = List;
		List = List->NextNode;
		SLL_DestroyNode(Cur);
	}

	return 0;
}