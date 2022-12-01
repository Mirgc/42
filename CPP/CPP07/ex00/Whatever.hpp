/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   Whatever.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:40:16 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/01 14:03:25 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_H
# define WHATEVER_H

template <typename T>
void swap( T &a, T &b ) {
	T c(a);
	a = b;
	b = c;
}

template <typename T>
T min(T &a, T &b){
    return (a < b ? a : b);
}

template <typename T>
T max(T &a, T &b){
	return (a > b ? a : b);
}

#endif
