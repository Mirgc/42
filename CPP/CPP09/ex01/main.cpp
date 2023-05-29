/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/02 14:24:47 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cout << "usage : ./RPN \"x y *\"" << std::endl;
		return (1);
	}
	RPN	rpn;
	rpn.run (argv[1]);
	return 0;
}
