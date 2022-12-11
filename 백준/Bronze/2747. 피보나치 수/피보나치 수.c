#include <stdio.h>

int main()
{
	int n, i;
	int a = 0, b = 1, c = 0;

	scanf("%d", &n);

		if (n < 2)
		{
			if (n == 0)
				printf("0");
			else
				printf("1");
		}

		else
		{
			for (i = 1; i < n; i++)
			{
				c = a + b;
				a = b;
				b = c;
			}
			printf("%d", c);
		}
		
	return 0;
}