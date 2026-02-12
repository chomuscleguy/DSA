#ifndef LCRSTREE_H
#define LCRSTREE_H
#pragma once

#include "stdio.h"
#include "stdlib.h"

typedef char ElementType;

typedef struct tagLCRSNode
{
	struct LCRSNode* leftChild;
	struct LCRSNode* rightSibling;

	ElementType data;
}LCRSNode;

LCRSNode* LCRS_CreateNode(ElementType newData);
void LCRS_DestroyNode(LCRSNode* node);
void LCRS_DestroyTree(LCRSNode* root);
void LCRS_AddChildNode(LCRSNode* parent, LCRSNode* child);
void LCRS_PrintTree(LCRSNode* node, int depth);
void LCRS_PrintNodesAtLevel(LCRSNode* node, int index ,int level);

#endif

