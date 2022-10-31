#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap trap("clap1");
	ClapTrap trap3("clap3");

	for (int i = 0; i < 7; i++)
	{
		trap.attack("clap2");
		trap.beRepaired(1);
	}
	for (int i = 0; i < 5; i++)
		trap3.takeDamage(i);
	return (0);
}