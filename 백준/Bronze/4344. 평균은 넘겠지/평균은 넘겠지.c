#include <stdio.h>

int main()
{
	int C, i, j, a, b;
	double arr[1000];
	scanf("%d", &C);

	double average = 0, result = 0;
	
	for (i = 0; i < C; i++)
	{
		scanf("%d", &a);
		double sum = 0, cnt = 0;
		for (j = 0; j < a; j++)
		{
			scanf("%d", &b);
			arr[j] = b;
			sum += b;
		}
		average = sum / a;

		for (j = 0; j < a; j++)
		{
			if (arr[j] > average)
			{
				cnt++;
			}
		}
		result = (cnt / a) * 100;
		printf("%.3lf%%\n", result);
	}
}