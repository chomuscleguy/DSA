#include "ArrayStack.h"

int ArrayStackExample(void)
{
	ArrayStack* stack = NULL;

	AS_CreateStack(&stack, 10);

	AS_Push(stack, 3);
	AS_Push(stack, 37);
	AS_Push(stack, 11);
	AS_Push(stack, 12);

	printf("Capacity : %d, Sizee : %d, Top : %d \n\n", stack->capacity, AS_GetSize(stack), AS_Top(stack));

	for (int i = 0; i < 4; i++)
	{
		if (AS_IsEmpty(stack))
			break;

		printf("Popped : %d, ", AS_Pop(stack));

		if (!AS_IsEmpty(stack))
			printf("Current Top : %d\n", AS_Top(stack));
		else
			printf("Stack is Empty.\n");
	}

	printf("\nPushing random values onto the stack...\n\n");

	while (!AS_IsFull(stack))
	{
		AS_Push(stack, rand());
	}

	while (!AS_IsEmpty(stack))
	{
		printf("Popped : %d, ", AS_Pop(stack));

		if (!AS_IsEmpty(stack))
			printf("Current Top : %d\n", AS_Top(stack));
		else
			printf("Stack is Empty.\n");
	}

	AS_DestroyStack(stack);

	return 0;
}

