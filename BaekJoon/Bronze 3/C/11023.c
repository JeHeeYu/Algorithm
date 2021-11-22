#include <stdio.h>

int main() 
{
	int sum = 0, n, i;


	while(scanf("%d", &n) != EOF)
		sum += n;

	printf("%d", sum);

	return 0;
}
