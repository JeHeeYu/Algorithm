#include <stdio.h>

int main() 
{
	int a, b, c, n;

	while (1)
	{
		scanf("%d %d %d", &a, &b, &c);
		if (a == 0 && b == 0 && c == 0)
			break;

		a = a * a;
		b = b * b;
		c = c * c;

		if (a + b == c || a + c == b || b + c == a)
			printf("right\n");
		else
			printf("wrong\n");
	}

	return 0;
}
