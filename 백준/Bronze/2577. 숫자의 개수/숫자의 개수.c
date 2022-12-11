#include <stdio.h>

int main()
{
	int A, B, C, i;
	int sum = 0;
	scanf("%d %d %d", &A, &B, &C);
	sum = A * B * C;
	
	int arr[10] = { 0 };

	while (sum > 0)
	{
		arr[sum % 10]++;
		sum /= 10;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}
}