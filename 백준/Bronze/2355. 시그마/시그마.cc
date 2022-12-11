#include <stdio.h>

int main() 
{
	long long  A, B, sum = 0;
	scanf("%lld %lld", &A, &B);

	if (A <= B)
		printf("%lld", (A + B) * (B - A + 1) / 2);
	
	else
		printf("%lld", (A + B) * (A - B + 1) / 2);

	return 0;
}