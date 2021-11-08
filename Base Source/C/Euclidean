#include <stdio.h>

int Euclidean(int x, int y)
{
	if (y == 0)
		return x;
	else
	{
		return Euclidean(y, x % y);
	}

}

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d", Euclidean(x, y));
}
