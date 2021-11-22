#include <stdio.h>

int main()
{
	int n, i, x = 0, y = 0;
	
	for(i = 0; i < 4; i++)
	{
		scanf("%d", &n);
		y += n;
	}
	
	while(1)
	{
		if(y < 60)
			break;
		y -= 60;
		x++;
	}
	printf("%d\n%d", x, y);
}
