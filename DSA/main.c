#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "example.h"

extern void LinkedListExample(void);
extern void DoublyLinkedListExample(void);
extern void CircularLinkedListExample(void);
extern void ArrayStackExample(void);
extern void LinkedListStackExample(void);
extern void CalculatorExample(void);

static ExampleEntry examples[] =
{
	{ "LinkedList", LinkedListExample },
	{"DoublyLinkedList", DoublyLinkedListExample},
	{"CircularLinkedList", CircularLinkedListExample},
	{"ArrayStack",ArrayStackExample},
	{"LinkedListStack",LinkedListStackExample},
	{"Calculator",CalculatorExample},
};

int main(void)
{
	int choice = 0;
	scanf("%d", &choice);
	examples[choice].run();

	return 0;
}
