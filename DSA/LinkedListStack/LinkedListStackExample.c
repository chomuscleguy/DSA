#include "LinkedListStack.h"

int LinkedListStackExample(void)
{
	int cnt = 0;
	Node* popped;

	LinkedListStack* stack;

	LLS_CreateStack(&stack);

	LLS_Push(stack, LLS_CreateNode("abc"));
	LLS_Push(stack, LLS_CreateNode("def"));
	LLS_Push(stack, LLS_CreateNode("ghi"));
	LLS_Push(stack, LLS_CreateNode("jkl"));

	cnt = LLS_GetSize(stack);
	printf("Size : %d, Top : %s \n\n",cnt,LLS_Top(stack)->data);

	for (int i = 0; i < cnt; i++)
	{
		if (LLS_IsEmpty(stack))
			break;

		popped = LLS_Pop(stack);

		printf("Popped : %s, ", popped->data);

		LLS_DestroyNode(popped);

		if (!LLS_IsEmpty(stack))
			printf("Cur Top : %s \n", LLS_Top(stack)->data);
		else
			printf("Stack is Empty");
	}

	LLS_DestroyStack(stack);

	return 0;
}