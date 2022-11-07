#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap trap("Michel");
	trap.takeDamage(100);
	trap.attack("Patrick");
	return (0);
}
