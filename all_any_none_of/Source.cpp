#include <iostream>
#include <vector>
#include <algorithm>

/* 
 * References:
 *   [1] https://en.cppreference.com/w/cpp/algorithm/all_any_none_of
 */


int main()
{
	std::vector V {1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto allEven = [&](const auto& i){ return i%2 == 0; };
	auto equalFive = [&](const auto& i){ return i == 5; };
	auto biggerThanTen = [&](const auto& i){ return i > 10; };


	std::cout << std::boolalpha << "All even? " << std::all_of(V.begin(), V.end(), allEven) << std::endl;
	std::cout << std::boolalpha << "No element > 10? " << std::none_of(V.begin(), V.end(), biggerThanTen) << std::endl;
	std::cout << std::boolalpha << "Any element == 5?  " << std::any_of(V.begin(), V.end(), equalFive) << std::endl;
	return 0;
}

