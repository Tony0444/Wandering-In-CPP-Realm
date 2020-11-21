#include <iostream>
#include <cassert>

/* 
 * Topic: 
 * 	fold expression[1]
 *	parameter pack [2]
 *
 * Sources:
 *	 [1] https://en.cppreference.com/w/cpp/language/fold
 *	 [2] https://en.cppreference.com/w/cpp/language/parameter_pack
 */

template <typename ...T>
auto sum(T ...args)
{
	return (args + ...);
}

template <typename ...U>
auto Is_ascending(U ...args)
{
	return (... < args);
}

template <typename ...U>
auto Is_descending(U ...args)
{
	return (... > args);
}

int main()
{
	assert(sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) == 55);	// OK
	assert(sum(1.0, 3.1, 4) == 8.1);			// OK
	assert((sum(1, 1) == 3) == false);			// NOT OK! 2 != 3

	assert(Is_ascending(1, 3, 5, 9));			// OK
	assert(Is_descending(1, 3, 5, 9) == false);		// NOT OK
	return 0;
}

