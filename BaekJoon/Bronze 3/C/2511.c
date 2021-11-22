#include <stdio.h>

int main()
{
	int i, A = 0, B = 0;
	int a[10] = { 0 };
	int b[10] = { 0 };
	char last = 'D';

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &b[i]);
	}

	for (i = 0; i < 10; i++)
	{
		if (a[i] > b[i])
		{
			A += 3;
			last = 'A';
		}
			
		else if (a[i] < b[i]) {
			B += 3;
			last = 'B';
		}
			
		else
		{
			A += 1;
			B += 1;
		}
	}
	printf("%d %d\n", A, B);

	if (A > B)
		printf("A");
	else if (A < B)
		printf("B");
	else
		printf("%c", last);

	return 0;
}
