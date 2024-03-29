/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/29 13:39:44 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style.h"
#include "easyfind.tpp.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <stack>

void	help_msg(std::string msg) {
	std::cout << GREEN << TITLE << " 💬 " << msg << " " << END_STYLE << std::endl;
}

void	warning_msg(std::string msg) {
	std::cout << " ⚠️  " << GREEN << BOLD << UNDERLINE << msg << END_STYLE << std::endl;
}

int	main(void) {
	int	ints[] = {4, 7, 3, 8, 5, 1, 6, 3, 5, 8, 9};
	
	help_msg("Initializing containers with integers 4, 7, 3, 8, 5, 1, 6, 3, 5, 8, 9");
	std::vector<int> vec(ints, ints + sizeof(ints) / sizeof(int));
	std::deque<int> deq(ints, ints + sizeof(ints) / sizeof(int));
	std::list<int> lis(ints, ints + sizeof(ints) / sizeof(int));
	
	std::cout << std::endl;
	help_msg("Searching 7 in vector container...");
	::easyfind(vec, 7);
	help_msg("Searching 2 in deque container...");
	::easyfind(deq, 2);
	help_msg("Searching 9 in list container...");
	::easyfind(lis, 9);
	return (0);
}
