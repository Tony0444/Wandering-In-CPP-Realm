#include <iostream>
#include <vector>
#include <ranges>

/* 
 * References:
 *   [1] https://en.cppreference.com/w/cpp/ranges
 */


int main()
{

	std::vector V{0, 1, 2, 3, 4, 5, 6, 7, 16, 17, 18, 19, 20, 21, 22, 23, 8, 9, 10, 11, 12, 13, 14, 15, 24, 25, 26, 27, 28, 29, 30, 31};
	auto even = [](int i) { return i%2 == 0; };
	auto p = [](int i) { return i < 16; };
	auto addOne = [](int i) { return i+1; };

	std::cout << "v is even:    ";
	for (auto v : V | std::views::filter(even))
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;


	std::cout << "Reverse order:    ";
	for (auto v : V | std::views::reverse | std::views::filter(even))
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;


	std::cout << "Break if v < 16:    ";
	for (auto v : V | std::views::filter(even) | std::views::take_while(p))
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;


	std::cout << "Transform v -> v + 1:    ";
	for (auto v : V | std::views::filter(even) | std::views::take_while(p) | std::views::transform(addOne))
	{
		std::cout << v << " ";
	}
	std::cout << std::endl;
	return 0;
}
