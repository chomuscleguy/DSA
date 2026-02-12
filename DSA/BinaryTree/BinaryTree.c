#include "BinaryTree.h"

SBTNode* SBT_CreateNode(ElementType newData)
{
	SBTNode* newNode = (SBTNode*)malloc(sizeof(*newNode));

	if (newNode == NULL)
		return NULL;

	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = newData;
}

void SBT_DestroyNode(SBTNode* node)
{
	free(node);
}

void SBT_DestroyTree(SBTNode* node)
{
	if (node == NULL)
		return NULL;

	SBT_DestroyNode(node->left);
	SBT_DestroyNode(node->right);
	SBT_DestroyNode(node);
}

void SBT_PreorderPrintTree(SBTNode* node)
{
	if (node == NULL)
		return NULL;

	printf("%c", node->data);

	SBT_PreorderPrintTree(node->left);
	SBT_PreorderPrintTree(node->right);
}

void SBT_InorderPrintTree(SBTNode* node)
{
	if (node == NULL)
		return NULL;

	SBT_InorderPrintTree(node->left);

	printf("%c", node->data);

	SBT_InorderPrintTree(node->right);
}

void SBT_PostorderPrintTree(SBTNode* node)
{
	if (node == NULL)
		return NULL;
	s
	SBT_PostorderPrintTree(node->left);
	SBT_PostorderPrintTree(node->right);

	printf("%c", node->data);
}