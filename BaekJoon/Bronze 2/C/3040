#include <stdio.h>

int main()
{
	int i, j;
	int arr[9];
	int sum = 0, sub = 0, a = 0, b = 0, temp = 0;

	for (i = 0; i < 9; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	sub = sum - 100;

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (sub == arr[i] + arr[j])
			{
				a = arr[i];
				b = arr[j];
			}
		}
	}

	for (i = 0; i < 9; i++)
	{
		for (j = i + 1; j < 9; j++)
		{
			if (arr[i] == a && arr[j] == b)
				continue;

			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	
	for (i = 0; i < 9; i++)
	{
		if(arr[i] != a && arr[i] != b)
			printf("%d\n", arr[i]);
	}
}
