#include <stdio.h>

int main()
{
	int N, K, i;
	int arr[10000];
	int cnt = 0;
	scanf("%d %d", &N, &K);

	for (i = 1; i <= N; i++)
	{
		if (N % i == 0)
		{
			arr[cnt] = i;
			cnt++;
		}
	}

	if (arr[K - 1] < 1)
		printf("0");
	else
		printf("%d", arr[K - 1]);
	return 0;
}
 