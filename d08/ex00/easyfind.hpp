
#pragma once
#include <algorithm>
#include <iostream>

template<typename T>
typename T::iterator                    easyfind(T & arr, int num)
{
    return std::find(arr.begin(), arr.end(), num);
}
