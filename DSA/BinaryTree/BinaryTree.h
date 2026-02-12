#ifndef BINARYTREE_H
#define BINARYTREE_H
#pragma once

#include "stdlib.h"
#include "stdio.h"

typedef char ElementType;

typedef struct tagSBTNode
{
	struct tagSBTNode* left;
	struct tagSBTNode* right;

	ElementType data;
}SBTNode;

SBTNode* SBT_CreateNode(ElementType newData);
void SBT_DestroyNode(SBTNode* node);
void SBT_DestroyTree(SBTNode* node);
void SBT_PreorderPrintTree(SBTNode* node);
void SBT_InorderPrintTree(SBTNode* node);
void SBT_PostorderPrintTree(SBTNode* node);

#endif