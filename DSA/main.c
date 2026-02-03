#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "example.h"

extern void LinkedListExample(void);
extern void DoublyLinkedListExample(void);

static ExampleEntry examples[] =
{
	{ "LinkedList", LinkedListExample },
	{"DoublyLinkedList", DoublyLinkedListExample},

};

int main(void)
{
	int choice = 0;
	scanf("%d", &choice);
	examples[choice].run();

	return 0;
}
