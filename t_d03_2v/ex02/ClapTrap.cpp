
#include	"ClapTrap.hpp"
#include	<iostream>
ClapTrap::~ClapTrap()
{
	this->_outputNameOfClass();
	std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap():	_name("-"),
						_hitPoints(100),
						_maxHitPoints(100),
						_level(1)
{
	this->_outputNameOfClass();
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name):	_name(name),
												_hitPoints(100),
												_maxHitPoints(100),
												_level(1)
{
	this->_outputNameOfClass();
	std::cout << "Name set constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & copy)
{
	this->_outputNameOfClass();
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

void				ClapTrap::_outputNameOfClass()
{
	std::cout << "ClapTrap :";
}

ClapTrap &			ClapTrap::operator=(ClapTrap const & ft)
{
	this->_outputNameOfClass();
	std::cout << "Assignation operator called" << std::endl;
	this->_name  = ft._name;
	this->_hitPoints = ft._hitPoints;
	this->_maxHitPoints = ft._maxHitPoints;
	this->_energyPoints = ft._energyPoints;
	this->_maxEnergyPoints = ft._maxEnergyPoints;
	this->_level = ft._level;
	this->_meleeAttackDamege = ft._meleeAttackDamege;
	this->_rangedAttackDamege = ft._rangedAttackDamege;
	this->_armorDamageReduction = ft._armorDamageReduction;

	return (*this);
}

void				ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << this->_name;
	std::cout << " attacks " << target;
	std::cout << " range, causing " << this->_rangedAttackDamege;
	std::cout << " points of damage !" << std::endl;
}

void				ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << this->_name;
	std::cout << " attacks " << target;
	std::cout << " melee, causing " << this->_rangedAttackDamege;
	std::cout << " points of damage !" << std::endl;
}

void				ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << this->_name;
	std::cout << " : My robotic flesh get" << amount;
	this->_hitPoints = std::max(this->_hitPoints - (int)amount, 0);
	std::cout << " points of demage! AAHH! My health : " << this->_hitPoints << std::endl;
}

void				ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << this->_name;
	std::cout << " : I found " << amount << " hit points! ";
	this->_hitPoints = std::min(this->_hitPoints + (int)amount, this->_maxHitPoints);
	std::cout << "My health : " << this->_hitPoints << std::endl;
}
