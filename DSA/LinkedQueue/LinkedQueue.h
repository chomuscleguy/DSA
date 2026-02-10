#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct tagNode
{
	char* data;
	struct tagNode* nextNode;
}Node;

typedef struct tagLinkedQueue
{
	Node* front;
	Node* rear;
	int count;
}LinkedQueue;

void LQ_CreateQueue(LinkedQueue** queue);
void LQ_DestroyQueue(LinkedQueue* queue);
Node* LQ_CreateNode(char* data);
void LQ_DestroyNode(Node* _node);
void LQ_Enqueue(LinkedQueue* queue, Node* newNode);
Node* LQ_Dequeue(LinkedQueue* queue);
int LQ_IsEmpty(LinkedQueue* queue);

#endif