#include <iostream>
#include <array>

void Print(std::array<int, 5> arr)
{
	for (auto ele : arr)
		std::cout << ele << ", ";
}

int main()
{
	std::array<int, 10> arr1;

	arr1[0] = 1;
	std::cout << "arr1 배열의 첫 번째 원소 : " << arr1[0] << std::endl;

	std::array<int, 4> arr2 = { 1, 2, 3, 4 };
	std::cout << "arr2의 모든 원소 : ";

	for (int i = 0; i < arr2.size(); i++)
		std::cout << arr2[i] << " ";
	
	std::cout << std::endl;

	// at() 함수를 사용하여 예외처리 가능
	std::array<int, 4> arr3 = { 1, 2, 3, 4 };
	try
	{
		std::cout << arr3.at(3) << std::endl;
		std::cout << arr3.at(4) << std::endl;
	}

	catch (const std::out_of_range& ex)
	{
		std::cerr << ex.what() << std::endl;
	}

	// 함수에 매개변수로 전달 가능
	std::array<int, 5> arr4 = { 1, 2, 3, 4, 5 };
	std::cout << "arr4의 원소 : ";
	Print(arr4);
	std::cout << std::endl;

	// 일반 for문을 사용할 경우 배열의 크기를 정확하게 지정하지 않으면 에러가 발생함
	std::array<int, 5> arr5 = { 1, 2, 3, 4, 5 };
	std::cout << "arr5의 원소 : ";
	for (auto element : arr5)
		std::cout << element << " ";
	std::cout << std::endl;

	// begin() 함수는 첫 번째 원소의 위치, end() 함수는 마지막 원소 다음을 가리키는 함수로  이 함수를 이용하여 반복문 사용 가능
	std::array<int, 5> arr6 = { 1, 2, 3, 4, 5 };
	std::cout << "arr6의 원소 : ";
	for (auto it = arr6.begin(); it != arr6.end(); it++)
	{
		auto element = (*it);
		std::cout << element << ' ';
	}
	std::cout << std::endl;

	// front() 함수는 배열의 첫 번째 원소, end() 함수는 배열의 마지막 원소
	// data() 함수는 배열 객체 내부에서 실제 데이터 메모리 버퍼를 가리키는 포인ㅌ ㅓ반환
	std::array<int, 5> arr7 = { 1, 2, 3, 4, 5 };
	std::cout << "arr7의 원소 : ";
	std::cout << arr7.front() << " ";
	std::cout << arr7.back() << " ";
	std::cout << *(arr7.data() + 1) << std::endl;
}
