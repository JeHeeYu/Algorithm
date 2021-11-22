#include <stdio.h>

int main() 
{
	int n, i, a, b, result = 0, dad = 0;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &a, &b);

		result = a / b;
		dad = a % b;

		printf("You get %d piece(s) and your dad gets %d piece(s).\n", result, dad);
	}

	return 0;
}
