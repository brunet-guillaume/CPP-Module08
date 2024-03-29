/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:01:00 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/29 16:44:25 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"
# include <iostream>
# include <algorithm>

template<typename T>
int	*easyfind(T &container, int needle) {
	typename T::iterator it = container.begin();

	it = std::find(container.begin(), container.end(), needle);
	if (it != container.end())
		return (&(*it));
	else throw std::exception();
}

#endif
