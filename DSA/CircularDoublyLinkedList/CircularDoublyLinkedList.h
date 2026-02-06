#ifndef CIRCULARDOUBLYLINKEDLIST_H
#define CIRCULARDOUBLYLINKEDLIST_H
#pragma once

#include "stdlib.h"
#include "stdio.h"

typedef int ElementType;

typedef struct tagNode
{
	ElementType data;
	struct tagNode* prevNode;
	struct tagNode* nextNode;
}Node;

Node* CDLL_CreateNode(ElementType newData);
void CDLL_DestroyNode(Node* node);
void CDLL_AppendNode(Node** head, Node* newNode);
void CDLL_InsertAfter(Node* cur, Node* newNode);
void CDLL_RemoveNode(Node** head, Node* remove);
Node* CDLL_GetNodeAt(Node* head, int location);
int CDLL_GetNodeCount(Node* head);

#endif
