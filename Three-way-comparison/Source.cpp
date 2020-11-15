/*
 * Defaulting <=> should automatically give ==, !=, >, <, >=, <= operators
 * Compile command: g++ -std=c++20 -o prog Concepts.cpp
 * Run command: ./prog
 * References: 	[1] https://en.cppreference.com/w/cpp/language/default_comparisons
 * 		[2] https://en.cppreference.com/w/cpp/language/operator_comparison#Three-way_comparison
 */


#include <iostream>
#include <compare>

struct MyInt
{
	int value;
	MyInt(int val) : value(val) {}
	auto operator<=>(const MyInt& other) const = default;
};


int main()
{
	MyInt Five(5);
	MyInt Two(2);

	if (Five < Two)
		std::cout << "5 < 2" << std::endl;
	else 
		std::cout << "5 >= 2" << std::endl;

	if (Five == Two)
		std::cout << "5 == 2" << std::endl;
	else 
		std::cout << "5 != 2" << std::endl;

	if (Five >= Two)
		std::cout << "5 >= 2" << std::endl;
	else 
		std::cout << "5 < 2" << std::endl;

	return 0;
}
