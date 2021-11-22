#include <stdio.h>

int main()
{
	int a, b, c, d, i;

	for (i = 0; i < 3; i++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);

		if (a + b + c + d == 3)
			printf("A\n");
		else if (a + b + c + d == 2)
			printf("B\n");
		else if (a + b + c + d == 1)
			printf("C\n");
		else if (a + b + c + d == 4)
			printf("E\n");
		else
			printf("D\n");
	}

	return 0;
}
