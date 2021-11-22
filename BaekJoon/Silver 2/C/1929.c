#include <stdio.h>

int arr[1000001];

int main() 
{
	int N, M, i, j;
	arr[1] = 1;
	scanf("%d %d", &M, &N);

	for (i = 2; i <= N; i++)
		for (j = 2; i * j <= N; j++)
			arr[i * j] = 1;

	for (int i = M; i <= N; i++)
		if (arr[i] == 0)
			printf("%d\n", i);

	return 0;
}
