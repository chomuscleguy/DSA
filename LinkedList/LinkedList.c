#include "LinkedList.h"

Node* SLL_CreateNode(ElementType NewData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

void SLL_DestroyNode(Node* Node)
{
	free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL)
		*Head = NewNode;
	else
	{
		Node* Tail = (*Head);

		while (Tail->NextNode != NULL)
			Tail = Tail->NextNode;

		Tail->NextNode = NewNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Cur = Head;

	while (Cur != NULL && Location-- >= 0)
		Cur = Cur->NextNode;

	return Cur;
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if ((*Head) == Remove)
		*Head = Remove->NextNode;
	else
	{
		Node* Cur = *Head;

		while (Cur != NULL && Cur->NextNode != Remove)
			Cur = Cur->NextNode;

		if (Cur != NULL)
			Cur->NextNode = Remove->NextNode;
	}
}

void SLL_InsertAfter(Node* Cur, Node* NewNode)
{
	NewNode->NextNode = Cur->NextNode;
	Cur->NextNode = NewNode;
}

void SLL_InsertNewHead(Node** Head, Node* NewHead)
{
	if ((*Head) == NULL)
		(*Head) = NewHead;
	else
	{
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

int SLL_GetNodeCount(Node* Head)
{
	int Cnt = 0;
	Node* Cur = Head;

	while (Cur != NULL)
	{
		Cur = Cur->NextNode;
		Cnt++;
	}

	return Cnt;
}