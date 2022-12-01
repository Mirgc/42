/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/01 14:29:21 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main( void ) {
	// INT
	int size = 10;
	int a[size];

	for (int i = 0; i < size; i++)
		a[i] = i + 1;
	
	::iter(a, 10, Print);

	//STRING
	char str[10];

	for (int i = 0; i < size; i++)
		str[i] = static_cast<char>(i);
	
	::iter(str, 10, Print);
	
	return 0;
}
