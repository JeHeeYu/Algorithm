#include <stdio.h>

int main() 
{
	int N, i, j, input, cnt = 0, flags;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &input);
		flags = 0;

		if (input == 1)
			continue;

		for (j = 2; j < input; j++)
		{
			if (input % j == 0)
				flags = 1;
		}
		if (flags == 0)
			cnt++;
	}
	printf("%d", cnt);

	return 0;
}
