#ifndef EXPRESSIONTREE_H
#define EXPRESSIONTREE_H
#pragma once

#include "stdlib.h"
#include "stdio.h"

typedef char ElementType;

typedef struct tagETNode
{
	struct tagETNode* left;
	struct tagETNode* right;

	ElementType data;
}ETNode;

ETNode* ET_CreateNode(ElementType newData);
void ET_DestroyNode(ETNode* node);
void ET_DestroyTree(ETNode* root);
void ET_PreorderPrintTree(ETNode* node);
void ET_InorderPrintTree(ETNode* node);
void ET_PostorderPrintTree(ETNode* node);
void ET_BuildExpressionTree(char* postfixExpression, ETNode** node);
double ET_Evaluate(ETNode* tree);

#endif