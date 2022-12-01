/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/01 14:29:27 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
# define ITER_H
# include <cstring>
# include <iostream>
# include <iomanip>

template <typename T>
void iter( T *arr, int size, void function(T &)) {
	for (int i = 0; i < size; i++)
		function(arr[i]);
}

template <typename T>
void Print(T &i) {
	std::cout << i << std::endl;
}

#endif
