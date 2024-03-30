/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/30 10:09:08 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style.h"
#include "easyfind.tpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>

void	help_msg(std::string msg) {
	std::cout << GREEN << TITLE << " 💬 " << msg << " " << END_STYLE << std::endl;
}

void	warning_msg(std::string msg) {
	std::cout << " ⚠️  " << GREEN << BOLD << UNDERLINE << msg << END_STYLE << std::endl;
}

void	print(int &i) {
	std::cout << i << " ";
}

int	main(void) {
	int	ints[] = {4, 7, 3, 8, 7, 1, 6, 3, 5, 8, 9};
	int	*finded_int;
	
	help_msg("Initializing containers with integers 4, 7, 3, 8, 7, 1, 6, 3, 5, 8, 9");
	std::vector<int> vec(ints, ints + sizeof(ints) / sizeof(int));
	std::deque<int> deq(ints, ints + sizeof(ints) / sizeof(int));
	std::list<int> lis(ints, ints + sizeof(ints) / sizeof(int));
	std::for_each(vec.begin(), vec.end(), print);
	std::cout << std::endl;
	
	std::cout << std::endl;
	help_msg("Searching 7 in vector container...");
	try {
		finded_int = ::easyfind(vec, 7);
		warning_msg("Adding 10 to the found integer and printing the container ints");
		*finded_int += 10;
		std::for_each(vec.begin(), vec.end(), print);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Container does not contains this integer" << std::endl;
	}
	help_msg("Searching 2 in deque container...");
	try {
		finded_int = ::easyfind(deq, 2);
		warning_msg("Adding 10 to the found integer and printing the container ints");
		*finded_int += 10;
		std::for_each(vec.begin(), vec.end(), print);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Container does not contains this integer" << std::endl;
	}
	help_msg("Searching 9 in list container...");
	try {
		finded_int = ::easyfind(lis, 9);
		warning_msg("Adding 10 to the found integer and printing the container ints");
		*finded_int += 10;
		std::for_each(lis.begin(), lis.end(), print);
		std::cout << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << "Container does not contains this integer" << std::endl;
	}
	return (0);
}
