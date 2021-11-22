#include <stdio.h>

int main()
{
	long long S;
	scanf("%lld", &S);

	long long  n = 0, sum = 0;

	while (1)
	{
		n++;
		sum += n;

		if (sum > S)
		{
			n--;
			break;
		}
	}
	printf("%d", n);

	return 0;
}
