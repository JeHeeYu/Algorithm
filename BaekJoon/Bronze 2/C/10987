#include <stdio.h>
#include <string.h>

int main()
{
	char arr[101];
	char c[6] = { 'a', 'e', 'i', 'o', 'u' };
	int cnt = 0, i, j;
	scanf("%s", arr);

	int len = strlen(arr);

	for (i = 0; i < len; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (arr[i] == c[j])
				cnt++;
		}
	}

	printf("%d", cnt);
	return 0;
}
