
#include	"Peon.hpp"

Peon::Peon(){}

Peon::Peon(Peon const & copy)
{
	*this = copy;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon::Peon(std::string const & name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon &			Peon::operator=(Peon const & p)
{
	this->_name = p._name;

	return(*this);
}

void			Peon::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a pink pony !" << std::endl;
}
