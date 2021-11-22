#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int N, i, input;
	double arr[1000];
	double M = 0, sum = 0;
	scanf("%d", &N);
	
	for (i = 0; i < N; i++)
	{
		scanf("%lf", &arr[i]);
		if (M < arr[i])
			M = arr[i];
	}
	
	for (i = 0; i < N; i++)
	{
		sum += (arr[i] / M) * 100;
	}
	sum /= N;
	printf("%lf\n", sum);
}
