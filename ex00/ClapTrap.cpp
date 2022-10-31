#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hit_points(10),
	_energy_points(10), _attack_damage(0)
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const &to_copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_copy;
	return ;
}

ClapTrap::~ClapTrap( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &to_copy)
{
	std::cout << "Copy operator overload called" << std::endl;
	this->_name = to_copy._name;
	this->_hit_points = to_copy._hit_points;
	this->_energy_points = to_copy._energy_points;
	this->_attack_damage = to_copy._attack_damage;
	return (*this);
}

// FUNCTION MEMBERS

void	ClapTrap::takeDamage(unsigned int amout)
{
	if (!this->_hit_points || !this->_energy_points)
	{
		std::cout << this->_name << " is dead" << std::endl;
		return ;
	}
	else if (amout >= this->_hit_points)
	{
		this->_hit_points = 0;
		std::cout << this->_name << " died" << std::endl;
		return ;
	}
	this->_hit_points -= amout;
	std::cout << this->_name << " took " << amout << " points of damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amout)
{
	if (!this->_hit_points || !this->_energy_points)
	{
		std::cout << this->_name << " is dead" << std::endl;
		return ;
	}
	this->_hit_points += amout;
	--this->_energy_points;
	if (!this->_energy_points)
		std::cout << this->_name << " died" << std::endl;
	else
		std::cout << this->_name << " got back " << amout << " hit points" << std::endl;
}

void	ClapTrap::attack(std::string const &target)
{
	if (!this->_hit_points || !this->_energy_points)
	{
		std::cout << this->_name << " is dead" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks "
		<< target << ", causing " << this->_attack_damage
		<< " points of damage !" << std::endl;
	this->_attack_damage = 0;
	--this->_energy_points;
}
