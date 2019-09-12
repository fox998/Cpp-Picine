

#include <string>
#include <iostream>

static const std::string str = "HI THIS IS BRAIN";

int main()
{
    std::string const& ref = str;
    std::string const* ptr = &str;


    std::cout << "ref : " << ref << "\n";
    std::cout << "ptr : " << *ptr << "\n"; 
}