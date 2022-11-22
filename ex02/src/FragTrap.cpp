#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &rhs): ClapTrap()
{
	*this = rhs;
	std::cout << "FragTrap copy constructor called." << std::endl;
	return ;
}

FragTrap::FragTrap(std::string const &name): ClapTrap(name)
{
	std::cout << "FragTrap string constructor called." << std::endl;
	return ;
}

FragTrap::~FragTrap(void)
{
	if (!this->_hit_points || !this->_energy_points)
		std::cout << this->_name << " died." << std::endl;
	std::cout << "FragTrap destructor called." << std::endl;
	return ;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_attack_damage = rhs._attack_damage;
	this->_energy_points = rhs._energy_points;
	this->_hit_points = rhs._hit_points;
	this->_name = rhs._name;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "Let's have a high five !" << std::endl;
}