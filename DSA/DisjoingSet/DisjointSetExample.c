#include "DisjointSet.h"

int DisjointSetExample(void)
{
	int a = 1, b = 2, c = 3, d = 4;
	DisjointSet* set1 = DS_MakeSet(&a);
	DisjointSet* set2 = DS_MakeSet(&b);
	DisjointSet* set3 = DS_MakeSet(&c);
	DisjointSet* set4 = DS_MakeSet(&d);

	printf("Set1 == Set2 : %d \n", DS_FindSet(set1) == DS_FindSet(set2));

	DS_UnionSet(set1, set3);
	printf("Set1 == Set3 : %d \n", DS_FindSet(set1) == DS_FindSet(set3));

	DS_UnionSet(set3, set4);
	printf("Set3 == Set4 : %d \n", DS_FindSet(set3) == DS_FindSet(set4));

	return 0;
}