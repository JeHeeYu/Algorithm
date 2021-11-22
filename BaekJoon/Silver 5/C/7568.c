#include <stdio.h>

int main()
{
	int N, i, j, cnt;
	int x[50] = { 0, };
	int y[50] = { 0, };

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &x[i], &y[i]);
	}
	
	for (i = 0; i < N; i++)
	{
		cnt = 0;
		for (j = 0; j < N; j++)
		{
			if (x[i] < x[j] && y[i] < y[j])
				cnt++;
		}
		printf("%d ", cnt + 1);
	}

	return 0;
}
