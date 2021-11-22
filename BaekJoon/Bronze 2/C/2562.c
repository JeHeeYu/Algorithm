
#include <stdio.h>

int main()
{
	int num, i, cnt;
	int max = 0;
	for (i = 1; i <= 10; i++)
	{
		scanf("%d", &num);
		
		if (max < num)
		{
			max = num;
			cnt = i;
		}
			
	}
	printf("%d\n%d", max, cnt);
}
