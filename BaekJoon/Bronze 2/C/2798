#include <stdio.h>

int main()
{
	int N, M, i, j, k;
	int result = 0, max = 0;
	int arr[100] = { 0 };
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < N; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			for (k = j + 1; k < N; k++)
			{
				result = arr[i] + arr[j] + arr[k];
				if (result > max && result <= M)
					max = result;
			}
		}
	}
	printf("%d", max);

	return 0;
}
