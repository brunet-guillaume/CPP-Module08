/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrunet <guill@umebrunet.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 04:48:24 by gbrunet           #+#    #+#             */
/*   Updated: 2024/03/30 10:07:09 by gbrunet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <algorithm>

typedef std::vector<int>::iterator InputIt;

Span::Span() {}

Span::Span(const unsigned int N): _maxItem(N), _count(0) {}

Span::Span(const Span &cpy):
	_maxItem(cpy._maxItem), _count(cpy._count), _vector(cpy._vector) {
	
}

Span::~Span() {}

Span	&Span::operator=(const Span &rhs) {
	if (this == &rhs)
		return (*this);
	this->_maxItem = rhs._maxItem;
	this->_count = rhs._count;
	this->_vector = rhs._vector;
	return (*this);
}

void	Span::addNumber(const int nb) {
	if (this->_count >= this->_maxItem)
		throw Span::FullSpanException();
	this->_count++;
	this->_vector.push_back(nb);
}

unsigned int	Span::getCount() const {
	return (this->_count);
}

int	Span::getItem(int i) const {
	return (this->_vector[i]);
}

unsigned int	Span::shortestSpan() {
	unsigned int	shortest;

	if (this->_count == 0)
		throw Span::EmptySpanException();
	if (this->_count == 1)
		throw Span::OnlyOneException();
	std::vector<int> sorted(this->_vector);
	std::sort(sorted.begin(), sorted.end());
	shortest = *(sorted.begin() + 1) - sorted.front();
	if (shortest == 0)
		return (0);
	for (InputIt it = (sorted.begin() + 1); it != sorted.end() - 1; it++) {
		if(static_cast<unsigned long>(*(it + 1) - *it) < shortest) {
			shortest = *(it + 1) - *it;
			if (shortest == 0)
				return (0);
		}
	}
	return (shortest);
}

unsigned int	Span::longestSpan() {
	unsigned int	longest;

	if (this->_count == 0)
		throw Span::EmptySpanException();
	if (this->_count == 1)
		throw Span::OnlyOneException();
	longest = *std::max_element(this->_vector.begin(), (this->_vector.end()))
		- *std::min_element(this->_vector.begin(), (this->_vector.end()));
	return (longest);
}

void	Span::addRange(InputIt start, InputIt end) {
	unsigned int dist = std::distance(start, end);

	if (dist + this->_count > this->_maxItem)
		throw Span::RangeTooLargeException();
	this->_vector.insert(this->_vector.end(), start, end);
	this->_count += dist;
}

const char* Span::EmptySpanException::what() const throw() {
	return ("Span is empty");
}

const char* Span::OnlyOneException::what() const throw() {
	return ("Span has only one item");
}

const char *Span::FullSpanException::what() const throw() {
	return ("Span is full");
}

const char *Span::RangeTooLargeException::what() const throw() {
	return ("Range is too large: can't be added to span");
}

std::ostream	&operator<<(std::ostream &o, const Span &span) {
	for (unsigned int i = 0; i < span.getCount(); i++)
		o << span.getItem(i) << " ";
	return (o);
}
