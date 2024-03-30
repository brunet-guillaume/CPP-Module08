/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 07:30:32 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/30 09:49:33 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
	private:

	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack();
		MutantStack(const MutantStack &cpy);
		~MutantStack();

		MutantStack	&operator=(const MutantStack &rhs);

		iterator	begin();
		iterator	end();
};

#endif
