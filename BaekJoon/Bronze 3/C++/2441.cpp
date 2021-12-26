#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	for (int i = N; i > 0; i--)
	{
		for (int j = 1; j <= N - i; j++)
			std::cout << " ";
		for (int k = 1; k <= i; k++)
			std::cout << "*";

		std::cout << std::endl;
	}
}
