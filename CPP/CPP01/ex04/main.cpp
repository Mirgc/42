/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 14:35:34 by migarcia          #+#    #+#             */
/*   Updated: 2022/05/19 11:21:12 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string get_newName(std::string str)
{
    for (int i = 0; str[i] != '\0'; i++)
        str[i] = toupper(str[i]);
    str.append(".replace");
    return str;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./sed filename s1 s2" << std::endl;
		return (1);
	}

	std::string filename = argv[1];
	std::ifstream filein(argv[1]);
	if (!filein.is_open())
	{
		std::cout << "Error. Can't open file." << std::endl;
		return (1);
	}
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.length() == 0 || s2.length() == 0)
	{
		std::cout << "Error. Empty arguments." << std::endl;
		return (1);
	}

	std::string line;		
	std::string str;
	std::string newName = get_newName(filename);
	std::ofstream newFile(newName.c_str());

	while(std::getline(filein, line))
	{
		size_t lastpos(0);
		size_t pos = line.find(s1);
		while ( pos != std::string::npos)
	        {
			str.append(line.substr(lastpos, pos - lastpos));
			str.append(s2);
			pos += s1.size();
			lastpos = pos;
			pos = line.find(s1, pos);
	        }
		str.append(line.substr(lastpos, pos - lastpos));
		str.append("\n");
	}
	newFile << str;

	return (0);
}
