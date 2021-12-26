#include <iostream>

int main()
{
	int N;
	std::cin >> N;

	for (int i = N; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
			std::cout << "*";

		std::cout << std::endl;
	}
}
