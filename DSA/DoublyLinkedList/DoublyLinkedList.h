#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
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

Node* DLL_CreateNode(ElementType newData);
void DLL_DestroyNode(Node* node);
void DLL_AppendNode(Node** head, Node* newNode);
void DLL_RemoveNode(Node** head, Node* remove);
void DLL_InsertAfter(Node* cur, Node* newNode);
Node* DLL_GetNodeAt(Node* head, int location);
int DLL_GetNodeCount(Node* head);
void PrintReverse(Node* Head);

#endif
