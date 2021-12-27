#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			std::cout << " ";
		}

		for (int k = N * 2; k >= i * 2; k--)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = N - 1; j > i; j--)
		{
			std::cout << " ";
		}

		for (int k = 1; k <= i * 2 + 1; k++)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}
}
