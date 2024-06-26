/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/12/01 11:05:56 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"

int main(int argc, char **argv)
{
	if (argc !=2){
		std::cerr << "USAGE: " << argv[0] << " value" << std::endl;
		return (1);
	}
	try{
		Cast	conv(argv[1]);
		if (conv.getType() != PSEUDO)
			conv.print();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		std::cout << "ERROR: Can't cast because of the reason above. Check your arguments!" << std::endl;
	}
	return (0);
}
