int main()
{
	int n, i, j;
	int change = 0, money = 1000;
	int arr[6] = { 500, 100, 50, 10, 5, 1 };
	scanf("%d", &n);

	money -= n;

	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (money == 0)
				break;

			if (money % arr[i] == 0)
			{
				money -= arr[i];
				change++;
			}

			else if (money > arr[i])
			{
				money -= arr[i];
				change++;
			}
		}
	}
	printf("%d", change);

	return 0;
}
