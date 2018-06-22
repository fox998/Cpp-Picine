
#include	"Victim.hpp"

Victim::~Victim()
{
	std::cout << "Victim " << this->_name;
	std::cout << " just died for no apparent reason !" << std::endl;
}

Victim::Victim(){}

Victim::Victim(std::string const & name) : _name(name)
{
	std::cout << "Some random victim called " << this->_name;
	std::cout << " just popped !" << std::endl;
}

Victim::Victim(Victim const & copy)
{
	*this = copy;
}

Victim &			Victim::operator=(Victim const & v)
{
	this->_name = v._name;

	return (*this);
}

void				Victim::getPolymorphed() const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream &		operator<<(std::ostream & o, Victim const & v)
{
	std::cout << "I'm " + v.getName() +  "and I like otters !" << std::endl;

	return (o);
}

std::string const &		Victim::getName() const
{
	return (this->_name);
}
