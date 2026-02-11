#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** stack, int capacity)
{
	*stack = (ArrayStack*)malloc(sizeof(**stack));

	if (*stack == NULL)
		return NULL;

	(*stack)->nodes = (Node*)malloc(sizeof(*(*stack)->nodes) * capacity);

	(*stack)->capacity = capacity;
	(*stack)->top = -1;
}

void AS_DestroyStack(ArrayStack* stack)
{
	free(stack->nodes);
	free(stack);
}

void AS_Push(ArrayStack* stack, ElementType data)
{
	if (stack->top == stack->capacity)
	{
		int increase = (int)(stack->capacity * 0.3f);

		if (increase < 1)
			increase = 1;

		int newCapacity = stack->capacity + increase;

		Node* newNodes = (Node*)realloc(stack->nodes, sizeof(*newNodes) * newCapacity);

		if (newNodes == NULL)
			return NULL;

		stack->nodes = newNodes;
		stack->capacity = newCapacity;
	}

	stack->top++;
	stack->nodes[stack->top].data = data;
}

ElementType AS_Pop(ArrayStack* stack)
{
	int position = stack->top;
	ElementType data = stack->nodes[position].data;
	stack->top--;

	int used = stack->top + 1;

	if (used > 0 && used < (int)(stack->capacity * 0.7f))
	{
		int newCapacity = (int)(stack->capacity * 0.7f);

		if (newCapacity < 1)
			newCapacity = 1;

		if (newCapacity < used)
			newCapacity = used;

		Node* newNodes = (Node*)realloc(stack->nodes, sizeof(*newNodes) * newCapacity);

		if (newNodes != NULL)
		{
			stack->nodes = newNodes;
			stack->capacity = newCapacity;
		}
	}

	return data;
}


ElementType AS_Top(ArrayStack* stack)
{
	return stack->nodes[stack->top].data;
}

int AS_GetSize(ArrayStack* stack)
{
	return stack->top + 1;
}

int AS_IsEmpty(ArrayStack* stack)
{
	return (stack->top == -1);
}

int AS_IsFull(ArrayStack* stack)
{
	return (stack->capacity - 1 == stack->top);
}

