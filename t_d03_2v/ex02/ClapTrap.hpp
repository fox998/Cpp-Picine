
#ifndef		CLAPTRAP_HPP
# define	CLAPTRAP_HPP

#include	<string>

class	ClapTrap
{
	protected:
		std::string		_name;
		int				_hitPoints;
		int				_maxHitPoints;
		int				_energyPoints;
		int				_maxEnergyPoints;
		int				_level;
		int				_meleeAttackDamege;
		int				_rangedAttackDamege;
		int				_armorDamageReduction;

	private:
		void			_outputNameOfClass();

	public:
		~ClapTrap();
		ClapTrap();
		ClapTrap(std::string const & name);
		ClapTrap(ClapTrap const & copy);
			
		ClapTrap &		operator=(ClapTrap const & ft);

		void			rangedAttack(std::string const & target);
		void			meleeAttack(std::string const & target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
};

#endif