#include <stdio.h>

	int main()
	{
		int M, N, i, j;
		int result = 0, min = 0, sum = 0;
		scanf("%d %d", &M, &N);

		for (i = M; i <= N; i++)
		{
			for (j = 2; j <= i; j++)
			{
				if (i % j == 0)
				{
					if (i == j)
					{
						sum += i;
						result++;

						if (result == 1)
							min = i;

						break;
					}
					else
						break;
				}
			}
		}

		if (sum == 0)
			printf("-1");
		else
			printf("%d\n%d", sum, min);
		
		return 0;
	}
