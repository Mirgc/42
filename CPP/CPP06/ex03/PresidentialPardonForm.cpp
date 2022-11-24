/* ************************************************************************** */
/*                                                                            */
/*                                                        :::.     ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarcia <migarcia@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:46:02 by migarcia          #+#    #+#             */
/*   Updated: 2022/11/21 11:27:53 by migarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("Presidential pardon", 25, 5), _target("none"){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target): Form("Presidential pardon", 25, 5), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): Form("Presidential pardon", 25, 5), _target(copy._target){
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj){
	(void)obj;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void){
}

std::string PresidentialPardonForm::getTarget() const
{
    return this->_target;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const{
	checkExecute(executor);

	std::cout << "   " << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
	
}
