#include <stdio.h>

int main() 
{
	int N, i, a, result = 0, arr[100];
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	scanf("%d", &a);
	for (i = 0; i < N; i++)
	{
		if (a == arr[i])
			result++;
	}

	printf("%d", result);
	return 0;
}
