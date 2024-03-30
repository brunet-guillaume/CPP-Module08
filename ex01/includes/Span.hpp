/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <gbrunet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 17:58:01 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/30 06:18:52 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iterator>
# include <vector>

class Span {
	private:
		typedef std::vector<int>::iterator InputIt;

		unsigned int		_maxItem;
		unsigned int		_count;
		std::vector<int>	_vector;
	
		Span();

	public:
		Span(const unsigned int N);
		Span(const Span &cpy);
		~Span();

		Span	&operator=(const Span &rhs);

		void			addNumber(const int nb);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();
		void			addRange(InputIt start, InputIt end);
		unsigned int	getCount() const;
		int				getItem(int i) const;
		
		class EmptySpanException : public std::exception {
			const char*	what() const throw();
		};
		class OnlyOneException : public std::exception {
			const char*	what() const throw();
		};
		class FullSpanException : public std::exception {
			const char*	what() const throw();
		};
		class RangeTooLargeException : public std::exception {
			const char*	what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &o, const Span &span);

#endif
