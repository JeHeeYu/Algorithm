#include <stdio.h>

int main() 
{
	int n, i, a = 100, b = 100, c, d;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &c, &d);

		if (c > d)
			b -= c;
		else if (c < d)
			a -= d;
		else
			continue;
	}

	printf("%d %d", a, b);

	return 0;
}
