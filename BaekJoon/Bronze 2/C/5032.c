#include <stdio.h>

int main() 
{
	int e, f, c, result = 0;
	scanf("%d %d %d", &e, &f, &c);

	int empty = e + f;

	while (empty >= c)
	{
		result += empty / c;
		empty = empty / c + empty % c;
	}

	printf("%d", result);
	
	return 0;
}
