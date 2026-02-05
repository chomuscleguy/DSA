#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** stack, int capacity)
{
	*stack = (ArrayStack*)malloc(sizeof(**stack));

	if (*stack == NULL)
		return;

	(*stack)->nodes = (Node*)malloc(sizeof(Node) * capacity);

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
	stack->top++;
	stack->nodes[stack->top].data = data;
}

ElementType AS_Pop(ArrayStack* stack)
{
	int position = stack->top--;
	return stack->nodes[position].data;
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

