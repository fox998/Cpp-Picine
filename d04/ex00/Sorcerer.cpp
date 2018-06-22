
#include	"Sorcerer.hpp"

Sorcerer::Sorcerer(){}

Sorcerer::~Sorcerer()
{
	std::cout << this->_name + ", " << this->_titel + ", ";
	std::cout << "is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & copy)
{
	*this = copy;
}

Sorcerer::Sorcerer(std::string const & name, std::string const & titel)
{
	this->_name = name;
	this->_titel = titel;
	std::cout << this->_name + ", " << this->_titel + ", ";
	std::cout << "is born !" << std::endl;
}

Sorcerer &				Sorcerer::operator=(Sorcerer const & s)
{
	this->_name = s._name;
	this->_titel = s._titel;

	return (*this);
}

void					Sorcerer::polymorph(Victim const & v)
{
	v.getPolymorphed();
}

std::string const &		Sorcerer::getName()
{
	return(this->_name);
}

std::string const &		Sorcerer::getTitel()
{
	return(this->_titel);
}

std::ostream &			operator<<(std::ostream & o, Sorcerer & s)
{
	o << "I am " + s.getName() + ", ";
	o << s.getTitel() + ", and I like ponies !" << std::endl;

	return (o);
}
