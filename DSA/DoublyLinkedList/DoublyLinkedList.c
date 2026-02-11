#include "DoublyLinkedList.h"

Node* DLL_CreateNode(ElementType newData)
{
	Node* newNode = (Node*)malloc(sizeof(*newNode));

	if (newNode == NULL)
		return NULL;

	newNode->data = newData;
	newNode->prevNode = NULL;
	newNode->nextNode = NULL;

	return newNode;
}

void DLL_DestroyNode(Node* node)
{
	free(node);
}

void DLL_AppendNode(Node** head, Node* newNode)
{
	if (*head == NULL)
		*head = newNode;
	else
	{
		Node* tail = *head;
		while (tail->nextNode != NULL)
			tail = tail->nextNode;

		tail->nextNode = newNode;
		newNode->prevNode = tail;
	}
}

Node* DLL_GetNodeAt(Node* head, int Location)
{
	Node* cur = head;
	while (cur != NULL && Location-- > 0)
		cur = cur->nextNode;

	return cur;
}

void DLL_RemoveNode(Node** head, Node* Remove)
{
	if (*head == Remove)
	{
		*head = Remove->nextNode;
		if (*head != NULL)
			(*head)->prevNode = NULL;

		Remove->prevNode = NULL;
		Remove->nextNode = NULL;
	}
	else
	{
		Node* tmp = Remove;

		if (Remove->prevNode != NULL)
			Remove->prevNode->nextNode = tmp->nextNode;

		if (Remove->nextNode != NULL)
			Remove->nextNode->prevNode = tmp->prevNode;

		Remove->prevNode = NULL;
		Remove->nextNode = NULL;
	}
}

void DLL_InsertAfter(Node* cur, Node* newNode)
{
	newNode->nextNode = cur->nextNode;
	newNode->prevNode = cur;

	if (cur->nextNode != NULL)
	{
		cur->nextNode->prevNode = newNode;
		cur->nextNode = newNode;
	}
}

int DLL_GetNodeCount(Node* head)
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

void PrintReverse(Node* head)
{
	if (head == NULL)
		return;

	int cnt = DLL_GetNodeCount(head) - 1;

	Node* cur = head;
	while (cur->nextNode != NULL)
		cur = cur->nextNode;

	for (int i = cnt; i >= 0;i--)
	{
		printf("List[%d] : %d\n", i, cur->data);
		cur = cur->prevNode;
	}

}
