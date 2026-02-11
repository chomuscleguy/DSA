#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "example.h"

extern void LinkedListExample(void);
extern void DoublyLinkedListExample(void);
extern void CircularLinkedListExample(void);
extern void ArrayStackExample(void);
extern void LinkedListStackExample(void);
extern void CalculatorExample(void);
extern void CircularQueueExample(void);
extern void LinkedQueueExample(void);
extern void LCRSTreeExample(void);

static ExampleEntry examples[] =
{
	{ 0, LinkedListExample },
	{1, DoublyLinkedListExample},
	{2, CircularLinkedListExample},
	{3,ArrayStackExample},
	{4,LinkedListStackExample},
	{5,CalculatorExample},
	{6,CircularQueueExample},
	{7,LinkedQueueExample},
	{8,LCRSTreeExample},
};

int main(void)
{
	int choice = 0;
	scanf("%d", &choice);
	examples[choice].run();

	return 0;
}
