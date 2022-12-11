int arr[10001];

int main()
{
	int N, i, j, a;
	
	scanf("%d", &N);
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a);
		arr[a]++;
	}

	for (i = 1; i <= 10000; i++)
	{
		for (j = 0; j < arr[i]; j++)
			printf("%d\n", i);
	}

	return 0;
}