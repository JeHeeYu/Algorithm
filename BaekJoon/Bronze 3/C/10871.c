#include <stdio.h>

int main()
{
	int N, X, A, i;
	scanf("%d %d", &N, &X);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &A);
		if (X > A)
			printf("%d ", A);
	}
}
