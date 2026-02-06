#define _CRT_SECURE_NO_WARNINGS

#include "Calculator.h"

char NUMBER[] = { '0','1', '2', '3', '4', '5', '6','7','8','9','.' };

int IsNumber(char cipher)
{
	int cnt = sizeof(NUMBER);

	for (int i = 0; i < cnt;i++)
		if (cipher == NUMBER[i])
			return 1;

	return 0;
}

unsigned int GetNextToken(char* expression, char* token, int* TYPE)
{
	int i = 0;

	if (IsNumber(expression[0]))
	{
		*TYPE = OPERAND;

		while (IsNumber(expression[i]))
		{
			token[i] = expression[i];
			i++;
		}
	}
	else
	{
		*TYPE = expression[0];
		token[0] = expression[0];
		i = 1;
	}

	token[i] = '\0';

	return i;
}


int GetPriority(char operator, int inStack)
{
	int priority = -1;

	switch (operator)
	{
	case LEFT_PARENTHESIS:
		if (inStack)
			priority = 3;
		else
			priority = 0;
		break;

	case MULTIPLY:
	case DIVIDE:
		priority = 1;
		break;
	case PLUS:
	case MINUS:
		priority = 2;
		break;
	}

	return priority;
}

int IsPrior(char operatorInStack, char operatorInToken)
{

	return (GetPriority(operatorInStack, 1) > GetPriority(operatorInToken, 0));
}

void GetPostfix(char* infixExpreession, char* postfixExpression)
{
	LinkedListStack* stack;

	char token[32];
	int type = -1;
	unsigned int position = 0;
	unsigned int length = strlen(infixExpreession);

	LLS_CreateStack(&stack);

	while (position < length)
	{
		position += GetNextToken(&infixExpreession[position], token, &type);

		if (type == OPERAND)
		{
			strcat(postfixExpression, token);
			strcat(postfixExpression, " ");
		}
		else if (type == RIGHT_PARENTHESIS)
		{
			while (!LLS_IsEmpty(stack))
			{
				Node* popped = LLS_Pop(stack);

				if (popped->data[0] == LEFT_PARENTHESIS)
				{
					LLS_DestroyNode(popped);
					break;
				}
				else
				{
					strcat(postfixExpression, popped->data);
					LLS_DestroyNode(popped);
				}
			}
		}
		else
		{
			while (!LLS_IsEmpty(stack) && !IsPrior(LLS_Top(stack)->data[0], token[0]))
			{
				Node* popped = LLS_Pop(stack);

				if (popped->data[0] != LEFT_PARENTHESIS)
					strcat(postfixExpression, popped->data);

				LLS_DestroyNode(popped);
			}

			LLS_Push(stack, LLS_CreateNode(token));
		}
	}

	while (!LLS_IsEmpty(stack))
	{
		Node* popped = LLS_Pop(stack);

		if (popped->data[0] != LEFT_PARENTHESIS)
			strcat(postfixExpression, popped->data);

		LLS_DestroyNode(popped);
	}

	LLS_DestroyStack(stack);
}

double Calculate(char* postfixExpression)
{
	LinkedListStack* stack;
	Node* resNode;

	double res;
	char token[32];
	int type = -1;
	unsigned int read = 0;
	unsigned int length = strlen(postfixExpression);

	LLS_CreateStack(&stack);

	while (read < length)
	{
		read += GetNextToken(&postfixExpression[read], token, &type);

		if (type == SPACE)
			continue;

		if (type == OPERAND)
		{
			Node* newNode = LLS_CreateNode(token);
			LLS_Push(stack, newNode);
		}
		else
		{
			char resString[32];
			double operator1, operator2, tmpRes;
			Node* operatorNode;

			operatorNode = LLS_Pop(stack);
			operator2 = atof(operatorNode->data);
			LLS_DestroyNode(operatorNode);

			operatorNode = LLS_Pop(stack);
			operator1 = atof(operatorNode->data);
			LLS_DestroyNode(operatorNode);

			switch (type)
			{
			case PLUS:
				tmpRes = operator1 + operator2;
				break;
			case MINUS:
				tmpRes = operator1 - operator2;
				break;
			case MULTIPLY:
				tmpRes = operator1 * operator2;
				break;
			case DIVIDE:
				tmpRes = operator1 / operator2;
				break;
			}

			_gcvt(tmpRes, 10, resString);
			LLS_Push(stack, LLS_CreateNode(resString));
		}
	}

	resNode = LLS_Pop(stack);
	res = atof(resNode->data);

	LLS_DestroyNode(resNode);
	LLS_DestroyStack(stack);

	return res;
}