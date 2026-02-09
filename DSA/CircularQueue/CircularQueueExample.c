#include "CircularQueue.h"

int CircularQueueExample(void)
{
	CircularQueue* queue;

	CQ_CreateQueue(&queue, 10);

	CQ_Enqueue(queue, 1);
	CQ_Enqueue(queue, 2);
	CQ_Enqueue(queue, 3);
	CQ_Enqueue(queue, 4);

	for (int i = 0; i < 3; i++)
	{
		printf("Dequeue : %d, ", CQ_Dequeue(queue));
		printf("Front : %d, Rear : %d \n", queue->front, queue->rear);
	}

	int n = 100;

	while (!CQ_IsFull(queue))
	{
		CQ_Enqueue(queue, n++);
	}

	printf("capacity : %d, size : %d \n\n", queue->capacity, CQ_GetSize(queue));

	while (!CQ_IsEmpty(queue))
	{
		printf("Dequeue : %d, ", CQ_Dequeue(queue));
		printf("Front : %d, Rear : %d \n", queue->front, queue->rear);
	}

	CQ_DestroyQueue(queue);

	return 0;
}