#include <stdio.h>

int main() 
{
	int N, i, input, score = 0, cnt = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &input);

		if (input == 1)
		{
			score += 1 + cnt;
			cnt++;
		}
		else
			cnt = 0;
	}

	printf("%d", score);

	return 0;
}
