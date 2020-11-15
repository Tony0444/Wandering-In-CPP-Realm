/*
 * Compile command: g++ -std=c++20 -o prog Concepts.cpp
 * Run command: ./prog
 * Reference: https://en.cppreference.com/w/cpp/concepts
 */

#include <iostream>
#include <concepts>

/* 
 * standard library same_as concept
 * T and U must be of same type
 */
template <typename T, std::same_as<T> U>
void foo (T t, U u)
{
	std::cout << "T and U have same type!" << std::endl;
	return;
}


/* 
 * standard library derived_from concept
 * T is derived from U
 */
template <typename T, std::derived_from<T> U>
void bar(T t, U u)
{
	std::cout << "T is derived from U!" << std::endl;
	return;
}

class Base {};
class Derived : public Base {};

int main()
{
	foo(1, 1);			// OK 		- int and int
	foo("LIONEL", "MESSI");		// OK 		- const char* and const char*
	//foo(1, "TTT");		// NOT OK 	- int and const char* are not same type!
	
	Base b;
	Derived d;

	bar(b, d); 			// OK 		- Derived is derived from Base
	//bar(d, b);			// NOT OK	- Base is not derived from Derived

	return 0;
}

