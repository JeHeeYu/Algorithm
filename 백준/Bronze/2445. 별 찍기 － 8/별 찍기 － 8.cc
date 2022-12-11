#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			std::cout << "*";
		}

		for (int k = 1; k <= (N * 2) - (i * 2); k++)
		{
			std::cout << " ";
		}

		for (int z = 1; z <= i; z++)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = N; j > i; j--)
		{
			std::cout << "*";
		}

		for (int k = 1; k <= i * 2; k++)
		{
			std::cout << " ";
		}

		for (int z = N; z > i; z--)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}
}