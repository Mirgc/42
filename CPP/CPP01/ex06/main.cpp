/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:54:20 by migarcia          #+#    #+#             */
/*   Updated: 2022/05/31 20:33:22 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		Karen	karen;

		std::string level = argv[1];
		karen.complain(level);
	}
	else
		std::cout << "Error: ./karenFilter DEBUG/INFO/WARNING/ERROR" << std::endl;
	return (0);
}
