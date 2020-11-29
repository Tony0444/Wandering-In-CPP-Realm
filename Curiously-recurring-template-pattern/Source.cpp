#include <iostream>
#include <bitset>

/* 
 * References:
 *   [1] https://en.cppreference.com/w/cpp/language/crtp
 *
 * Notes:
 *   [1] CRTP may be used to resolve polymorphism at compile-time!
 */

template <class T>
struct Printer
{
	void print(int n) 
	{
		static_cast<T*>(this)->printImpl(n); 
	}
};


struct BinPrinter : public Printer<BinPrinter>
{
	void printImpl(int n)
	{
		std::cout << "Binary format: " << std::bitset<8>(n) << std::endl;
	}
};


struct HexPrinter : public Printer<HexPrinter>
{
	void printImpl(int n) 
	{
		std::cout << "Hex format: " << std::hex << n << std::endl;
	}
};


int main()
{

	HexPrinter H;
	BinPrinter B;
	std::cout << "Decimal format: " << 10 << std::endl;
	H.print(10);
	B.print(10);
	return 0;
}

