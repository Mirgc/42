/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/03 01:20:33 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_H
# define MUTANTSTACK_H
# include <iostream>
# include <stack>

template<class T>
class MutantStack: public std::stack<T>
{
	public:
    	MutantStack(){};
	    MutantStack(const MutantStack &copy){
			*this = copy;
		}
		~MutantStack(){};

		MutantStack	&operator=(const MutantStack &obj) {
			if (*this != obj)
				this->std::stack<T>::operator=(obj);
			return (*this);
		}

		//https://refactoring.guru/es/design-patterns/iterator/cpp/example
		typedef typename MutantStack<T>::container_type::iterator iterator;
		
		iterator begin(){
			return this->c.begin();
		}
		iterator end(){
			return this->c.end();
		}
};

#endif
