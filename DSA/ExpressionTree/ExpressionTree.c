#include "ExpressionTree.h"

ETNode* ET_CreateNode(ElementType newData)
{
	ETNode* newNode = (ETNode*)malloc(sizeof(*newNode));

	if (newNode == NULL)
		return NULL;

	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = newData;
}

void ET_DestroyNode(ETNode* node)
{
	free(node);
}

void ET_DestroyTree(ETNode* root)
{
	if (root == NULL)
		return NULL;

	ET_DestroyNode(root->left);
	ET_DestroyNode(root->right);
	ET_DestroyNode(root);
}

void ET_PreorderPrintTree(ETNode* node)
{
	if (node == NULL)
		return NULL;

	printf("%c", node->data);

	ET_PreorderPrintTree(node->left);
	ET_PreorderPrintTree(node->right);
}

void ET_InorderPrintTree(ETNode* node)
{
	if (node == NULL)
		return NULL;

	printf("(");
	ET_InorderPrintTree(node->left);

	printf("%c", node->data);

	ET_InorderPrintTree(node->right);
	printf(")");

}

void ET_PostorderPrintTree(ETNode* node)
{
	if (node == NULL)
		return NULL;

	ET_PostorderPrintTree(node->left);
	ET_PostorderPrintTree(node->right);

	printf("%c", node->data);
}

void ET_BuildExpressionTree(char* postfixExpression, ETNode** node)
{
	int len = strlen(postfixExpression);
	char token = postfixExpression[len - 1];
	postfixExpression[len - 1] = '\0';

	switch (token)
	{
	case '+':case '-':case'*':case'/':
		*node = ET_CreateNode(token);
		ET_BuildExpressionTree(postfixExpression, &(*node)->right);
		ET_BuildExpressionTree(postfixExpression, &(*node)->left);
		break;
	default:
		*node = ET_CreateNode(token);
		break;
	}
}

double ET_Evaluate(ETNode* tree)
{
	char tmp[2];

	double left = 0;
	double right = 0;
	double result = 0;

	if (tree == NULL)
		return 0.0;

	switch (tree->data)
	{
	case '+': case '-': case '*': case'/':
		left = ET_Evaluate(tree->left);
		right = ET_Evaluate(tree->right);

		if (tree->data == '+')
			result = left + right;
		else if (tree->data == '-')
			result = left - right;
		else if (tree->data == '*')
			result = left * right;
		else if (tree->data == '/')
			result = left / right;

		break;
	default:
		memset(tmp, 0, sizeof(tmp));
		tmp[0] = tree->data;
		result = atof(tmp);
		break;
	}

	return result;
}