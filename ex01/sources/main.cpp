/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/04/01 09:48:51 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style.h"
#include <iostream>
#include "Span.hpp"
#include <cstdlib>
#include <unistd.h>

void	help_msg(std::string msg) {
	std::cout << GREEN << TITLE << " 💬 " << msg << " " << END_STYLE << std::endl;
}

void	warning_msg(std::string msg) {
	std::cout << " ⚠️  " << GREEN << BOLD << UNDERLINE << msg << END_STYLE << std::endl;
}

void	rdm_vector(std::vector<int> &v, long min, long max) {
	if (max < min)
		std::swap(min, max);
	for (unsigned int i = 0; i < v.size(); i++)
		v[i] = std::rand() % (max - min + 1) + min;
}

int	main(void) {
	std::vector<int>	rdm1(100);
	std::vector<int>	rdm2(10000);

	std::srand(time(NULL) * getpid());
	rdm_vector(rdm1, 0, 500);
	rdm_vector(rdm2, -200000000, 200000000);

	help_msg("Initializing a Span with size 15");
	Span	span1(15);
	
	std::cout << std::endl;
	help_msg("Trying to find the longest span");
	try {
		std::cout << span1.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	help_msg("Trying to find the shortest span");
	try {
		std::cout << span1.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	help_msg("Adding 5 to the Span");
	span1.addNumber(5);
	std::cout << span1 << std::endl;
	
	std::cout << std::endl;
	help_msg("Trying to find the longest span");
	try {
		std::cout << span1.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	help_msg("Trying to find the shortest span");
	try {
		std::cout << span1.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	help_msg("Adding 10 to the Span");
	span1.addNumber(10);
	std::cout << span1 << std::endl;
	
	std::cout << std::endl;
	help_msg("Trying to find the longest span");
	try {
		std::cout << span1.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	help_msg("Trying to find the shortest span");
	try {
		std::cout << span1.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	help_msg("Adding 6 to the Span");
	span1.addNumber(6);
	std::cout << span1 << std::endl;
	
	std::cout << std::endl;
	help_msg("Trying to find the longest span");
	try {
		std::cout << span1.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	help_msg("Trying to find the shortest span");
	try {
		std::cout << span1.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	help_msg("Trying to add a range of 15 ints to the Span");
	try {
		span1.addRange(rdm1.begin(), rdm1.begin() + 15);
		std::cout << span1 << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	help_msg("Trying to add a range of 10 ints to the Span");
	try {
		span1.addRange(rdm1.begin(), rdm1.begin() + 10);
		std::cout << span1 << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	help_msg("Tryinmg to add int 13 to the Span (5 times)");
	for (int i = 0; i < 5; i++) {
		try {
			span1.addNumber(13);
		} catch (std::exception &e) {
			std::cerr << RED << e.what() << END_STYLE << std::endl;
		}
	}
	std::cout << span1 << std::endl;

	std::cout << std::endl;
	help_msg("Initializing a Span with size 100000");
	Span	span2(10000);
	
	std::cout << std::endl;
	help_msg("Trying to add a range of 10000 ints to the Span");
	try {
		span2.addRange(rdm2.begin(), rdm2.begin() + 10000);
		std::cout << "Range added" << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	
	std::cout << std::endl;
	help_msg("Trying to find the longest span");
	try {
		std::cout << span2.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}
	help_msg("Trying to find the shortest span");
	try {
		std::cout << span2.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << END_STYLE << std::endl;
	}

	return (0);
}
