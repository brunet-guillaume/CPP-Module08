/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:01:00 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/29 13:13:03 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"
# include <iostream>
# include <algorithm>

template<typename T>
void	easyfind(T container, int needle) {
	if (std::find(container.begin(), container.end(), needle) != container.end())
		std::cout << "Integer found" << std::endl;
	else
		std::cout << "Integer not found !" << std::endl;
}

#endif
