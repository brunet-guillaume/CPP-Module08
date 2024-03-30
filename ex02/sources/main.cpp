/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/30 10:04:12 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "MutantStack.tpp"

void	help_msg(std::string msg) {
	std::cout << GREEN << TITLE << " 💬 " << msg << " " << END_STYLE << std::endl;
}

void	warning_msg(std::string msg) {
	std::cout << " ⚠️  " << GREEN << BOLD << UNDERLINE << msg << END_STYLE << std::endl;
}

void	info_msg(std::string msg) {
	std::cout << CYAN << BOLD << " ➡  " << msg << END_STYLE << std::endl;
}

int	rdm(long min, long max) {
	if (max < min)
		std::swap(min, max);
	return (std::rand() % (max - min + 1) + min);
}


int	main(void) {
	MutantStack<int>			mutantStack1;
	MutantStack<int>::iterator	begin;
	MutantStack<int>::iterator	end;

	std::srand(time(NULL) * getpid());
	help_msg("Verifying MutantStack stack functions");
	info_msg("empty(): true");
	if (mutantStack1.empty())
		std::cout << "    true" << std::endl;
	else
		std::cout << "    false" << std::endl;
	info_msg("size(): 0");
	std::cout << "    " << mutantStack1.size() << std::endl;
	info_msg("push(5) and top(): 5");
	mutantStack1.push(5);
	std::cout << "    " << mutantStack1.top() << std::endl;
	info_msg("empty(): false");
	if (mutantStack1.empty())
		std::cout << "    true" << std::endl;
	else
		std::cout << "    false" << std::endl;
	info_msg("size(): 1");
	std::cout << "    " << mutantStack1.size() << std::endl;
	info_msg("pop() and size(): 0");
	mutantStack1.pop();
	std::cout << "    " << mutantStack1.size() << std::endl;
	info_msg("push(1), push(3) and top(): 3");
	mutantStack1.push(1);
	mutantStack1.push(3);
	std::cout << "    " << mutantStack1.top() << std::endl;
	info_msg("Copying with constructor and size(): 2 / 2");
	MutantStack<int>	mutantStack2(mutantStack1);
	std::cout << "    " << mutantStack1.size() << std::endl;
	std::cout << "    " << mutantStack2.size() << std::endl;
	info_msg("Copying with operator = and size(): 2 / 2 / 2");
	MutantStack<int>	mutantStack3;
	mutantStack3 = mutantStack2;
	std::cout << "    " << mutantStack1.size() << std::endl;
	std::cout << "    " << mutantStack2.size() << std::endl;
	std::cout << "    " << mutantStack3.size() << std::endl;
	info_msg("first MutantStack pop() and size(): 1 / 2 / 2");
	mutantStack1.pop();
	std::cout << "    " << mutantStack1.size() << std::endl;
	std::cout << "    " << mutantStack2.size() << std::endl;
	std::cout << "    " << mutantStack3.size() << std::endl;
	info_msg("first end second MutantStack pop() and size(): 0 / 1 / 2");
	mutantStack1.pop();
	mutantStack2.pop();
	std::cout << "    " << mutantStack1.size() << std::endl;
	std::cout << "    " << mutantStack2.size() << std::endl;
	std::cout << "    " << mutantStack3.size() << std::endl;

	std::cout << std::endl;
	help_msg("Verifying MutantStack iterators");
	info_msg("Printing first stack");
	begin = mutantStack1.begin();
	end = mutantStack1.end();
	std::cout << "    ";
	for (; begin != end; begin++)
		std::cout << *begin << " ";
	std::cout << std::endl;
	info_msg("Printing second stack");
	begin = mutantStack2.begin();
	end = mutantStack2.end();
	std::cout << "    ";
	for (; begin != end; begin++)
		std::cout << *begin << " ";
	std::cout << std::endl;
	info_msg("Printing third stack");
	begin = mutantStack3.begin();
	end = mutantStack3.end();
	std::cout << "    ";
	for (; begin != end; begin++)
		std::cout << *begin << " ";
	std::cout << std::endl;

	std::cout << std::endl;
	help_msg("Adding 15 randoms ints to the first MutantStack and printing it");
	for (int i = 0; i < 15; i++)
		mutantStack1.push(rdm(-100, 100));
	begin = mutantStack1.begin();
	end = mutantStack1.end();
	std::cout << "    ";
	for (; begin != end; begin++)
		std::cout << *begin << " ";
	std::cout << std::endl;

	return (0);
}
