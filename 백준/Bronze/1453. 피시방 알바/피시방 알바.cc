#include <iostream>

int main()
{
	int N, M, cnt = 0;
	int arr[101] = { 0, };
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> M;
		arr[M]++;

		if (arr[M] > 1)
			cnt++;
	}

	std::cout << cnt;

	return 0;

}