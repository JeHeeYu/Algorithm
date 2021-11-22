#include <stdio.h>

int main()
{
	long A, B, C, i;
	scanf("%ld %ld %ld", &A, &B, &C);
	
	long result = 1;

	if (B >= C)
	{
		printf("-1");
		return 0;
	}

	result = A / (C - B) + 1;

	printf("%d", result);

	return 0;
}
