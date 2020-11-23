#include <iostream>
#include <array>
#include <utility>

/* 
 * References:
 *   [1] https://en.cppreference.com/w/cpp/language/fold
 *   [2] https://en.cppreference.com/w/cpp/language/parameter_pack
 */


template <typename ...T>
auto sum(T ...args)
{
    return (args + ...);
}

template <typename T, std::size_t ...Is>
auto sum(T t, std::index_sequence<Is...>)
{
    return sum(t[Is]...);
}

int main()
{
    std::array<int, 3> a1 = {1, 4, 3};
    int a2[5] = {1, 2, 3, 4, 0};

    std::cout << "Sum a1 = " << sum(a1, std::make_index_sequence<a1.size()>{}) << "\n";
    std::cout << "Sum a2 = " << sum(a2, std::make_index_sequence<5>{}) << "\n";
    return 0;
}
