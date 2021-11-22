#include <stdio.h>

int main()
{
	int N, i, num;
	int min = 1000000;
	int max = -1000000;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		
		if (max < num)
			max = num;
		if (min > num)
			min = num;
	}
	printf("%d %d", min, max);
}
