#include <iostream>
#include <string>

void	memoryLeak()
{
	std::string const* const panthere = new std::string("String panthere");

	std::cout << *panthere << std::endl;

	delete panthere;
}