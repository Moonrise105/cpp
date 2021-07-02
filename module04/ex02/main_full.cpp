/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppipes <ppipes@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:12:24 by ppipes            #+#    #+#             */
/*   Updated: 2021/03/12 21:41:45 by ppipes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "Squad.hpp"

int main() 
{
	std::cout << "CONSTRUCTORS: " << std::endl;
	ISpaceMarine* bob = new TacticalMarine;
	ISpaceMarine* jim = new AssaultTerminator;
	ISpaceMarine* jack = new TacticalMarine;
	ISpaceMarine* jonas = new AssaultTerminator;
	ISquad* vlc = new Squad;

	vlc->push(bob);
	vlc->push(jim);
	vlc->push(jack);
	vlc->push(jonas);

	

	std::cout << "UNITS IN THE SQUAD: " << std::endl;
	for(int i = 0; i < vlc->getCount(); i++) {
		std::cout << "UNIT #" << i+1 << std::endl;
		ISpaceMarine* cur = vlc->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
	}

	std::cout << "DESTRUCTORS: " << std::endl;
	delete vlc;

	std::cout << std::endl << "TESTING DEEP COPY: " << std::endl;
	std::cout << std::endl << "DEFAULT CONSTRUCTOR: " << std::endl;
	Squad* sq1 = new Squad;
	ISpaceMarine* a = new TacticalMarine;
	ISpaceMarine* b = new AssaultTerminator;

	sq1->push(a);
	sq1->push(b);

	std::cout << std::endl << "COPY CONSTRUCTOR: " << std::endl;
	Squad sq2(*sq1);

	std::cout << std::endl << "SQ1: " << std::endl;
	for(int i = 0; i < sq1->getCount(); i++) {
		std::cout << "UNIT #" << i+1 << std::endl;
		ISpaceMarine* cur = sq1->getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		std::cout << cur << std::endl;
	}
	
	std::cout << std::endl << "SQ2: " << std::endl;
	for(int i = 0; i < sq2.getCount(); i++) {
		std::cout << "UNIT #" << i+1 << std::endl;
		ISpaceMarine* cur = sq2.getUnit(i);
		cur->battleCry();
		cur->rangedAttack();
		cur->meleeAttack();
		std::cout << cur << std::endl;
	}
	std::cout << "DESTRUCTORS: " << std::endl;
	delete sq1;
	return 0;
}