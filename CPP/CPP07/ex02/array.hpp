/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/02 10:45:58 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H
# include <iostream>
# include <iomanip>

template<class T>
class Array
{
	private:
	    T *_arr;
		unsigned int _size;
	public:
    	Array(): _arr(NULL), _size(0){}
	    Array(unsigned int n): _arr(new T[n]), _size(n){}
	    Array(const Array &copy): _arr(new T[copy._size]), _size(copy._size) {
			for (unsigned int i = 0; i < _size; i++)
				this->_arr[i] = T(copy._arr[i]);
		}
		~Array() {delete [] _arr;}

		Array	&operator=(const Array &obj) {
			if (this != &obj){
				this->_size = obj._size;
				if (this->_size > 0)
					delete [] this->_arr;
				this->_arr = new T[obj._size];
				for (unsigned int i = 0; i < obj._size; i++)
					this->_arr[i] = T(obj._arr[i]);
			}
			return (*this);
		}

		T		&operator[](const int pos){
			if (static_cast<unsigned int>(pos) >= this->_size)
				throw IndexOutOfRangeException();
			return (this->_arr[pos]);
		}

		unsigned int	size(void) const {
			return (this->_size);
		}

		class IndexOutOfRangeException: public std::exception {
			public:
				virtual const char	* what() const throw(){
					return ("ERROR: Index out of range!");
				}
		};
};

#endif
