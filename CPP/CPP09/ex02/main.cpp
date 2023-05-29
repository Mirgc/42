/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:08:37 by migarcia          #+#    #+#             */
/*   Updated: 2023/05/29 18:17:28 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc < 1)
	{
		std::cout << "usage : ./PmergeMe 3 5 9 7 4" << std::endl;
		return (1);
	}
	PmergeMe	merge;
	merge.run(argv);
	return 0;
}
