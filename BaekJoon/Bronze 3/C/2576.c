#include <stdio.h>

int main() 
{
	int i, n, sum = 0, min = 101;

	for (i = 0; i < 7; i++)
	{
		scanf("%d", &n);

		if (n % 2 != 0)
		{
			sum += n;
			if (n < min)
				min = n;
		}
	}

	if (sum == 0)
		printf("-1");
	else
		printf("%d\n%d", sum, min);
	return 0;
}
