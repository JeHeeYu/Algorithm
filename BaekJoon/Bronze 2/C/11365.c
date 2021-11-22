#include <stdio.h>
#include <string.h>

int main() 
{
	char arr[501] = { 0 };
	int i;

	while (1)
	{
		gets(arr);
		if (strcmp(arr, "END") == 0)
			break;

		for (i = strlen(arr) - 1; i >= 0; i--)
			printf("%c", arr[i]);
		printf("\n");
	}

	return 0;
}
