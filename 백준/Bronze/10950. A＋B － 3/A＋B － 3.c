#include <stdio.h>

int main()
{
	int A, B, t, i;

	scanf("%d", &t);

	for (i = 0; i < t; i++)
	{
		scanf("%d %d", &A, &B);
		printf("%d\n", A + B);
	}

	return 0;
}