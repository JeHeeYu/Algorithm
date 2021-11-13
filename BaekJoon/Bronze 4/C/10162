#include <stdio.h>

int main()
{
	int A = 0, B = 0, C = 0, T;
	scanf("%d", &T);

	while (T >= 0)
	{
		if (T >= 300)
		{
			T -= 300;
			A++;
		}
		else if (T >= 60)
		{
			T -= 60;
			B++;
		}
		else if (T >= 10)
		{
			T -= 10;
			C++;
		}
		else
			break;
	}

	if (T == 0)
	{
		printf("%d %d %d", A, B, C);
	}
	else
		printf("-1");

	return 0;
}
