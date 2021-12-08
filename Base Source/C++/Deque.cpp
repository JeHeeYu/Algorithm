#include <iostream>
#include <deque>

template <typename T>
void PrintDeque(std::deque<T>& dq)
{
	std::cout << "[ ";

	for (const auto& elem : dq)
		std::cout << elem << " ";

	std::cout << "]" << std::endl;
}

int main()
{
	std::deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);
	dq.push_back(40);

	std::cout << "초기 dq 상태" << std::endl;
	PrintDeque(dq);

	std::cout << "맨 앞의 원소 제거" << std::endl;
	dq.pop_front();
	PrintDeque(dq);

	std::cout << "맨 뒤의 원소 제거" << std::endl;
	dq.pop_back();
	PrintDeque(dq);

	return 0;
}
