#include <stdio.h>

#define BITSETNULL		(BitSet) 0
#define BITSETBITS		32
#define SETOF(no)			((BitSet) 1 << (no))

typedef unsigned long BitSet;

int IsMember(BitSet s, int data);
void Add(BitSet* s, int data);
void ReMove(BitSet* s, int data);
int Size(BitSet s);
void Print(BitSet s);

int main()
{
	BitSet A = BITSETNULL;


	Add(&A, 1);
	Add(&A, 3);
	Add(&A, 5);

	printf("size : %d\n", Size(A));
	ReMove(&A, 3);
	printf("size : %d\n", Size(A));

	Print(A);
}

int IsMember(BitSet s, int data)
{
	return s & SETOF(data);
}

void Add(BitSet* s, int data)
{
	*s |= SETOF(data);
}

void ReMove(BitSet* s, int data)
{
	*s &= ~SETOF(data);
}

int Size(BitSet s)
{
	int count = 0;
	for (; s != BITSETNULL; count++)
		s &= s - 1;

	return count;
}

void Print(BitSet s)
{
	int i;

	printf("{ ");

	for (i = 0; i < BITSETBITS; i++)
		if (IsMember(s, i))
			printf("%d ", i);

	printf("}");
}
