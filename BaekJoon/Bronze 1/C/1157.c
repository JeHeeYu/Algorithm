#include <stdio.h>
#include <string.h>

int main()
{
	char arr[1000001];
	int cnt[26] = { 0, };
	int i, max;
	int a = 0;

	scanf("%s", arr);
	
	int len = strlen(arr);

	for (i = 0; i < len; i++)
	{
		if (arr[i] < 97)
			arr[i] += 32;
		cnt[arr[i] - 97]++;
	}

	max = cnt[0];
	
	for (i = 1; i < 26; i++)
	{
		if (max < cnt[i])
		{
			max = cnt[i];
			a = i;
		}
		else if (max == cnt[i] && cnt[i] != 0)
		{
			a = -1;
		}
	}

	if (a != -1)
		printf("%c\n", 65 + a);
	else
		printf("?\n");

	return 0;
}
