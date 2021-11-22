#include <stdio.h>

int main() 
{
	int A, B, C, D;
	scanf("%d %d %d %d", &A, &B, &C, &D);
	
	C += D;

	while (C >= 60)
	{
		if (C >= 60)
		{
			C -= 60;
			B++;
		}

		if (B >= 60)
		{
			B -= 60;
			A++;
		}

		if (A >= 24)
		{
			A -= 24;
		}
	}

	printf("%d %d %d", A, B, C);
}
