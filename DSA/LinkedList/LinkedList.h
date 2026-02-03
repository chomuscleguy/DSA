#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
#include "stdlib.h"
#include "stdio.h"

typedef int ElementType;

typedef struct tagNode
{
	ElementType data;
	struct tagNode* nextNode;
}Node;

Node* SLL_CreateNode(ElementType newData);
void SLL_DestroyNode(Node* node);
void SLL_DestroyAllNodes(Node** list);
void SLL_AppendNode(Node** head, Node* newNode);
void SLL_RemoveNode(Node** head, Node* remove);
void SLL_InsertAfter(Node* cur, Node* newNode);
void SLL_InsertBefore(Node** head, Node* cur, Node* newNode);
void SLL_InsertNewHead(Node** head, Node* newHead);
Node* SLL_GetNodeAt(Node* head, int location);
int SLL_GetNodeCount(Node* head);

#endif