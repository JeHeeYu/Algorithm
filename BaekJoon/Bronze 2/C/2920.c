#include <stdio.h>

int main()
{
	int arr[8] = { 0 };
	int i, as = 0, des = 0, mix = 0;

	for (i = 0; i < 8; i++)
	{
		scanf("%d", &arr[i]);

		if (i + 1 == arr[i])
			as++;
		else if (8 - i == arr[i])
			des++;
		else
			mix++;
	}

	if (as == 8)
		printf("ascending");
	else if (des == 8)
		printf("descending");
	else
		printf("mixed");

	return 0;
}
