#include <iostream>

int main()
{
	int N, M, sum = 0, min = 10001;
	int arr[10001] = { 0 };
	std::cin >> M;
	std::cin >> N;

	for (int i = 1; i <= N; i++)
		arr[i] = i * i;

	for (int i = 1; i <= N; i++)
	{
		if (M <= arr[i] && arr[i] <= N)
		{
			sum += arr[i];
			if (min > arr[i])
				min = arr[i];
		}
	}

	if (sum == 0)
		std::cout << "-1" << std::endl;

	else
	{
		std::cout << sum << std::endl;
		std::cout << min << std::endl;
	}

	return 0;
}
