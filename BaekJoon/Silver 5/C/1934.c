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
	int T, i;
	int result = 0, n = 0;
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", LCM(a, b));
	}

	return 0;
}
