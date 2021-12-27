#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	for(int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)	
		{
			std::cout << " ";
		}
		std::cout << "*";

		for (int k = 0; k < 2 * i - 1; k++)
		{
			std::cout << " ";
		}

		if (i != 0)
			std::cout << "*";

		std::cout << std::endl;
	}

	for (int i = 1; i <= 2 * N - 1; i++)
	{
		std::cout << "*";
	}

	return 0;
}
