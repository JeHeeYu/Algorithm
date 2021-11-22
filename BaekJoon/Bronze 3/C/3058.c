#include <stdio.h>

int main() 
{
	int T, i, j, arr[7];
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		int min = 100, sum = 0;
		for (j = 0; j < 7; j++)
		{
			scanf("%d", &arr[j]);
			if (arr[j] % 2 == 0)
			{
				sum += arr[j];
				if (arr[j] % 2 == 0 && arr[j] < min)
					min = arr[j];
			}
				
		}
		printf("%d %d\n", sum, min);
	}

	return 0;
}
