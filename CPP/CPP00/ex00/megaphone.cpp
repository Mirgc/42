/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 18:51:51 by migarcia          #+#    #+#             */
/*   Updated: 2022/01/20 18:51:53 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    int i;
    int j;

    if (argc < 2)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        i = 0;
        while (argc > ++i)
        {
            j = -1;
            while(argv[i][++j] != '\0')
                std::cout << (char)std::toupper(argv[i][j]);
            if (argc == i - 1)
                std::cout << " ";
        }
    }
    std::cout << std::endl;
    return (0);
}
