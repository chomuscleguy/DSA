#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType newData)
{
	LCRSNode* newNode = (LCRSNode*)malloc(sizeof(*newNode));

	if (newNode == NULL)
		return NULL;

	newNode->leftChild = NULL;
	newNode->rightSibling = NULL;
	newNode->data = newData;

	return newNode;
}

void LCRS_DestroyNode(LCRSNode* node)
{
	free(node);
}

void LCRS_DestroyTree(LCRSNode* root)
{
	if (root->rightSibling != NULL)
		LCRS_DestroyTree(root->rightSibling);

	if (root->leftChild != NULL)
		LCRS_DestroyTree(root->leftChild);

	root->leftChild = NULL;
	root->rightSibling = NULL;

	LCRS_DestroyNode(root);
}

void LCRS_AddChildNode(LCRSNode* parent, LCRSNode* child)
{
	if (parent->leftChild == NULL)
		parent->leftChild = child;
	else
	{
		LCRSNode* tempNode = parent->leftChild;
		while (tempNode->rightSibling != NULL)
			tempNode = tempNode->rightSibling;

		tempNode->rightSibling = child;
	}
}

void LCRS_PrintTree(LCRSNode* node, int depth)
{
	for (int i = 0; i < depth;i++)
		printf("   ");

	if (depth > 0)
		printf("+--");

	printf("%c\n", node->data);

	if (node->leftChild != NULL)
		LCRS_PrintTree(node->leftChild, depth + 1);

	if (node->rightSibling != NULL)
		LCRS_PrintTree(node->rightSibling, depth);
}