#include <stdio.h>

int main()
{
	int n, sum = 0;
	int i;

	char arr[100] = { 0, };

	scanf("%d", &n);
	scanf("%s", &arr);

	for (i = 0; i < n; i++)
	{
		sum += arr[i] - '0';
	}

	printf("%d", sum);

	return 0;
}
