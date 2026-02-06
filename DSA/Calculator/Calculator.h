#ifndef CALCULATOR_H
#define CALCULATOR_H
#pragma once

#include "stdlib.h"
#include "../LinkedListStack/LinkedListStack.h"

typedef enum
{
	LEFT_PARENTHESIS = '(', RIGHT_PARENTHESIS = ')',
	PLUS = '+', MINUS = '-',
	MULTIPLY = '*', DIVIDE = '/',
	SPACE = ' ', OPERAND,
}SYMBOL;

int IsNumber(char cipher);
unsigned int GetNextToken(char* expression, char* token, int* TYPE);
int IsPrior(char operatorInStack, char operatorInToken);
void GetPostfix(char* infixExpreession, char* postfixExpression);
double Calculate(char* postfixExpression);

#endif
