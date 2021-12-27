#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = N; j > i; j--)
		{
			std::cout << " ";
		}

		for (int k = 1; k <= i; k++)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			std::cout << " ";
		}

		for (int k = N; k > i; k--)
		{
			std::cout << "*";
		}

		std::cout << std::endl;
	}
}
