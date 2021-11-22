#include <stdio.h>
#include <string.h>

int main()
{
	char S[101] = { 0 };
	scanf("%s", S);

	int len = strlen(S);
	int i, arr[26] = { 0 };

	for (i = 0; i < len; i++)
	{
		arr[S[i] - 97]++;
	}

	for (i = 0; i < 26; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
