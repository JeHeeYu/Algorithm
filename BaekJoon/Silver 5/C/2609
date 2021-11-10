#include <stdio.h>

int GCD(int x, int y)
{
	if (y == 0)
		return x;
	else
	{
		return GCD(y, x % y);
	}

}

int LCM(int x, int y)
{
	return x * y / GCD(x, y);
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%d\n", GCD(a, b));
	printf("%d\n", LCM(a, b));

	return 0;
}
