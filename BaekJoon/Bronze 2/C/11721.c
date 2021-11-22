#include <stdio.h>

int main()
{
	char str[100] = { 0 };
	int i;

	scanf("%s", str);

	printf("%c", str[0]);

	for (i = 1; i < strlen(str); i++)
	{
		if (i % 10 == 0) printf("\n");
		printf("%c", str[i]);
	}

	return 0;
}

	
