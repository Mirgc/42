/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/29 14:28:55 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cast.hpp"

int main(int argc, char **argv)
{
	if (argc !=2)
	{
		std::cerr << "USAGE: " << argv[0] << " value" << std::endl;
		return (1);
	}
	Cast	conv(argv[1]);
	if (conv.getType() != INVALID)
		conv.print();	
	return (0);
}
