#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "string.h"
#include "Calculator.h"

int CalculatorExample(void)
{
	char infixExperssion[100];
	char postfixExperssion[100];

	double res = 0.0;

	memset(infixExperssion, 0, sizeof(infixExperssion));
	memset(postfixExperssion, 0, sizeof(postfixExperssion));

	printf("Enter Infix Expression ");
	scanf("%s", infixExperssion);

	GetPostfix(infixExperssion, postfixExperssion);

	printf("Infix : %s \nPostifx : %s \n", infixExperssion, postfixExperssion);

	res = Calculate(postfixExperssion);

	printf("Calculation Result : %f \n", res);

	return 0;
}