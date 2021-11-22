#include <stdio.h>

int Result(int data);

int arr[1001];

int main()
{
	int n, i;
	scanf("%d", &n);

	arr[0] = 1;
	arr[1] = 1;

	printf("%d", Result(n));
	
	return 0;

}

int Result(int data)
{
	int i;
	
	for (i = 2; i <= data; i++)
	{
		arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
	}
	
	return arr[data];
}
