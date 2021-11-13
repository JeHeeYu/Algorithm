#include <stdio.h>

int Min(int x, int y);
int Result(int data);

int arr[1000001];

int main()
{
	int N;
	scanf("%d", &N);

	printf("%d", Result(N));
	
	return 0;
}

int Min(int x, int y)
{
	return x > y ? y : x;
}

int Result(int data)
{
	int i;

	for (i = 2; i <= data; i++)
	{
		arr[i] = arr[i - 1] + 1;
		if (i % 2 == 0)
			arr[i] = Min(arr[i], arr[i / 2] + 1);
		if (i % 3 == 0)
			arr[i] = Min(arr[i], arr[i / 3] + 1);
	}

	return arr[data];
}
