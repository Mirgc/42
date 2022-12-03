/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   easyfind.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/02 14:27:30 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_H
# define EASYFIND_H

class notFound: public std::exception {
    public:
         const char * what() const throw(){
	         return ("ERROR: not found");
         };
};

template <typename T>
void easyfind( T &a, int &b ) {
	std::cout << "Searching " << b << "..." << std::endl;
	typename T::iterator it;
	it = std::find(a.begin(), a.end(), b);
	if (it == a.end())
		throw notFound();
}

#endif
