#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _hit_points(100), _energy_points(50), _attack_damage(30), _name("default")
{
	std::cout << "ClapTrap default constructor called." << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string const &name): _hit_points(100), _energy_points(50), _attack_damage(30), _name(name)
{
	std::cout << "ClapTrap string constructor called." << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &to_copy)
{
	*this = to_copy;
	std::cout << "ClapTrap copy constructor called." << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called." << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_attack_damage = rhs._attack_damage;
	this->_energy_points = rhs._energy_points;
	this->_hit_points = rhs._hit_points;
	this->_name = rhs._name;
	return (*this);
}

void ClapTrap::attack(std::string const &target)
{
	if (!this->_hit_points || !this->_energy_points)
		return ;
	this->_energy_points--;
	if (this->_attack_damage >= this->_hit_points)
		this->_hit_points = 0;
	else
		this->_hit_points -= this->_attack_damage;
	std::cout << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage !" << std::endl;
	if (!this->_hit_points || !this->_energy_points)
		std::cout << this->_name << " died." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_hit_points || !this->_energy_points)
		return ;
	this->_attack_damage = amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_hit_points || !this->_energy_points)
		return ;
	this->_energy_points--;
	this->_hit_points += amount;
	if (!this->_energy_points)
		std::cout << this->_name << " died." << std::endl;
}
