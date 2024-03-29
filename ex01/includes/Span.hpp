/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:58:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/29 18:19:04 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iterator>
# include <list>

class Span {
	private:
		const unsigned int	_maxItem;
		unsigned int		_count;
		std::list<int>		_list;
	
		Span();

	public:
		Span(const unsigned int N);
		Span(const Span &cpy);
		~Span();

		Span	&operator=(const Span &rhs);

		void	addNumber(const int nb);
		int		shortestSpan();
		int		longestSpan();
		void	addRange(/*TODO*/);
		
		class EmptySpanException : public std::exception {
			const char*	what() const throw();
		};
		class OnlyOneException : public std::exception {
			const char*	what() const throw();
		};
};

#endif
