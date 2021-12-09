#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>

void PrintMap(std::map<K, V>& m)
{
	for (auto itr = m.begin(); itr != m.end(); ++itr)
		std::cout << itr->first << " " << itr->second << std::endl;
}

template <typename K, typename V>
void SearchPrint(std::map<K, V>& m, K key)
{
	auto itr = m.find(key);
	if (itr != m.end())
		std::cout << key << " --> " << itr->second << std::endl;
	else
		std::cout << key << " X " << std::endl;
}

int main()
{
	std::map<std::string, double> pitcher_list;

	pitcher_list["오승환"] = 3.58;

	PrintMap(pitcher_list);
	std::cout << "================" << std::endl;

	SearchPrint(pitcher_list, std::string("오승환"));
	SearchPrint(pitcher_list, std::string("류현진"));
}
