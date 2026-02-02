#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "stdlib.h"

typedef int ElementType;

typedef struct tagNode
{
	ElementType Data;
	struct tagNode* NextNode;
}Node;

Node* SLL_CreateNode(ElementType NewData);
void SLL_DestroyNode(Node* Node);
void SLL_AppendNode(Node** Head, Node* NewNode);
void SLL_RemoveNode(Node** Head, Node* Remove);
void SLL_InsertAfter(Node* Cur, Node* NewNode);
void SLL_InsertNewHead(Node** Head, Node* NewHead);
Node* SLL_GetNodeAt(Node* Head, int Location);
int SLL_GetNodeCount(Node* Head);

#endif