/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:46:02 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/21 10:36:57 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("Robotomy request", 72, 45), _target("none"){
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target): Form("Robotomy request", 72, 45), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): Form("Robotomy request", 72, 45), _target(copy._target){
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj){
	(void)obj;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void){
}

std::string RobotomyRequestForm::getTarget() const
{
    return this->_target;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const{
	srand (time(NULL)); // Inicializo en random para que cada vez que se ejecute, dependiendo de la hora, de un numero diferente, sin esto hay que recompilar para que cambie el numero.
	int random;

	checkExecute(executor);

	std::cout << "   brrrrrap brruuuuu zzziiiiii " << std::endl;
	random = rand() % 100 + 1;; // Numero random del 1 al 100
	//std::cout << random << std::endl;
	if (random % 2)
		std::cout << "   " << _target << " has been robotomized." << std::endl;
	else
		std::cout << "   " << _target << " hasn't been robotomized." << std::endl;
	
}
