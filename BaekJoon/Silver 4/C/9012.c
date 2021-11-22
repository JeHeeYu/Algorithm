#include <stdio.h>
#include <string.h>

int main()
{
	char arr[51];
	int T, i, j, cnt;

	scanf("%d", &T);
	
	for (i = 0; i < T; i++) 
	{
		cnt = 0;
		scanf("%s", arr);

		int len = strlen(arr);

		for (j = 0; j < len; j++) 
		{
			if (cnt < 0)
				break;
			if (arr[j] == '(')
				cnt++;
			else if (arr[j] == ')')
				cnt--;
			else if (arr[i] == ')')
			{
				cnt--;
				break;
			}
				
		}
		if (cnt == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
