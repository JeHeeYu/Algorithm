#include <stdio.h>

int main()
{
	int N, i, j, temp = 0;
	int arr[1000];
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	for (i = 0; i < N - 1; i++)
	{
		for (j = i + 1; j < N; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (i = 0; i < N; i++)
		printf("%d\n", arr[i]);

	return 0;
}
