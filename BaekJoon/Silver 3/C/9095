#include <stdio.h>

int arr[11];

int main()
{
	int i, T, n;
	scanf("%d", &T);
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;

	for (i = 4; i < 11; i++)
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];

	for (i = 0; i < T; i++)
	{
		scanf("%d", &n);
		printf("%d\n", arr[n]);
	}

	return 0;
}
