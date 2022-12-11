#include <stdio.h>

int main()
{
	int num, sum = 0;

	for (int i = 0; i < 5; i++) {
		scanf("%d", &num);
		if (num < 40) sum += 40;
		else sum += num;
	}
	printf("%d\n", sum / 5);
}