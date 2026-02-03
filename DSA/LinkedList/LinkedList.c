#include "LinkedList.h"

Node* SLL_CreateNode(ElementType newData)
{
	Node* newNode = (Node*)malloc(sizeof(*newNode));

	newNode->data = newData;
	newNode->nextNode = NULL;

	return newNode;
}

void SLL_DestroyNode(Node* node)
{
	free(node);
}

void SLL_DestroyAllNodes(Node** list)
{
	Node* cur = *list;

	while (cur != NULL)
	{
		Node* next = cur->nextNode;
		free(cur);
		cur = next;
	}

	*list = NULL;
}

void SLL_AppendNode(Node** head, Node* newNode)
{
	if (*head == NULL)
		*head = newNode;
	else
	{
		Node* tail = *head;

		while (tail->nextNode != NULL)
			tail = tail->nextNode;

		tail->nextNode = newNode;
	}
}

Node* SLL_GetNodeAt(Node* head, int location)
{
	Node* cur = head;

	while (cur != NULL && location-- >= 0)
		cur = cur->nextNode;

	return cur;
}

void SLL_RemoveNode(Node** head, Node* remove)
{
	if (*head == remove)
		*head = remove->nextNode;
	else
	{
		Node* cur = *head;

		while (cur != NULL && cur->nextNode != remove)
			cur = cur->nextNode;

		if (cur != NULL)
			cur->nextNode = remove->nextNode;
	}
}

void SLL_InsertAfter(Node* cur, Node* newNode)
{
	newNode->nextNode = cur->nextNode;
	cur->nextNode = newNode;
}

void SLL_InsertBefore(Node** head, Node* cur, Node* newNode)
{
	if (*head == cur)
	{
		newNode->nextNode = *head;
		*head = newNode;
	}
	else
	{
		Node* prev = *head;

		while (prev != NULL && prev->nextNode != cur)
			prev = prev->nextNode;

		if (prev != NULL)
		{
			prev->nextNode = newNode;
			newNode->nextNode = cur;
		}
	}
}

void SLL_InsertNewHead(Node** head, Node* newHead)
{
	if (*head == NULL)
		*head = newHead;
	else
	{
		newHead->nextNode = (*head);
		*head = newHead;
	}
}

int SLL_GetNodeCount(Node* head)
{
	unsigned int cnt = 0;
	Node* cur = head;

	while (cur != NULL)
	{
		cur = cur->nextNode;
		cnt++;
	}

	return cnt;
}