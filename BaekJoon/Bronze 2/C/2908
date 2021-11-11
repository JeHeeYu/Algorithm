#include <stdio.h>

int main()
{
	int A, B, a = 0, b = 0;
	scanf("%d %d", &A, &B);

		a += (A % 10) * 100;
		A /= 10;
		a += (A % 10) * 10;
		A /= 10;
		a += A % 10;

		b += (B % 10) * 100;
		B /= 10;
		b += (B % 10) * 10;
		B /= 10;
		b += B % 10;

		if (a > b)
			printf("%d", a);
		else
			printf("%d", b);

	return 0;
}
