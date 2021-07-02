#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main() {
	FragTrap f1("Leonid");
	FragTrap f2("Dinoel");
	srand(time(NULL));

	f2.meleeAttack(f1.getName());
	f1.takeDamage(f2.getMeleeDamage());
	std::cout << f1.getHitPoints() << "|||\n";

	f1.vaulthunter_dot_exe(f2.getName());
	f1.vaulthunter_dot_exe(f2.getName());
	f1.vaulthunter_dot_exe(f2.getName());
	f1.vaulthunter_dot_exe(f2.getName());
	f1.vaulthunter_dot_exe(f2.getName());
	f1.vaulthunter_dot_exe(f2.getName());

	f1.meleeAttack(f2.getName());
	f2.takeDamage(f1.getMeleeDamage());
	std::cout << f2.getHitPoints() << "|||\n";

	f1.rangedAttack(f2.getName());
	f2.takeDamage(f1.getRangeDamage());
	std::cout << f2.getHitPoints() << "|||\n";

	f2.beRepaired(20);
	std::cout << f2.getHitPoints() << "|||\n";

	f1.meleeAttack(f2.getName());
	f2.takeDamage(f1.getMeleeDamage());
	std::cout << f2.getHitPoints() << "|||\n";

	f1.rangedAttack(f2.getName());
	f2.takeDamage(f1.getMeleeDamage());
	std::cout << f2.getHitPoints() << "|||\n";

	f1.meleeAttack(f2.getName());
	f2.takeDamage(f1.getMeleeDamage());
	std::cout << f2.getHitPoints() << "|||\n";

	f1.meleeAttack(f2.getName());
	f2.takeDamage(f1.getMeleeDamage());
	std::cout << f2.getHitPoints() << "|||\n";
	
	ScavTrap s1("Scav");
	ScavTrap s2("Vacs");
	
	s1.challengeNewcomer();
	s1.challengeNewcomer();
	s1.challengeNewcomer();

	s2.meleeAttack(s1.getName());
	s1.takeDamage(s2.getMeleeDamage());

	s2.rangedAttack(s1.getName());
	s1.takeDamage(s2.getMeleeDamage());

	s2.meleeAttack(s1.getName());
	s1.takeDamage(s2.getMeleeDamage());

	s2.meleeAttack(s1.getName());
	s1.takeDamage(s2.getMeleeDamage());

	s2.meleeAttack(s1.getName());
	s1.takeDamage(s2.getMeleeDamage());

	s2.meleeAttack(s1.getName());
	s1.takeDamage(s2.getMeleeDamage());

	return 0;
}