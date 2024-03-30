/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 08:57:52 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/30 09:52:17 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack() {};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &cpy): std::stack<T>(cpy) {}

template<typename T>
MutantStack<T>::~MutantStack() {};

template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack &rhs) {
	std::stack<T>::operator=(rhs);
	return (*this);
};

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin() {
	return (this->c.begin());
};

template<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end() {
	return (this->c.end());
};

#endif
