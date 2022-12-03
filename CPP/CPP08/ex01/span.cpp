/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:44:40 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/02 19:46:15 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <algorithm>
#include "span.hpp"

Span::Span(unsigned int n): _size(n){
}

Span::Span(const Span &copy){
	*this = copy;
}

Span::~Span(void){
}

Span &Span::operator=(const Span &obj){
	if (this != &obj){
		this->_size = obj._size;
		this->_vec = obj._vec;
	}		
	return *this;
}

void Span::addNumber(unsigned int n){
	if (this->_vec.size() == this->_size)
		throw noSizeException();
	this->_vec.push_back(n);
}

int Span::shortestSpan() const{
	if (this->_vec.size() <= 1)
		throw emptyVectorException();

	std::vector<unsigned int> _tmpVec = this->_vec;
	unsigned int res = std::numeric_limits<unsigned int>::max(); //the maximum value for type unsigned int

	std::sort(_tmpVec.begin(), _tmpVec.end());
	for (size_t i = 0; i + 1 < _vec.size(); i++)
		res = std::min(res, (_tmpVec[i + 1] - _tmpVec[i]));
	return (res);
}

int Span::longestSpan() const{
	if (this->_vec.size() <= 1)
		throw emptyVectorException();

	std::vector<unsigned int>::const_iterator min;
	std::vector<unsigned int>::const_iterator max;
	min = std::min_element(_vec.begin(), _vec.end()); //Finds the smallest element in the range (first, last).
	max = std::max_element(_vec.begin(), _vec.end());
	return *max - *min;
}

void	Span::Print(){
	std::cout << "Vector Size: " << _size << " { ";
	for (unsigned int i = 0; i < _size; i++)
			std::cout << _vec[i] << " ";
	std::cout << "}" << std::endl;
}

const char *Span::noSizeException::what() const throw(){
	return "ERROR: Haven't got size in vector!";
}

const char *Span::emptyVectorException::what() const throw(){
	return "ERROR: Empty vector or only one file!";
}
