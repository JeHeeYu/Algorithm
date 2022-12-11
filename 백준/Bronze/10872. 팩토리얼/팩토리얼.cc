#include <stdio.h>

int Factorial(int n)
{
	if (n < 2)
		return 1;
	else
		return Factorial(n - 1) *  n;
}

int main() 
{
	int N;
	scanf("%d", &N);
	printf("%d", Factorial(N));

}