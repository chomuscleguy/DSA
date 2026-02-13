#include "ExpressionTree.h"

int ExpressionTreeExample(void)
{
	ETNode* root = NULL;

	char postfixExpression[20] = "71*52-/";
	ET_BuildExpressionTree(postfixExpression, &root);

	printf("Preorder ... \n");
	ET_PreorderPrintTree(root);
	printf("\n\n");

	printf("Inorder ... \n");
	ET_InorderPrintTree(root);
	printf("\n\n");

	printf("Postorder ... \n");
	ET_PostorderPrintTree(root);
	printf("\n");

	printf("Evaulation Result : %f \n", ET_Evaluate(root));

	ET_DestroyNode(root);

	return 0;
}