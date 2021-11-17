#include <stdio.h>

int main() 
{
	long long A, B, i, cnt = 0;
	scanf("%lld %lld", &A, &B);
	
	if (A < B)
	{
		for (i = 0; i < B - A - 1; i++)
			cnt++;

		printf("%lld\n", cnt);

		for (i = A + 1; i < B; i++)
			printf("%lld ", i);
	}

	else if (A > B)
	{
		for (i = 0; i < A - B - 1; i++)
			cnt++;

		printf("%lld\n", cnt);

		for (i = B + 1; i < A; i++)
			printf("%lld ", i);
	}

	else
		printf("0");

	return 0;
}
