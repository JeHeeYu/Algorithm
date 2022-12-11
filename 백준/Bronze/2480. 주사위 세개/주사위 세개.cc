#include <stdio.h>

int main()
{
	int a, b, c, sum = 0;
	scanf("%d %d %d", &a, &b, &c);

	if (a == b && a == c && b == c)
		sum = 10000 + a * 1000;
	else if (a == b)
		sum = 1000 + a * 100;
	else if (a == c)
		sum = 1000 + a * 100;
	else if (b == c)
		sum = 1000 + b * 100;
	else
	{
		int max = a;
		if (max < b)
			max = b;
		if (max < c)
			max = c;

		sum = max * 100;
	}
	
	printf("%d", sum);
}
	