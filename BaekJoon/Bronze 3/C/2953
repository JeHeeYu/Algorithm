#include <stdio.h>

int main() 
{
	int arr[5] = { 0 };
	int i, j, n, max = 0, result;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 4; j++)
		{
			scanf("%d", &n);
			arr[i] += n;
		}
	}

	for (i = 0; i < 5; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			result = i + 1;
		}
	}

	printf("%d %d", result, max);
	return 0;
}
