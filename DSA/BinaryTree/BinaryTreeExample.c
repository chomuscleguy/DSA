#include "BinaryTree.h"

int BinaryTreeExample(void)
{
	SBTNode* A = SBT_CreateNode('A');
	SBTNode* B = SBT_CreateNode('B');
	SBTNode* C = SBT_CreateNode('C');
	SBTNode* D = SBT_CreateNode('D');
	SBTNode* E = SBT_CreateNode('E');
	SBTNode* F = SBT_CreateNode('F');
	SBTNode* G = SBT_CreateNode('G');

	A->left = B;
	B->left = C;
	B->right = D;

	A->right = E;
	E->left = F;
	E->right = G;

	printf("Preorder ...\n");
	SBT_PreorderPrintTree(A);
	printf("\n\n");

	printf("Inorder ...\n");
	SBT_InorderPrintTree(A);
	printf("\n\n");

	printf("Postorder ...\n");
	SBT_PostorderPrintTree(A);
	printf("\n");

	SBT_DestroyTree(A);

	return 0;
}