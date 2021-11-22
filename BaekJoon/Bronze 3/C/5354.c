#include <stdio.h>

int main() 
{
	int i, j, k, n, a;
	scanf("%d", &a);

	for (i = 0; i < a; i++)
	{
		scanf("%d", &n);
		for (j = 0; j < n; j++)
		{
			for (k = 0; k < n; k++)
			{
				if (j == 0 || j == n - 1)
					printf("#");

				else if (k == 0 || k == n - 1)
					printf("#");
				
				else
				printf("J");
			}	
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
