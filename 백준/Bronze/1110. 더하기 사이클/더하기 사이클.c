#include <stdio.h>

int main()
{
	int	 N, a, b, c, d, result;
	int cnt = 0;

	scanf("%d", &N);
	result = N;

	while (1)
	{
		a = N / 10;
		b = N % 10;
		c = (a + b) % 10;
		d = (b * 10) + c;

		N = d;
		cnt++;

		if (d == result) break;

	}
	printf("%d", cnt);
}