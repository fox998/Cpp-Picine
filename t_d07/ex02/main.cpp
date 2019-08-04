
#include    "Array.template.hpp"
#include	<iostream>
#include	<string>


int     main()
{
	Array<std::string>	a;
	Array<std::string>	b(5);

	std::cout << " b[] : ";
	for (unsigned int i = 0; i <  b.size(); i++)
	{	
		b[i] = "rand ";
		std::cout << b[i];
	}
	std::cout << std::endl;
	a = b;
	std::cout << " b[0] : " << (b[0] += "end") << std::endl;

	std::cout << " a[] : ";
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i];
}