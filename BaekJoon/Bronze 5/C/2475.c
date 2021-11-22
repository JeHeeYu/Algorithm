#include <stdio.h>

int main()
{
	int i, sum = 0, result = 0;
	int arr[5];
	for (i = 0; i < 5; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i] * arr[i];
	} 

	result = sum % 10;
	
	printf("%d", result);

	return 0;
}
