#ifndef __CLAP_TRAP_HPP__
# define __CLAP_TRAP_HPP__

#include <iostream>

class ClapTrap {
	public:
		ClapTrap( std::string const name );
		ClapTrap( ClapTrap const &to_copy );
		~ClapTrap( void );

		ClapTrap & operator=(ClapTrap const &to_copy);

		void	attack(std::string const &target);
		void	takeDamage(unsigned int amout);
		void	beRepaired(unsigned int amout);

	private:
		std::string				_name;
		unsigned int			_hit_points;
		unsigned int			_energy_points;
		unsigned int			_attack_damage;
};

#endif