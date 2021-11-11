#include <stdio.h>

int main()
{
	int N;
	int cnt = 0;

	scanf("%d", &N);

	while (N > 0)
	{
		if (N % 5 == 0)
		{
			N -= 5;
			cnt++;
		}

		else if (N % 3 == 0)
		{
			N -= 3;
			cnt++;
		}

		else if (N > 5)
		{
			N -= 5;
			cnt++;
		}
		else
		{
			cnt = -1;
			break;
		}
	}

	printf("%d", cnt);

	return 0;
}
