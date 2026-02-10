#include "LinkedQueue.h"

int LinkedQueueExample(void)
{
	Node* popped;
	LinkedQueue* queue;

	LQ_CreateQueue(&queue);

	LQ_Enqueue(queue, LQ_CreateNode("abc"));
	LQ_Enqueue(queue, LQ_CreateNode("def"));
	LQ_Enqueue(queue, LQ_CreateNode("ghi"));
	LQ_Enqueue(queue, LQ_CreateNode("jkl"));

	printf("Queue Size : %d\n", queue->count);

	while (!LQ_IsEmpty(queue))
	{
		popped = LQ_Dequeue(queue);

		printf("Dequeue : %s \n", popped->data);
		LQ_DestroyNode(popped);
	}

	LQ_DestroyQueue(queue);

	return 0;
}