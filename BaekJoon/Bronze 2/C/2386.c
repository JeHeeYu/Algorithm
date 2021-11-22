#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	char c, arr[251];
	int i, j;

	while (1)
	{
		int cnt = 0;
		scanf("%[^\n]", arr);
		getchar();

		if (arr[0] == '#')
			break;

		for (i = 1; i < strlen(arr); i++)
		{
			if (arr[i] >= 65 && arr[i] <= 90)
				arr[i] += 32;

			if (arr[0] == arr[i])
				cnt++;
		}

		printf("%c %d\n", arr[0], cnt);
	}
}
