#include <stdio.h>

int main() 
{
	int arr[9][9];
	int i, j, max = 0;
	int a = 0, b = 0, result = 0;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			scanf("%d", &arr[i][j]);
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				result = max;
				a = i + 1;
				b = j + 1;
			}
		}
	}
	printf("%d\n%d %d", result, a, b);
}
