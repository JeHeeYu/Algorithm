#include <stdio.h>

int main()
{
	char arr[80];

	int N, i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		int sum = 0, score = 1;
		scanf("%s", arr);
		for (j = 0; j < strlen(arr); j++)
		{
			if (arr[j] == 'O')
				sum += score++;
			if (arr[j] == 'X')
				score = 1;
		}
		printf("%d\n", sum);
	}
}
