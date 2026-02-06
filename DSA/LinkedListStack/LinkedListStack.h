#ifndef LINKEDLISTSTACK_H
#define LINKEDLISTSTACK_H
#pragma once

#include "stdio.h"
#include "stdlib.h"

typedef int ElementType;

typedef struct tagNode
{
	char* data;
	struct tagNode* nextNode;
}Node;

typedef struct tagLinkeListStack
{
	Node* list;
	Node* top;
}LinkedListStack;

void LLS_CreateStack(LinkedListStack** stack);
void LLS_DestroyStack(LinkedListStack* stack);
Node* LLS_CreateNode(char* newData);
void LLS_DestroyNode(Node* _node);
void LLS_Push(LinkedListStack* stack, Node* newNode);
Node* LLS_Pop(LinkedListStack* stack);
Node* LLS_Top(LinkedListStack* stack);
int LLS_GetSize(LinkedListStack* stack);
int LLS_IsEmpty(LinkedListStack* stack);
int LLS_IsFull(LinkedListStack* stack);

#endif
