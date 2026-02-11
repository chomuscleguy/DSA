#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** stack)
{
	*stack = (LinkedListStack*)malloc(sizeof(**stack));

	if (*stack == NULL)
		return NULL;

	(*stack)->list = NULL;
	(*stack)->top = NULL;
}

void LLS_DestroyStack(LinkedListStack* stack)
{
	while (!LLS_IsEmpty(stack))
	{
		Node* popped = LLS_Pop(stack);
		LLS_DestroyNode(popped);
	}

	free(stack);
}

Node* LLS_CreateNode(char* newData)
{
	Node* newNode = (Node*)malloc(sizeof(*newNode));

	if (newNode == NULL)
		return NULL;

	newNode->data = (char*)malloc(strlen(newData) + 1);

	strcpy(newNode->data, newData);
	newNode->nextNode = NULL;

	return newNode;
}

void LLS_DestroyNode(Node* _node)
{
	free(_node->data);
	free(_node);
}

void LLS_Push(LinkedListStack* stack, Node* newNode)
{
	if (stack->list == NULL)
		stack->list = newNode;
	else
		stack->top->nextNode = newNode;

	stack->top = newNode;
}

Node* LLS_Pop(LinkedListStack* stack)
{
	Node* topNode = stack->top;

	if (stack->list == stack->top)
	{
		stack->list = NULL;
		stack->top = NULL;
	}
	else
	{
		Node* curTop = stack->list;

		while (curTop != NULL & curTop->nextNode != stack->top)
			curTop = curTop->nextNode;

		stack->top = curTop;
		stack->top->nextNode = NULL;
	}

	return topNode;
}

Node* LLS_Top(LinkedListStack* stack)
{
	return stack->top;
}

int LLS_GetSize(LinkedListStack* stack)
{
	int cnt = 0;
	Node* cur = stack->list;

	while (cur != NULL)
	{
		cur = cur->nextNode;
		cnt++;
	}

	return cnt;
}

int LLS_IsEmpty(LinkedListStack* stack)
{
	return (stack->list == NULL);
}

int LLS_IsFull(LinkedListStack* stack)
{
	return 0;
}



