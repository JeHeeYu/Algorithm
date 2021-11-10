#include <stdio.h>
#include <string.h>

int main()
{
	int N, i, j, temp;
	int max = 0;
	char c[11] = { NULL };
	
	scanf("%s", c);

	for (i = 0; i < strlen(c) - 1; i++)
	{
		for (j = i; j < strlen(c); j++)
		{
			if (c[i] < c[j])
			{
				temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	}

	for (i = 0; i < strlen(c); i++)
	{
		printf("%c", c[i]);
	}

	return 0;
}
