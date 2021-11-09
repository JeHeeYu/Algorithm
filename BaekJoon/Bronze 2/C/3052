#include <stdio.h>

int main()
{
	int arr[10];
	int i, j;
	int input, result = 0;

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		arr[i] %= 42;

	}
	
	for (i = 0; i < 10; i++)
	{
		int cnt = 0;
		for (j = i + 1; j < 10; j++)
		{
			if (arr[i] == arr[j]) cnt++;
		}
		if (cnt == 0) result++;
	}
	printf("%d", result);
}
