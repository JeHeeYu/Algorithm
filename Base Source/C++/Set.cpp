#include <iostream>
#include <set>

template <typename T>
void PrintSet(std::set<T>& s)
{
	std::cout << "[ ";
	for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr)
		std::cout << *itr << " ";

		std::cout << " ] " << std::endl;
}

int main()
{
	std::set<int> s;
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);
	s.insert(30);
	s.insert(10);
	s.insert(50);
	s.insert(20);
	s.insert(40);
	s.insert(30);

	// 셋은 입력 순서와 상관없이 순서대로 정렬되며,
	// 중복된 원소는 저장되지 않음
	std::cout << "순서대로 정렬되어 출력" << std::endl;
	PrintSet(s);


	std::cout << "find 함수 20 검색 : ";
	auto itr = s.find(20);
	
	if (itr != s.end())
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	return 0;
}
