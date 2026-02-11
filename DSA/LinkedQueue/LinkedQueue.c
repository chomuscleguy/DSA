#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue** queue)
{
	*queue = (LinkedQueue*)malloc(sizeof(**queue));

	if ((*queue) == NULL)
		return;

	(*queue)->front = NULL;
	(*queue)->rear = NULL;
	(*queue)->count = 0;
}

void LQ_DestroyQueue(LinkedQueue* queue)
{
	while (!LQ_IsEmpty(queue))
	{
		Node* popped = LQ_Dequeue(queue);
		LQ_DestroyNode(popped);
	}

	free(queue);
}

Node* LQ_CreateNode(char* newData)
{
	Node* newNode = (Node*)malloc(sizeof(*newNode));

	if (newNode == NULL)
		return NULL;

	newNode->data = (char*)malloc(strlen(newData) + 1);

	strcpy(newNode->data, newData);
	newNode->nextNode = NULL;

	return newNode;
}

void LQ_DestroyNode(Node* _node)
{
	free(_node->data);
	free(_node);
}

void LQ_Enqueue(LinkedQueue* queue, Node* newNode)
{
	if (queue->front == NULL)
	{
		queue->front = newNode;
		queue->rear = newNode;
		queue->count++;
	}
	else
	{
		queue->rear->nextNode = newNode;
		queue->rear = newNode;
		queue->count++;
	}
}

Node* LQ_Dequeue(LinkedQueue* queue)
{
	Node* front = queue->front;

	if (queue->front->nextNode == NULL)
	{
		queue->front = NULL;
		queue->rear = NULL;
	}
	else
		queue->front = queue->front->nextNode;
	queue->count--;

	return front;
}

int LQ_IsEmpty(LinkedQueue* queue)
{
	return (queue->front == NULL);
}