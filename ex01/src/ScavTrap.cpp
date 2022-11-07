#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap default constructor called." << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string const &name): ClapTrap(name)
{
	std::cout << "ScavTrap string constructor called." << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &to_copy): ClapTrap()
{
	*this = to_copy;
	std::cout << "ScavTrap copy constructor called." << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called." << std::endl;
	return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	*this = rhs;
	return (*this);
}

void ScavTrap::guardGate(void) const
{
	std::cout << this->_name << " entered in Gate Keeper mode." << std::endl;
}

void ScavTrap::attack(std::string const &target)
{
	if (!this->_hit_points || !this->_energy_points)
		return ;
	this->_energy_points--;
	if (this->_attack_damage >= this->_hit_points)
		this->_hit_points = 0;
	else
		this->_hit_points -= this->_attack_damage;
	std::cout << "ScavTrap: " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage !" << std::endl;
	if (!this->_hit_points || !this->_energy_points)
		std::cout << this->_name << " died." << std::endl;
}
