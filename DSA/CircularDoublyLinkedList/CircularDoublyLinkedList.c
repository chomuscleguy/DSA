#include "CircularDoublyLinkedList.h"

Node* CDLL_CreateNode(ElementType newData)
{
	Node* newNode = (Node*)malloc(sizeof(*newNode));

	newNode->data = newData;
	newNode->prevNode = NULL;
	newNode->nextNode = NULL;

	return newNode;
}

void CDLL_DestroyNode(Node* node)
{
	free(node);
}

void CDLL_AppendNode(Node** head, Node* newNode)
{
	if (*head == NULL)
	{
		*head = newNode;
		(*head)->nextNode = *head;
		(*head)->prevNode = *head;
	}
	else
	{
		Node* tail = (*head)->prevNode;
		
		tail->nextNode->prevNode = newNode;
		tail->nextNode = newNode;

		newNode->nextNode = *head;
		newNode->prevNode = tail;
	}
}

void CDLL_InsertAfter(Node* cur, Node* newNode)
{
	newNode->nextNode = cur->nextNode;
	newNode->prevNode = cur;

	if (cur->nextNode != NULL)
	{
		cur->nextNode->prevNode = newNode;
		cur->nextNode = newNode;
	}
}

void CDLL_RemoveNode(Node** head, Node* remove)
{
	if (*head == remove)
	{
		(*head)->prevNode->nextNode = remove->nextNode;
		(*head)->nextNode->prevNode = remove->prevNode;

		*head = remove->nextNode;

		remove->prevNode = NULL;
		remove->nextNode = NULL;
	}
	else
	{
		remove->prevNode->nextNode = remove->nextNode;
		remove->nextNode->prevNode = remove->prevNode;

		remove->prevNode = NULL;
		remove->nextNode = NULL;
	}
}

Node* CDLL_GetNodeAt(Node* head, int location)
{
	Node* cur = head;

	while (cur != NULL && location-- > 0)
		cur = cur->nextNode;

	return cur;
}

int CDLL_GetNodeCount(Node* head)
{
	unsigned int cnt = 0;
	Node* cur = head;

	while (cur != NULL)
	{
		cur = cur->nextNode;
		cnt++;

		if (cur == head)
			break;
	}

	return cnt;
}