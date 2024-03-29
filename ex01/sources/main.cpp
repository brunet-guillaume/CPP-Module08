/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:20:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/29 17:56:29 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "style.h"
#include <iostream>

void	help_msg(std::string msg) {
	std::cout << GREEN << TITLE << " 💬 " << msg << " " << END_STYLE << std::endl;
}

void	warning_msg(std::string msg) {
	std::cout << " ⚠️  " << GREEN << BOLD << UNDERLINE << msg << END_STYLE << std::endl;
}

int	main(void) {
	help_msg("Initializing containers with integers 4, 7, 3, 8, 7, 1, 6, 3, 5, 8, 9");

	return (0);
}
