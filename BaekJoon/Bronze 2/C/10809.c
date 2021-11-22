#include <stdio.h>

int main()
{
	char arr[100];
	int i, j;

	scanf("%s", &arr);
	
	for (i = 'a'; i <= 'z'; i++)
	{
		int cnt = 0;
		
		for (j = 0; j < strlen(arr); j++)
		{
			if (arr[j] == i)
			{
				printf("%d ", j);
				cnt++;
				break;
			}
		}
		if (cnt == 0) printf("-1 ");
	}
	return 0;
}
