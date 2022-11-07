#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap clap("Michel");

	clap.attack("Patrick");
	for (int i = 0; i < 20; i++)
		clap.beRepaired(1);
	clap.attack("Patrick");
	return (0);
}
