
#include    "easyfind.hpp"
#include    <vector>
#include    <list>
#include    <iostream>

int     main()
{
    std::vector<float>    arr (5);
    std::list<int>      lst;

    arr[0] = 42;
    arr[1] = 43;
    arr[2] = 44;
    arr[3] = 45;
    arr[4] = 46;


    lst.push_back(0);
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    lst.push_back(50);

    std::cout << (easyfind(lst, 42) == lst.end()) << " " << *easyfind(lst, 10) << std::endl;
    std::cout << (easyfind(arr, 10) == arr.end()) << " " << *easyfind(arr, 42) << std::endl;

    lst.erase(easyfind(lst, 10));
    arr.erase(easyfind(arr, 42));

    std::cout << (easyfind(lst, 10) == lst.end())  << std::endl;
    std::cout << (easyfind(arr, 42) == arr.end())  << std::endl;
}