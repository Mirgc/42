/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:12:36 by migarcia          #+#    #+#             */
/*   Updated: 2022/05/31 19:10:51 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

Karen::Karen ()
{
}

Karen::~Karen()
{
}

void Karen::complain(std::string level)
{
	const std::string level_ref[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void (Karen::*function[4])(void) = { &Karen::debug, 
		&Karen::info, &Karen::warning, &Karen::error };

	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(level_ref[i]))
			(this->*function[i])();
	}
}

void Karen::debug()
{
	std::cout << "[DEBUG] ";
	std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void Karen::info()
{
	std::cout << "[INFO] ";
	std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void Karen::warning()
{
	std::cout << "[WARNING] ";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void Karen::error()
{
	std::cout << "[ERROR] ";
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

